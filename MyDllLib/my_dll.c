
#include "my_dll.h"


static dLL list;

void MyDLLInit(uint_16t elem_size, uint_16t list_size) {
//	dLL list_init;
	list.size_elem = elem_size;
	list.size_list = list_size;
	list.middle_head = NULL;
	list.all_nodes[list_size] = NULL;
}


uint_16t MyDLLInsert(unsigned char *element) {}

unsigned char *MyDLLRemove(uint_16t id) {
	
	head = list.middle_head;
	

}


void takeElem(node *head, uint_16t id) {
	//percorro a lista
	//achei o elemento
		//coloco o previous e o next a apontar um para o outro
		//coloca a string toda a zeros
		//coloco a 0 no ocupied


}



void adjustDLLCenter() {
	if (list.place_middle < list.size_list / 2) {
		list.place_middle -= 1;
		list.middle_head = list.middle_head.prev;
		adjustDLLCenter();
		return;
	}
	if (list.place_middle > list.size_list / 2 +1 ) {
		list.place_middle += 1;
		list.middle_head = list.middle_head.next;
		adjustDLLCenter();
		return;
	}
}

unsigned char *MyDLLFind(uint_16t id) {}
unsigned char *MyDLLFindNext(uint_16t id);
unsigned char *MyDLLFindPrevious(uint_16t id);



//EOF
