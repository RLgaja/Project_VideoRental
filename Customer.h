// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

// Define a structure to store information about a customer rental
struct RentalLog {
	std::vector< std::string > titleName; // Title name of the rented movie
	std::vector< double > rentalAmount; // Rental fee charged for the rented movie
	std::vector< int > rentalDays; // Number of days the rented movie
	double totalRentalFee = 0.; // Total Rental Fee
	int totalRenterPoints = 0; // Total Renter Points
};

// The customer class represents the customer of the store

class Customer {
public:
	Customer();
	explicit Customer(const std::string& name);

	void addRental(const Rental& arg);
	std::string getCustomerName() const;

	// Generate a statement for the customer
	std::string statement();
	// Determine amounts for each rental
	double getRentalFee(Rental);
	// Determine bonus points for each rental
	int getRenterPoints(Rental);
	// Prints a rental receipt for the customer
	std::string printStatement(RentalLog);



private:
	std::string customerName;
	std::vector< Rental > customerRentals;
	// Define an alias for RentalLog structure called customerlog
	RentalLog customerLog; 

};


inline Customer::Customer() {}

inline Customer::Customer(const std::string& name) :
	customerName(name) {}

inline void Customer::addRental(const Rental& arg) { customerRentals.push_back(arg); }

inline std::string Customer::getCustomerName() const { return customerName; }

#endif // CUSTOMER_HH
