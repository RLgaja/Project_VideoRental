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
	static const int SPECIAL_EVENT_MOVIE = 3; // add new genre

	Movie(const std::string& title, int priceCode = REGULAR);

	int getPriceCode() const;
	void setPriceCode(int arg);
	std::string getTitle() const;
	// add function to get genre name from moviePriceCode 
	std::string getGenre(int arg) const;

private:
	std::string movieTitle;
	// add string array to define genre name
	std::string movieGenre[4] = { "REGULAR", "NEW_RELEASE", "CHILDRENS", "SPECIAL_EVENT_MOVIE" };

	int moviePriceCode;
};

inline Movie::Movie(const std::string& title, int priceCode) :
	movieTitle(title),
	moviePriceCode(priceCode)
{}

inline int Movie::getPriceCode() const { return moviePriceCode; }

inline void Movie::setPriceCode(int arg) { moviePriceCode = arg; }

inline std::string Movie::getTitle() const { return movieTitle; }

inline std::string Movie::getGenre(int arg) const { return movieGenre[arg]; }

#endif // MOVIE_H
