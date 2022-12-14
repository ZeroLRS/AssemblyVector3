#ifdef _V3ASM
#include "../Vector3ASM/Vector3.h"
#endif
#ifdef _V3CPP
#include "../Vector3/Vector3.h"
#endif

#include <iostream>
#include <chrono>
#include <stdlib.h>

void PrintVector(Vector3 v)
{
	std::cout << v.x << ", " << v.y << ", " << v.z;
}

void TestAllFunctionsAndPrint()
{
	Vector3 v1 = Vector3(1, 2, 3);
	Vector3 v2 = Vector3(4, 5, 6);

	std::cout << "v1: ";
	PrintVector(v1);
	std::cout << std::endl << "v2: ";
	PrintVector(v2);

	Vector3 v3 = v1.Normal();
	Vector3 v4 = v2;
	v4.Normalize();

	std::cout << std::endl;
	PrintVector(v3);
	std::cout << std::endl;
	PrintVector(v4);

	std::cout << std::endl << std::endl;

	std::cout << "v1: ";
	PrintVector(v1);
	std::cout << std::endl << "v2: ";
	PrintVector(v2);
	std::cout << std::endl;
	std::cout << std::endl << "Magnitude: " << v1.Magnitude() << " SqrMagnitude: " << v1.SqrMagnitude();
	std::cout << std::endl << "Distance: " << v1.Distance(v2) << " SqrDistance: " << v1.SqrDistance(v2) << std::endl;
	std::cout << "Cross: ";
	Vector3 v5 = v1.Cross(v2);
	PrintVector(v5);
	std::cout << " Dot: " << v1.Dot(v2) << std::endl << std::endl;

	std::cout << "+:";
	PrintVector(v1 + v2);
	std::cout << std::endl << "-:";
	PrintVector(v1 - v2);
	std::cout << std::endl << "*:";
	PrintVector(v1 * 2);
	std::cout << std::endl;
	std::cout << "v1 == v1: " << (v1 == v1) << " v1 != v1: " << (v1 != v1) << std::endl;
	std::cout << "v1 == v2: " << (v1 == v2) << " v1 != v2: " << (v1 != v2) << std::endl;
}

void volatile TestAllFunctions(Vector3& v1, Vector3& v2)
{
	Vector3 v3 = v1.Normal();
	Vector3 v4 = v2;

	v4.Normalize();

	v1.Magnitude();
	v1.SqrMagnitude();

	v1.Distance(v2);
	v1.SqrDistance(v2);

	v1.Cross(v2);
	v1.Dot(v2);

	v1 + v2;
	v1 - v2;
	v1 * 2;
	v1 == v1;
	v1 != v1;
	v1 == v2;
	v1 != v2;
}

int main()
{
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	long long seed = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	srand(seed);

	Vector3* v1arr = new Vector3[1000000];
	Vector3* v2arr = new Vector3[1000000];

	std::cout << "Generating random vectors..." << std::endl;

	for (int i = 0; i < 1000000; i++)
	{
		v1arr[i].x = rand() / RAND_MAX * 10000.0f;
		v1arr[i].y = rand() / RAND_MAX * 10000.0f;
		v1arr[i].z = rand() / RAND_MAX * 10000.0f;

		v2arr[i].x = rand() / RAND_MAX * 10000.0f;
		v2arr[i].y = rand() / RAND_MAX * 10000.0f;
		v2arr[i].z = rand() / RAND_MAX * 10000.0f;
	}

	std::cout << "Running tests..." << std::endl;

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	
	for (int i = 0; i < 1000000; i++)
	{
		TestAllFunctions(v1arr[i], v2arr[i]);
	}

	std::chrono::high_resolution_clock::time_point done = std::chrono::high_resolution_clock::now();

	std::cout << std::endl << "Took: " << std::chrono::duration_cast<std::chrono::milliseconds>(done - start).count() << std::endl;

	system("pause");

	return 0;

}