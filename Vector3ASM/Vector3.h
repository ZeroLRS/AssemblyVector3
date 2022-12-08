#pragma once

class __declspec(dllexport, align(16)) Vector3
{
public:

	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		float v[4];
	};

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

extern "C" void _Normalize(float* vec3);
extern "C" void _Normal(float* vec3, float* dest);