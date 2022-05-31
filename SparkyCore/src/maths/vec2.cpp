#include "vec2.h"

namespace sparky::maths {

	vec2::vec2() { x = 0.0f; y = 0.0f; }

	vec2::vec2(const float& x, const float& y) {
		this->x = x;
		this->y= y;
	}

	void vec2::Log() const {
		std::cout << *this << std::endl;
	}


	vec2& vec2::add(const vec2& other) {
		x += other.x;
		y += other.y;
		return *this;
	}


	vec2& vec2::subtract(const vec2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}


	vec2& vec2::multiply(const vec2& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	vec2& vec2::divide(const vec2& other) {

		if (other.x == 0 || other.y == 0) {
			//Todo : Log error 
			return *this;
		}

		x /= other.x;
		y /= other.y;
		return *this;
	}

	//Operator Overloads
	std::ostream& operator<<(std::ostream& stream, const vec2& vector) {
		stream << "vec2 [" << vector.x << "," << vector.y << "]"; 
		return stream; 
	}

	vec2& operator+(vec2& a, const vec2& b) { return a.add(b); } 
	vec2& operator-(vec2& a, const vec2& b) { return a.subtract(b); }
	vec2& operator*(vec2& a, const vec2& b) { return a.multiply(b); }
	vec2& operator/(vec2& a, const vec2& b) { return a.divide(b); }

	vec2& vec2::operator+=(const vec2& b) { return this->add(b); }
	vec2& vec2::operator-=(const vec2& b) { return this->subtract(b); }
	vec2& vec2::operator*=(const vec2& b) { return this->multiply(b); }
	vec2& vec2::operator/=(const vec2& b) { return this->divide(b); }

	bool vec2::operator==(const vec2& b) { return this->x == b.x && this->y == b.y; }
	bool vec2::operator!=(const vec2& b) { return  !( *this == b ); }
	bool vec2::operator<(const vec2& b)	 { return this->x < b.x && this->y < b.y; }
	bool vec2::operator>(const vec2& b)  { return this->x > b.x&& this->y > b.y; }


}