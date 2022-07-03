#pragma once
#include <iostream>

namespace sparky::maths {
	

	//Lower case so that it match GLSL conventions.
	struct vec3 {

		float x, y, z;

		vec3();
		vec3(const float& x, const float& y, const float& z);

		void Log() const;

		vec3& add(const vec3& other);
		vec3& subtract(const vec3& other);
		vec3& multiply(const vec3& other);
		vec3& divide(const vec3& other);

		//Overload
		vec3& add(const float& other);
		vec3& add(const float& x, const float& y, const float& z);
		vec3& subtract(const float& other);
		vec3& subtract(const float& x, const float& y, const float& z);
		vec3& multiply(const float& other);
		vec3& multiply(const float& x, const float& y, const float& z);
		vec3& divide(const float& other);
		vec3& divide(const float& x, const float& y, const float& z);



		//Friend just for the sake of it, if it was a class we could handle private members.
		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);
		friend vec3& operator+(vec3 a, const vec3& b);
		friend vec3& operator-(vec3 a, const vec3& b);
		friend vec3& operator*(vec3 a, const vec3& b);
		friend vec3& operator/(vec3 a, const vec3& b);

		// +-*/ & = operator are not friend. 
		vec3& operator+=(const vec3& b);
		vec3& operator-=(const vec3& b);
		vec3& operator*=(const vec3& b);
		vec3& operator/=(const vec3& b);

		//Comparaisons
		bool operator==(const vec3& b);
		bool operator!=(const vec3& b);
	};
}