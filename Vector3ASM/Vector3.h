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

extern "C" float _Dot(float* selfV, float* otherV);

extern "C" void _Normal(float* vec3, float* dest);
extern "C" void _Normalize(float* vec3);

extern "C" float _Magnitude(float* vec3);
extern "C" float _SqrMagnitude(float* vec3);

extern "C" void _Cross(float* selfV, float* otherV, float* dest);

extern "C" float _Distance(float* selfV, float* otherV);
extern "C" float _SqrDistance(float* selfV, float* otherV);

extern "C" bool _Add(float* selfV, const float* otherV, float* dest);
extern "C" bool _Subtract(float* selfV, const float* otherV, float* dest);
extern "C" bool _MultiplyScalar(float* selfV, const float scalar, float* dest);
extern "C" bool _Equals(float* selfV, const float* otherV);
extern "C" bool _NotEquals(float* selfV, const float* otherV);