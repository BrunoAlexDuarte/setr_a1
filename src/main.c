
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {

	MyDLLInit(50, 10);
	MyDLLInsert(3, "OLa");
	printf("%s\n",MyDLLFind(3));

	return 0;
}

//EOF
