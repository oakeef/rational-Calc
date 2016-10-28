#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
public:
	Rational(void);
	Rational(int numerator);
	Rational(int numerator, int denominator);
	
	Rational operator+(Rational b);
	Rational operator-(Rational b);
	Rational operator*(Rational b);
	Rational operator/(Rational b);
	bool operator==(Rational b);
	bool operator<(Rational b);
	bool operator>(Rational b);
	friend std::ostream& operator<<(std::ostream& output, Rational& r);
	friend std::istream& operator >> (std::istream& input, Rational& r);

private:
	int _numerator;
	int _denominator;
	void Normalize();

};

#endif 