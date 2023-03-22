// Movie.hh
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie {
public:
	// Change the position of variables based on their values.
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
	static const int CHILDRENS = 2;

	Movie(const std::string& title, int priceCode = REGULAR);

	int getPriceCode() const;
	void setPriceCode(int arg);
	std::string getTitle() const;

private:
	std::string movieTitle;
	int moviePriceCode;
};

inline Movie::Movie(const std::string& title, int priceCode) :
	movieTitle(title),
	moviePriceCode(priceCode)
{}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode(int arg) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }

#endif // MOVIE_H
