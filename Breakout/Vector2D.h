#pragma once

#ifndef VECTOR2D_H
#define VECTOR2D_H

#define SDL_MAIN_HANDLED
#define USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Vector2D
{
	public:
		float x;
		float y;
		const float pi = static_cast<float>(atan(1) * 4);
		const float degreesToRadians = pi / 180;

		Vector2D();
		Vector2D(float x, float y);

		Vector2D &Add(const Vector2D &vec);
		Vector2D &Subtract(const Vector2D &vec);
		Vector2D &Multiply(const Vector2D &vec);
		Vector2D &Divide(const Vector2D &vec);

		Vector2D operator+(const Vector2D &vec);
		Vector2D operator-(const Vector2D &vec);
		Vector2D operator*(const Vector2D &vec);
		Vector2D operator/(const Vector2D &vec);

		Vector2D &operator+=(const Vector2D &vec);
		Vector2D &operator-=(const Vector2D &vec);
		Vector2D &operator*=(const Vector2D &vec);
		Vector2D &operator/=(const Vector2D &vec);

		Vector2D &operator*(const int& i);
		Vector2D &Zero();

		Vector2D &Rotate(const Vector2D &vec, float degrees);
		Vector2D &RotateRadians(const Vector2D &vec, float radians);

		friend std::ostream &operator<<(std::ostream &stream, const Vector2D &vec);
};

#endif