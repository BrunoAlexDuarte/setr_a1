
#include "../MyDllLib/my_dll.h"

int main(int argc, char **argv) {
	uint16_t size_list_i = 3;
	uint16_t size_elem_i = 5;
	uint16_t res = 0;
	unsigned char res_str[MAX_SIZE_ELEMENT+1];
	uint16_t id = 0;

	printf(" ->init dll -> elem_size %d and list_size %d, ascending\n\r", size_list_i, size_elem_i);
	dLL lista = MyDLLInit(size_elem_i, size_list_i,1);

	unsigned char s1[] = "test1"; 
	id = 69;

	printf(" ->Will add node %d with %s\n\r", id, s1);
	res = MyDLLInsert(&lista, id, s1);
	if (res != SUCCESS) printf("\tFailed miserably_1\n\r");

	unsigned char s2[] = "BOM DIA"; 
	id = 100;
	printf(" ->Will add node %d with %s\n\r", id, s2);
	res = MyDLLInsert(&lista, id, s2);
	if (res != ELEMENT_TO_BIG) printf("\tFailed miserably_2\n\r");

	uint16_t inc = 30;
	printf(" ->As the element was to big, will increase size by %d\n\r", inc);
	res = MyDLLElementSizeIncrease(&lista, 30);
	if (res != SUCCESS) printf("\tFailed miserably_3\n\r");

	printf(" ->Will add node 100 with %s again\n\r", s2);
	res = MyDLLInsert(&lista, 100, s2);
	if (res != SUCCESS) printf("\tFailed miserably_4\n\r");

	id = 90;
	unsigned char s3[] = "BOA TARDE"; 
	printf(" ->Will add node %d with %s\n\r", id, s3);
	res = MyDLLInsert(&lista, 90, s3);
	if (res != SUCCESS) printf("\tFailed miserably_5\n\r");

	id = 91;
	unsigned char s4[] = "BOA NOITE"; 
	printf(" ->Will add node %d with %s\n\r", id,  s4);
	res = MyDLLInsert(&lista, 90, s3);
	if (res != DLL_FULL) printf("\tFailed miserably_5\n\r");
	
	inc = 10;
	printf(" ->as the dLL was full, will increase the size by %d\n\r", inc);
	res = MyDLLSizeIncrease(&lista, 3);
	if (res != SUCCESS) printf("\tFailed miserably_5\n\r");

	printf(" ->Will add node %d with %s\n\r", id, s4);
	res = MyDLLInsert(&lista, id, s4);
	if (res != SUCCESS) printf("\tFailed miserably_6\n\r");

	printf(" ->Try to show null list\n\r");
	res = MyDLLPrintAllList(NULL);
	if (res != DLL_NOT_VALID) printf("\tFailed miserably 7\n\r");

	printf(" ->Now show real list\n\r");
	res = MyDLLPrintAllList(&lista);
	if (res != DLL_NOT_VALID) printf("\tFailed miserably 8\n\r");

	printf(" ->Will add node %d with %s again\n\r", id, s3);
	res = MyDLLInsert(&lista, id, s3);
	if (res != DUPLICATE_ID) printf("\tFailed miserably_9\n\r");

	printf(" ->The actual head\n\r");
	res = MyDLLPrintHead(&lista);
	if (res != SUCCESS) printf("\tFailed miserably_10\n\r");

	id = 10;
	unsigned char s5[] = "CABE;A DA DOUBLY LINKED LIST"; 
	printf(" ->Will add node %d with %s to be the new head\n\r", id, s5);
	res = MyDLLInsert(&lista, id, s4);
	if (res != SUCCESS) printf("\tFailed miserably_11\n\r");
	
	printf(" ->The new head\n\r");
	res = MyDLLPrintHead(&lista);
	if (res != SUCCESS) printf("\tFailed miserably_12\n\r");

	printf(" ->Show the list till now\n\r");
	res = MyDLLPrintAllList(&lista);
	if (res != SUCCESS) printf("\tFailed miserably_13\n\r");

	id = 90;
	printf(" ->Will delete node %d\n\r", id);
	res = MyDLLRemove(&lista, 90, res_str);
	if (res != SUCCESS) printf("\tFailed miserably_14\n\r");
	printf(" ->O elemento %d tinha a string %s\n", id, res_str);

	printf(" ->A nova lista é\n\r");
	res = MyDLLPrintAllList(&lista);
	if (res != SUCCESS) printf("\tFailed miserably_15\n\r");

	printf(" ->Vai criar uma nova lista tamanhos acima do suposto e tentar achar um elemento nela\n\r");
	uint16_t new_size = 1000;
	dLL lista2 = MyDLLInit(new_size, new_size,1);
	res = MyDLLPrintStats(&lista2);
	if (res != SUCCESS) printf("\tFailed miserably_16\n\r");
	
	id = 10;
	printf(" ->Will find node %d\n\r", id);
	res = MyDLLFind(&lista2, id, res_str);
	if (res != ID_NOT_FOUND) printf("\tFailed miserably_17\n\r");

	printf(" ->Will find node %d\n\r", id);
	res = MyDLLFind(&lista, id, res_str);
	if (res != SUCCESS) printf("\tFailed miserably_18\n\r");
	printf(" ->O elemento %d string %s\n", id, res_str);

	id = 89;
	printf(" ->Vai tentar remover elemento que não existe\n\r");
	res = MyDLLRemove(&lista, id, res_str);
	if (res != ID_NOT_FOUND) printf("\tFailed miserably_19\n\r");
	return 0;
}


//EOF
