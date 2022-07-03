#include "vec3.h"

namespace sparky::maths {

	vec3::vec3() { x = 0.0f; y = 0.0f; z = 0.0f; }

	vec3::vec3(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y= y;
		this->z = z;
	}

	void vec3::Log() const {
		std::cout << *this << std::endl;
	}

	//vec3::Add
	vec3& vec3::add(const vec3& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	vec3& vec3::add(const float& other) { return this->add(vec3(other, other, other)); }
	vec3& vec3::add(const float& a, const float& b, const float& c) { return this->add(vec3(a, b, c)); }

	//vec3::Substract
	vec3& vec3::subtract(const vec3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	vec3& vec3::subtract(const float& other) { return this->subtract(vec3(other, other, other)); }
	vec3& vec3::subtract(const float& a, const float& b, const float& c) { return this->subtract(vec3(a, b, c)); }

	//vec3::Multiply
	vec3& vec3::multiply(const vec3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	vec3& vec3::multiply(const float& other) { return this->multiply(vec3(other, other, other)); }
	vec3& vec3::multiply(const float& a, const float& b, const float& c) { return this->multiply(vec3(a, b, c)); }

	//vec3::Divide
	vec3& vec3::divide(const vec3& other) {

		if (other.x == 0 || other.y == 0 || other.z == 0) {
			//Todo : Log error 
			return *this;
		}

		x /= other.x;
		y /= other.y;
		y /= other.z;

		return *this;
	}

	vec3& vec3::divide(const float& other) { return this->divide(vec3(other, other, other)); }
	vec3& vec3::divide(const float& a, const float& b, const float& c) { return this->divide(vec3(a, b, c)); }

	//Operator Overloads
	std::ostream& operator<<(std::ostream& stream, const vec3& vector) {
		stream << "vec3 [" << vector.x << "," << vector.y << "," << vector.z <<"]";
		return stream; 
	}

	vec3 operator+(vec3 a, const vec3& b) { return a.add(b); } 
	vec3 operator-(vec3 a, const vec3& b) { return a.subtract(b); }
	vec3 operator*(vec3 a, const vec3& b) { return a.multiply(b); }
	vec3 operator/(vec3 a, const vec3& b) { return a.divide(b); }

	vec3& vec3::operator+=(const vec3& b) { return this->add(b); }
	vec3& vec3::operator-=(const vec3& b) { return this->subtract(b); }
	vec3& vec3::operator*=(const vec3& b) { return this->multiply(b); }
	vec3& vec3::operator/=(const vec3& b) { return this->divide(b); }

	bool vec3::operator==(const vec3& b) { return this->x == b.x && this->y == b.y && this->z == b.z; }
	bool vec3::operator!=(const vec3& b) { return  !( *this == b ); }
}