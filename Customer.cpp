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


	// Loop over customer's rentals
	for (; iter != iter_end; ++iter) {

		double thisAmount = 0.;
		int frequentRenterPoints = 0;
		Rental each = *iter;

		thisAmount = getRentalFee(each);
		frequentRenterPoints = getRenterPoints(each);

		// Save information of customer rental
		customerLog.totalRenterPoints += frequentRenterPoints;
		customerLog.totalRentalFee += thisAmount;
		customerLog.titleName.push_back(each.getMovie().getTitle());
		// add customerLog.genreName to save genreName for each movie
		customerLog.genreName.push_back(each.getMovie().getGenre(each.getMovie().getPriceCode()));
		customerLog.rentalAmount.push_back(thisAmount);
		customerLog.rentalDays.push_back(each.getDaysRented());
	}

	std::string strResult = printStatement(customerLog);

	return strResult;
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

	// add calculation formula about rental fee for a new genre "SPECIAL_EVENT_MOVIE"
	case Movie::SPECIAL_EVENT_MOVIE:
		thisAmount += 1.0;
		if (each.getDaysRented() > 2)
			thisAmount += (each.getDaysRented() - 2) * 2.0;
		break;
	}
	return thisAmount;

}

//add funtion to determine bonus points for each rental
int Customer::getRenterPoints(Rental each)
{
	int resultPoints = 0;

	// Add frequent renter points
	// except for new genre "SPECIAL_EVENT_MOVIE"
	if (each.getMovie().getPriceCode() != Movie::SPECIAL_EVENT_MOVIE)
		resultPoints++;

	// Add bonus for a two day new release rental
	if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE)
		&& each.getDaysRented() > 1) resultPoints++;

	return resultPoints;
}

//add funtion to print a rental receipt for the customer
std::string Customer::printStatement(RentalLog customerLog)
{
	// result will be returned by statement()
	std::ostringstream result;
	result << "Rental Record for " << getCustomerName() << "\n";

	// Show figures for this rental
	for (int i = 0; i < customerLog.titleName.size(); i++) {
		result << "\t" << "제목: " << customerLog.titleName[i] << "\t"
			<< "대여료: " << customerLog.rentalAmount[i] << std::endl;
	}

	// Add footer lines
	result << "Amount owed is " << customerLog.totalRentalFee << "\n";
	result << "You earned " << customerLog.totalRenterPoints
		<< " frequent renter points" << std::endl;

	// Add new figures for this rental(Genre, MovieTitle, Rental Period(day), Rental fee)
	for (int i = 0; i < customerLog.titleName.size(); i++) {
		result << "\t" << "장르: " << customerLog.genreName[i] << "\t" << "제목: " << customerLog.titleName[i]
			<< "\t" << "대여일: " << customerLog.rentalDays[i] << "\t" << "대여료: " << customerLog.rentalAmount[i] << std::endl;
	}


	return result.str();
}

