#include "Vector2D.h"

Vector2D::Vector2D()
{
	x = 0;
	y = 0;
}

Vector2D::Vector2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2D & Vector2D::Add(const Vector2D & vec)
{
	this->x += vec.x;
	this->y += vec.y;

	return *this;
}

Vector2D & Vector2D::Subtract(const Vector2D & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;

	return *this;
}

Vector2D & Vector2D::Multiply(const Vector2D & vec)
{
	this->x *= vec.x;
	this->y *= vec.y;

	return *this;
}

Vector2D & Vector2D::Divide(const Vector2D & vec)
{
	this->x /= vec.x;
	this->y /= vec.y;

	return *this;
}

Vector2D & Vector2D::operator+=(const Vector2D & vec)
{
	return this->Add(vec);
}

Vector2D & Vector2D::operator-=(const Vector2D & vec)
{
	return this->Subtract(vec);
}

Vector2D & Vector2D::operator*=(const Vector2D & vec)
{
	return this->Multiply(vec);
}

Vector2D & Vector2D::operator/=(const Vector2D & vec)
{
	return this->Divide(vec);
}

Vector2D & Vector2D::operator*(const int & i)
{
	this->x *= i;
	this->y *= i;

	return *this;
}

Vector2D & Vector2D::Zero()
{
	this->x = 0;
	this->y = 0;

	return *this;
}


Vector2D Vector2D::operator+(const Vector2D & vec)
{
	Vector2D result;
	result.x = this->x + vec.x;
	result.y = this->y + vec.y;
	return result;
}

Vector2D Vector2D::operator-(const Vector2D & vec)
{
	Vector2D result;
	result.x = this->x - vec.x;
	result.y = this->y - vec.y;
	return result;
}

Vector2D Vector2D::operator*(const Vector2D & vec)
{
	Vector2D result;
	result.x = this->x * vec.x;
	result.y = this->y * vec.y;
	return result;
}

Vector2D Vector2D::operator/(const Vector2D & vec)
{
	Vector2D result;
	result.x = this->x / vec.x;
	result.y = this->y / vec.y;
	return result;
}


Vector2D & Vector2D::Rotate(const Vector2D &vec, float degrees)
{
	return this->RotateRadians(vec, degrees * degreesToRadians);
	//return vec.RotateRadians(vec, degrees * degreesToRadians);
}

Vector2D & Vector2D::RotateRadians(const Vector2D &vec, float radians)
{
	//Vector2D result;
	float c = cos(radians); 
	float s = sin(radians);
	this->x = c * vec.x - s * vec.y;
	this->y = s * vec.x + c * vec.y;
	return *this;
}


std::ostream & operator<<(std::ostream & stream, const Vector2D & vec)
{
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
}
