
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	printf("Will initialize list with elem_sisze 5 and list_size 2, ascending\n\r");
	dLL lista = MyDLLInit(1000, 2,0);
	unsigned char s1[] = "oLa"; 
	printf("Will add node 69 with %s\n\r", s1);
	MyDLLInsert(&lista, 69, s1);
	unsigned char s2[] = ">BOM DIA"; 
	printf("Will add node 100 with %s\n\r", s2);
	MyDLLInsert(&lista, 100, s2);
	MyDLLElementSizeIncrease(&lista, 30);
	printf("Will add node 100 with %s\n\r", s2);
	MyDLLInsert(&lista, 100, s2);
	unsigned char s3[] = ">BOA TARDE"; 
	printf("Will add node 90 with %s\n\r", s3);
	MyDLLInsert(&lista, 90, s3);
	MyDLLSizeIncrease(&lista, 3);
	printf("Will add node 90 with %s\n\r", s3);
	MyDLLInsert(&lista, 90, s3);
	unsigned char s4[] = "CABE;A DA DOUBLY LINKED LIST"; 
	MyDLLInsert(&lista, 55, s4);
	printf("Will add node 55 with %s\n\r", s4);
	MyDLLPrintAllList(&lista);
	printf("Will delete node 90\n\r");
	unsigned char retirou[256];
	MyDLLRemove(&lista, 90, retirou);
	printf("O elemento 90 tinha a string %s\n", retirou);
	MyDLLPrintAllList(&lista);
	MyDLLFind(&lista, 55, retirou);
	printf("O elemento 55 tinha a string %s\n", retirou);
	uint16_t res = MyDLLFind(&lista, 89, retirou);
	if (res!=0) printf("O find falhou\n");
	res = MyDLLRemove(&lista, 89, retirou);
	if (res!=0) printf("O remove falhou\n");
	return 0;
}

//EOF
