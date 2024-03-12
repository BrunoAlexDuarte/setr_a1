
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	printf("Will initialize list with elem_sisze 5 and list_size 1, ascending\n\r");
	MyDLLInit(5, 2,1);
	unsigned char s1[] = "oLa"; 
	printf("Will add node 69 with %s\n\r", s1);
	MyDLLInsert(69, s1);
	unsigned char s2[] = ">BOM DIA"; 
	printf("Will add node 100 with %s\n\r", s2);
	MyDLLInsert(100, s2);
	MyDLLElementSizeIncrease(30);
	printf("Will add node 100 with %s\n\r", s2);
	MyDLLInsert(100, s2);
	unsigned char s3[] = ">BOA TARDE"; 
	printf("Will add node 90 with %s\n\r", s3);
	MyDLLInsert(90, s3);
	MyDLLSizeIncrease(3);
	printf("Will add node 90 with %s\n\r", s3);
	MyDLLInsert(90, s3);
	unsigned char s4[] = "CABE;A DA DOUBLY LINKED LIST"; 
	MyDLLInsert(55, s4);
	printf("Will add node 55 with %s\n\r", s4);
	MyDLLPrintAllList();
	printf("Will delete node 90\n\r");
	MyDLLRemove(90);
	MyDLLPrintAllList();
	return 0;
}

//EOF
