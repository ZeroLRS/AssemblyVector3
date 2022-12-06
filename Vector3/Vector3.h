#pragma once

class __declspec(dllexport) Vector3
{

public:

	float x, y, z;

	Vector3(float xVal, float yVal, float zVal);

	Vector3();

	float Dot(Vector3& other);

	Vector3 Normal();

	void Normalize();

	float Magnitude();

	float SqrMagnitude();

	Vector3 Cross(Vector3& other);

	float Distance(Vector3& other);

	float SqrDistance(Vector3& other);

	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(const float scalar);
	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);
};
