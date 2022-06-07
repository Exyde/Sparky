#pragma once
#include <iostream>

namespace sparky::maths {
	
	//Todo : Add Vec3 & Vec4 || Ctrl + Shift F is your friend ;)

	//Lower case so that it match GLSL conventions.
	struct vec4 {

		float x, y, z, w;

		vec4();
		vec4(const  float& x, const float& y, const  float& z, const float& w);

		void Log() const;

		vec4& add(const vec4& other);
		vec4& subtract(const vec4& other);
		vec4& multiply(const vec4& other);
		vec4& divide(const vec4& other);

		//Overload
		vec4& add(const float& other);
		vec4& add(const float& x, const float& y, const float& z, const float& w);
		vec4& subtract(const float& other);
		vec4& subtract(const float& x, const float& y, const float& z, const float& w);
		vec4& multiply(const float& other);
		vec4& multiply(const float& x, const float& y, const float& z, const float& w);
		vec4& divide(const float& other);
		vec4& divide(const float& x, const float& y, const float& z, const float& w);



		//Friend just for the sake of it, if it was a class we could handle private members.
		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
		friend vec4& operator+(vec4& a, const vec4& b);
		friend vec4& operator-(vec4& a, const vec4& b);
		friend vec4& operator*(vec4& a, const vec4& b);
		friend vec4& operator/(vec4& a, const vec4& b);

		// +-*/ & = operator are not friend. 
		vec4& operator+=(const vec4& b);
		vec4& operator-=(const vec4& b);
		vec4& operator*=(const vec4& b);
		vec4& operator/=(const vec4& b);

		//Comparaisons
		bool operator==(const vec4& b);
		bool operator!=(const vec4& b);
	};
}