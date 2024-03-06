
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	MyDLLInit(50, 10);
	MyDLLInsert(69, "OLa");
	PrintCABECA();
	MyDLLInsert(100, ">BOM DIA");
	PrintCABECA();
	MyDLLInsert(90, ">BOA TARDE");
	PrintCABECA();
	MyDLLInsert(55, "CABE;A DA DOUBLY LINKED LIST");
	PrintCABECA();
	PrintNode(3);
	PrintNode(0);
	PrintNode(2);
	PrintNode(1);
	PrintNode(10);
	//MyDLLInsert(55, "ADEUS");
	//printf("o elemento e %s\n",MyDLLFind(3));
	return 0;
}

//EOF
