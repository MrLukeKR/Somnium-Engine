#pragma once

#include <stdio.h>
#include <string>

namespace Somnium
{
	namespace Maths
	{
		struct Vector3
		{
			float x, y, z;

			Vector3(float scalar = 0)
				:x(scalar), y(scalar), z(scalar) {};

			Vector3(float x, float y, float z)
				: x(x), y(y), z(z) {};

			~Vector3() {};

			//Addition Operators
			Vector3  operator+ (const Vector3&) const;
			Vector3& operator+=(const Vector3&);

			//Negation operator
			Vector3 operator-() const;

			//Subtraction Operators
			Vector3  operator- (const Vector3&) const;
			Vector3& operator-=(const Vector3&);

			//Multiplication Operators
			Vector3  operator* (const Vector3&) const;
			Vector3& operator*=(const Vector3&);

			Vector3  operator* (float) const;
			Vector3& operator*=(float);

			Vector3 normalise() const;
			float dot(const Vector3 &vector) const;
			static float dot(const Vector3& vector1, const Vector3& vector2);

			double magnitude(void) const;

			std::string toString() 
			{ 
				static const int buffSize = 256;
				char buff[buffSize];
#ifdef _WIN32
				sprintf_s(buff, buffSize, "[%f, %f, %f]", x, y, z);
#else
				snprintf(buff, buffSize, "[%f, %f, %f]", x, y, z);
#endif

				return std::string(buff);  
			}
		};
	}
}
