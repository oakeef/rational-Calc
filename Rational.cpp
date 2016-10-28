#include "Rational.hpp"
#include <string>
#include <stdlib.h>

Rational::Rational(void) :Rational(0) {}

Rational::Rational(int numerator):Rational(numerator, 1) {}

Rational::Rational(int numerator, int denomintor) {
	_numerator = numerator;
	_denominator = denomintor;
	Normalize();
}

Rational Rational::operator+(Rational b) {
	int resultNumerator = (_numerator * b._denominator) + (b._numerator * _denominator);
	int resultDenominator = (_denominator * b._denominator);
	Rational result(resultNumerator, resultDenominator);

	return result;
}

Rational Rational::operator-(Rational b) {
	int resultNumerator = (_numerator * b._denominator) - (b._numerator * _denominator);
	int resultDenominator = (_denominator * b._denominator);
	Rational result(resultNumerator, resultDenominator);

	return result;
}

Rational Rational::operator*(Rational b) {
	int resultNumerator = (_numerator * b._numerator);
	int resultDenominator = (_denominator * b._denominator);
	Rational result(resultNumerator, resultDenominator);

	return result;
}

Rational Rational::operator/(Rational b) {
	int resultNumerator = (_numerator * b._denominator);
	int resultDenominator = (_denominator * b._numerator);
	Rational result(resultNumerator, resultDenominator);

	return result;
}

bool Rational::operator==(Rational b) {
	if (_numerator == b._numerator && _denominator == b._denominator) {
		return true;
	}//end if
	return false;

}

bool Rational::operator<(Rational b) {
	if (_denominator != b._denominator) {
		int _newNumerator = (_numerator * b._denominator);
		int b_newNumerator = (b._numerator * _denominator);
		if (_newNumerator < b_newNumerator) {
			return true;
		}//end if
	}else if (_denominator == b._denominator) {
		if (_numerator < b._numerator) {
			return true;
		}//end if
	}//end else if
	return false;
		
}

bool Rational::operator>(Rational b) {
	if (_denominator != b._denominator) {
		int _newNumerator = (_numerator * b._denominator);
		int b_newNumerator = (b._numerator * _denominator);
		if (_newNumerator > b_newNumerator) {
			return true;
		}//end if
	}
	else if (_denominator == b._denominator) {
		if (_numerator > b._numerator) {
			return true;
		}//end if
	}//end else if
	return false;

}

void Rational::Normalize() {
	if (_denominator == 0) {
		throw std::exception("Denominator cannot be 0");
	}
	if (_denominator < 0) {
		_numerator *= -1;
		_denominator *= -1;
	}//end if
	for (int i = _denominator; i > 0; i--) {
		if (abs(_numerator) % i == 0 && abs(_denominator) % i == 0) {
			_numerator /= i;
			_denominator /= i;
			break;
		}//end if
	}//end for
}

std::ostream& operator<<(std::ostream& output, Rational& r) {
	output << r._numerator;
	output << "/";
	output << r._denominator;
	return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
	std::string read;
	int numerator;
	int denominator = 1;
	std::size_t sz;
	std::size_t sz2 = 0;

	input >> read;

	numerator = std::stoi(read, &sz);
	if (read.substr(sz) != "") {
		if (read[sz] != '/') {
			throw std::exception("Invlaid format");
		}//end if
		sz++;
		denominator = stoi(read.substr(sz), &sz2);
		if (read.substr(sz+sz2) != "") {
			throw std::exception("Invalid format");
		}//end if
	}//end if

	r._numerator = numerator;
	r._denominator = denominator;
	r.Normalize();
	return input;
}