// Customer.cc
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

std::string Customer::statement()
{
	double totalAmount = 0.;
	int totalRenterPoints = 0; // Total renter points earned by the customer

	std::vector< Rental >::iterator iter = customerRentals.begin();
	std::vector< Rental >::iterator iter_end = customerRentals.end();

	// result will be returned by statement()
	std::ostringstream result;
	result << "Rental Record for " << getCustomerName() << "\n";

	// Loop over customer's rentals
	for (; iter != iter_end; ++iter) {

		double thisAmount = 0.;
		int frequentRenterPoints = 0;
		Rental each = *iter;

		thisAmount = getRentalFee(each);
		frequentRenterPoints = getRenterPoints(each);

		// Show figures for this rental
		result << "\t" << each.getMovie().getTitle() << "\t"
			<< thisAmount << std::endl;
		totalAmount += thisAmount;
		totalRenterPoints += frequentRenterPoints;

	}

	// Add footer lines
	result << "Amount owed is " << totalAmount << "\n";
	result << "You earned " << totalRenterPoints
		<< " frequent renter points";

	return result.str();
}

//add funtion to determine amounts for each rental
double Customer::getRentalFee(Rental each)
{
	double thisAmount = 0.;

	// Determine amounts for each rental
	switch (each.getMovie().getPriceCode()) {
	case Movie::REGULAR:
		thisAmount += 2.;
		if (each.getDaysRented() > 2)
			thisAmount += (each.getDaysRented() - 2) * 1.5;
		break;

	case Movie::NEW_RELEASE:
		thisAmount += each.getDaysRented() * 3;
		break;

	case Movie::CHILDRENS:
		thisAmount += 1.5;
		if (each.getDaysRented() > 3)
			thisAmount += (each.getDaysRented() - 3) * 1.5;
		break;

	}
	return thisAmount;

}

//add funtion to determine bonus points for each rental
int Customer::getRenterPoints(Rental each)
{
	int resultPoints = 0;

	// Add frequent renter points
	resultPoints++;

	// Add bonus for a two day new release rental
	if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE)
		&& each.getDaysRented() > 1) resultPoints++;

	return resultPoints;
}

