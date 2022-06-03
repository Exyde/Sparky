#include "vec4.h"

namespace sparky::maths {

	//TODO : Recheck this class

	vec4::vec4() { x = 0.0f; y = 0.0f; z = 0.0f; w = 0.0f; }

	vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
		this->x = x;
		this->y= y;
		this->z= z;
		this->w = w;
	}

	void vec4::Log() const {
		std::cout << *this << std::endl;
	}

	//vec4::Add
	vec4& vec4::add(const vec4& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	vec4& vec4::add(const float& other) { return this->add(vec4(other, other, other, other)); }
	vec4& vec4::add(const float& x, const float& y, const float& z, const float& w) { return this->add(vec4(x, y, z, w)); }

	//vec4::Substract
	vec4& vec4::subtract(const vec4& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	vec4& vec4::subtract(const float& other) { return this->subtract(vec4(other, other, other, other)); }
	vec4& vec4::subtract(const float& x, const float& y, const float& z, const float& w) { return this->subtract(vec4(x, y, z, w)); }

	//vec4::Multiply
	vec4& vec4::multiply(const vec4& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	vec4& vec4::multiply(const float& other) { return this->multiply(vec4(other, other, other, other)); }
	vec4& vec4::multiply(const float& x, const float& y, const float& z, const float& w) { return this->multiply(vec4(x, y, z, w)); }

	//vec4::Divide
	vec4& vec4::divide(const vec4& other) {

		if (other.x == 0 || other.y == 0 || other.z == 0 || other.w == 0) {
			//Todo : Log error 
			return *this;
		}

		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;

		return *this;
	}

	vec4& vec4::divide(const float& other) { return this->divide(vec4(other, other, other, other)); }
	vec4& vec4::divide(const float& x, const float& y, const float& z, const float& w) { return this->divide(vec4(x, y, z, w)); }

	//Operator Overloads
	std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
		stream << "vec4 [" << vector.x << "," << vector.y << "]"; 
		return stream; 
	}

	vec4& operator+(vec4& a, const vec4& b) { return a.add(b); } 
	vec4& operator-(vec4& a, const vec4& b) { return a.subtract(b); }
	vec4& operator*(vec4& a, const vec4& b) { return a.multiply(b); }
	vec4& operator/(vec4& a, const vec4& b) { return a.divide(b); }

	vec4& vec4::operator+=(const vec4& b) { return this->add(b); }
	vec4& vec4::operator-=(const vec4& b) { return this->subtract(b); }
	vec4& vec4::operator*=(const vec4& b) { return this->multiply(b); }
	vec4& vec4::operator/=(const vec4& b) { return this->divide(b); }

	bool vec4::operator==(const vec4& b) { return this->x == b.x && this->y == b.y; }
	bool vec4::operator!=(const vec4& b) { return  !( *this == b ); }
	bool vec4::operator<(const vec4& b)	 { return this->x < b.x && this->y < b.y; }
	bool vec4::operator>(const vec4& b)  { return this->x > b.x&& this->y > b.y; }


}