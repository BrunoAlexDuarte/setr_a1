
#include "my_dll.h"


static dLL list;

void MyDLLInit(uint16_t elem_size, uint16_t list_size) {
//	dLL list_init;
	list.size_elem = elem_size;
	list.size_list = list_size;
	//list.middle_head = NULL;
	list.all_nodes[list_size] = NULL;
}


uint16_t MyDLLInsert(unsigned char *element) {}

unsigned char *MyDLLRemove(uint16_t id) {

	

}


void takeElem(node *head, uint16_t id) {
	//percorro a lista
	//achei o elemento
		//coloco o previous e o next a apontar um para o outro
		//coloca a string toda a zeros
		//coloco a 0 no ocupied


}



void adjustDLLCenter() {
	if (list.place_middle < list.size_list / 2) {
		list.place_middle -= 1;
		//list.middle_head = list.middle_head.prev;
		adjustDLLCenter();
		return;
	}
	if (list.place_middle > list.size_list / 2 +1 ) {
		list.place_middle += 1;
		//list.middle_head = list.middle_head.next;
		adjustDLLCenter();
		return;
	}
}

unsigned char *MyDLLFind(uint16_t id) {}
unsigned char *MyDLLFindNext(uint16_t id);
unsigned char *MyDLLFindPrevious(uint16_t id);



//EOF
