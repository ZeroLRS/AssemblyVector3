#ifdef _V3ASM
#include "../Vector3ASM/Vector3.h"
#endif
#ifdef _V3CPP
#include "../Vector3/Vector3.h"
#endif

#include <iostream>

int main()
{

	V3Test();

	std::cout << "Hello World" << std::endl;

	system("pause");

	return 0;

}