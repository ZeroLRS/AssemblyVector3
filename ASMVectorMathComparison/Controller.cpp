#ifdef _V3ASM
#include "../Vector3ASM/Vector3.h"
#endif
#ifdef _V3CPP
#include "../Vector3/Vector3.h"
#endif

#include <iostream>

void PrintVector(Vector3 v)
{
	std::cout << v.x << ", " << v.y << ", " << v.z;
}

int main()
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

	system("pause");

	return 0;

}