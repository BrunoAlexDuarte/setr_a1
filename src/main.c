
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	MyDLLInit(200, 2,0);
	unsigned char s1[] = "oLa"; 
	MyDLLInsert(69, s1);
	unsigned char s2[] = ">BOM DIA"; 
	MyDLLInsert(100, s2);
	unsigned char s3[] = ">BOA TARDE"; 
	MyDLLInsert(90, s3);
	MyDLLSizeIncrease(1);
	unsigned char s4[] = "CABE;A DA DOUBLY LINKED LIST"; 
	MyDLLInsert(55, s4);
	//MyDLLPrintHead();
	MyDLLPrintAllList();
	//MyDLLRemove(100);
	//PrintAllList();
	//MyDLLPrintHead();
	//MyDLLInsert(55, "ADEUS");
	//printf("o elemento e %s\n",MyDLLFind(3));
	return 0;
}

//EOF
