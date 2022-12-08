#include "Vector3.h"

Vector3::Vector3(float xVal, float yVal, float zVal)
{
	x = xVal;
	y = yVal;
	z = zVal;
	w = 0;
}

Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

float Vector3::Dot(Vector3& other)
{
	return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::Normal()
{
	Vector3 normal = Vector3();
	_Normal(v, normal.v);

	return normal;
}

void Vector3::Normalize()
{
	_Normalize(v);
}

float Vector3::Magnitude()
{
	return 0.0f;// sqrt(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude()
{
	return x * x + y * y + z * z;
}

Vector3 Vector3::Cross(Vector3& other)
{
	Vector3 cross = Vector3(x, y, z);

	cross.x = y * other.z - z * other.y;
	cross.y = z * other.x - x * other.z;
	cross.z = x * other.y - y * other.x;

	return cross;
}

float Vector3::Distance(Vector3& other)
{
	return 0.0f;// sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z));
}

float Vector3::SqrDistance(Vector3& other)
{
	return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z);
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
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
