
#include "my_dll.h"


static dLL list;

void MyDLLInit(uint16_t elem_size, uint16_t list_size) {
	/*
	 * Ao inicializar guardamos o tamanho máximo dos elementos, o tamanho máximo da lista,
	 * colocamos na posicção list_size+1 um elemento a NULL para o qual as pontas apontam,
	 * e colocamos a lista a a pontar para esse mesmo elemento, e colocamos todos
	 * os elementos de occupied a zero
	 * */
	list.size_elem = elem_size;
	list.size_list = list_size;
	list.all_nodes[list_size] = NULL;
	list.place_middle = list_size;
	for (int i = 0; i < list_size; i++) 
		list.occupied = 0;
}

uint16_t MyDLLInsert(uint16_t id, unsigned char *element) {
	uint16_t head = list.place_middle;

	for (int i = 0; i < list.size_list; i++) {
		node node_each = list.all_nodes[i];
		
		//Vemos se o nós não está livre
		if (node_each.next.prev == i and node_each.prev.next == i) continue;

		node_each.id = id;
		strcpy(node_each.element, element);

		uint16_t count = 1;
		while (count) {

		}

	
	}
	

}

unsigned char *MyDLLRemove(uint16_t id) {
	uint16_t head = list.place_middle;
	uint16_t cont = 1;

	while (cont) {
		//Se estiver a apontar para o local nulo, acaba, não foi achado o elemento
		if (head == list.size_list) return NULL;

		node node_each = list.all_nodes[head];
		if (node_each.id == id) { //Retira o elemento caso os ids sejam iguais
			list.all_nodes[node_each.next].prev = node_each.prev;
			list.all_nodes[node_each.prev].next = node_each.next;
			return node_each.element;
		}
		if (node_each.id < id) {
			head = node_each.next;
		} else return NULL; 
		/*else {
			head = node_each.prev;
		}*/
	}
}

unsigned char *MyDLLFind(uint16_t id) {
	uint16_t head = list.place_middle;
	
	while (head != list.size_list) {
		node node_each = list.all_nodes[head];
		if (node_each.id == id) return node_each.element;
		head = node_each.next;
	}
	return NULL;
}

unsigned char *MyDLLFindNext(uint16_t id) {
	uint16_t head = list.place_middle;
	
	while (head != list.size_list) {
		node node_each = list.all_nodes[head];
		if (node_each.id == id) {
			if (node_each.next != list.size_list) 
				return list.all_nodes[node_each.next].element;
			return NULL;
		}
		head = node_each.next;
	}
	return NULL;

}

unsigned char *MyDLLFindPrevious(uint16_t id) {
	uint16_t head = list.place_middle;
	
	while (head != list.size_list) {
		node node_each = list.all_nodes[head];
		if (node_each.id == id) {
			if (node_each.prev != list.size_list) 
				return list.all_nodes[node_each.prev].element;
			return NULL;
		}
		head = node_each.next;
	}
	return NULL;
}



//EOF
