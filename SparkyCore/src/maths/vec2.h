#pragma once
#include <iostream>

namespace sparky::maths {
	
	//Todo : Overload with float parameters (1 or 2)
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


		//Friend just for the sake of it, if it was a class we could handle private members.
		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
		friend vec2& operator+(vec2& a, const vec2& b);
		friend vec2& operator-(vec2& a, const vec2& b);
		friend vec2& operator*(vec2& a, const vec2& b);
		friend vec2& operator/(vec2& a, const vec2& b);

		// +-*/ & = operator are not friend. 
		vec2& operator+=(const vec2& b);
		vec2& operator-=(const vec2& b);
		vec2& operator*=(const vec2& b);
		vec2& operator/=(const vec2& b);

		//Comparaisons
		bool operator==(const vec2& b);
		bool operator!=(const vec2& b);

		//Is this really usefull ?
		bool operator<(const vec2& b);
		bool operator>(const vec2& b);
	};
}