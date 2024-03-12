
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	MyDLLInit(200, 10,0);
	MyDLLInsert(69, "OLa");
	MyDLLInsert(100, ">BOM DIA");
	MyDLLInsert(90, ">BOA TARDE");
	MyDLLInsert(55, "CABE;A DA DOUBLY LINKED LIST");
	PrintHead();
	PrintAllList();
	MyDLLRemove(100);
	PrintAllList();
	PrintHead();
	//MyDLLInsert(55, "ADEUS");
	//printf("o elemento e %s\n",MyDLLFind(3));
	return 0;
}

//EOF
