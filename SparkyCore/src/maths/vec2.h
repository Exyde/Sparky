#pragma once
#include <iostream>

namespace sparky::maths {
	
	//Todo : Add Vec3 & Vec4 || Ctrl + Shift F is your friend ;)

	//Lower case so that it match GLSL conventions.
	struct vec2 {

		float x, y;

		vec2();
		vec2(const  float& x, const float& y);

		void Log() const;

		vec2& add(const vec2& other);
		vec2& subtract(const vec2& other);
		vec2& multiply(const vec2& other);
		vec2& divide(const vec2& other);

		//Overload
		vec2& add(const float& other);
		vec2& add(const float& a, const float& b);
		vec2& subtract(const float& other);
		vec2& subtract(const float& a, const float& b);
		vec2& multiply(const float& other);
		vec2& multiply(const float& a, const float& b);
		vec2& divide(const float& other);
		vec2& divide(const float& a, const float& b);



		//Friend just for the sake of it, if it was a class we could handle private members.
		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		friend vec2 operator+(vec2 a, const vec2& b);
		friend vec2 operator-(vec2 a, const vec2& b);
		friend vec2 operator*(vec2 a, const vec2& b);
		friend vec2 operator/(vec2 a, const vec2& b);

		// +-*/ & = operator are not friend. 
		vec2& operator+=(const vec2& b);
		vec2& operator-=(const vec2& b);
		vec2& operator*=(const vec2& b);
		vec2& operator/=(const vec2& b);

		//Comparaisons
		bool operator==(const vec2& b);
		bool operator!=(const vec2& b);
	};
}