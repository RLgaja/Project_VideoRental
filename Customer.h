// Customer.hh
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

// The customer class represents the customer of the store

class Customer {
public:
	Customer();
	explicit Customer(const std::string& name);

	void addRental(const Rental& arg);
	std::string getCustomerName() const;

	// Generate a statement for the customer
	std::string statement();
	//add funtion to determine amounts for each rental
	double getRentalFee(Rental);

private:
	std::string customerName;
	std::vector< Rental > customerRentals;

};


inline Customer::Customer() {}

inline Customer::Customer(const std::string& name) :
	customerName(name) {}

inline void Customer::addRental(const Rental& arg) { customerRentals.push_back(arg); }

inline std::string Customer::getCustomerName() const { return customerName; }

#endif // CUSTOMER_HH
