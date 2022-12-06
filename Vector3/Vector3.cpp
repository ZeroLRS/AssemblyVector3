#include "Vector3.h"
#include <math.h>

Vector3::Vector3(float xVal, float yVal, float zVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

float Vector3::Dot(Vector3& other)
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Normal()
{
	Vector3 normal = Vector3(x, y, z);
	float magnitude = Magnitude();

	normal.x /= magnitude;
	normal.y /= magnitude;
	normal.z /= magnitude;

	return normal;
}

void Vector3::Normalize()
{
	float magnitude = Magnitude();

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

float Vector3::Magnitude()
{
	return sqrt(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude()
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Cross(Vector3& other)
{
	Vector3 cross = Vector3(x, y, z);

	cross.x = cross.y * other.z - cross.z * other.y;
	cross.y = cross.z * other.x - cross.x * other.z;
	cross.z = cross.x * other.y - cross.y * other.x;

	return cross;
}

float Vector3::Distance(Vector3& other)
{
	return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

float Vector3::SqrDistance(Vector3& other)
{
	return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y);
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator*(const float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

bool Vector3::operator==(const Vector3& other)
{
	if (x != other.x)
		return false;
	if (y != other.y)
		return false;
	if (z != other.z)
		return false;
	return true;
}

bool Vector3::operator!=(const Vector3& other)
{
	if (x == other.x)
		return false;
	if (y == other.y)
		return false;
	if (z == other.z)
		return false;
	return true;
}
