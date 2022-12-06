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

	system("pause");

	return 0;

}