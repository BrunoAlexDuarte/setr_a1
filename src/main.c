
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	MyDLLInit(200, 2,0);
	MyDLLInsert(69, "OLa");
	MyDLLInsert(100, ">BOM DIA");
	MyDLLInsert(90, ">BOA TARDE");
	MyDLLSizeIncrease(10);
	MyDLLInsert(55, "CABE;A DA DOUBLY LINKED LIST");
	MyDLLPrintHead();
	MyDLLPrintAllList();
	MyDLLRemove(100);
	//PrintAllList();
	MyDLLPrintHead();
	//MyDLLInsert(55, "ADEUS");
	//printf("o elemento e %s\n",MyDLLFind(3));
	return 0;
}

//EOF
