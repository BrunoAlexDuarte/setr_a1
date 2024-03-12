
#include "my_dll.h"
dLL MyDLLInit(uint16_t elem_size, uint16_t list_size, uint16_t order) {
	/*
	 * Ao inicializar guardamos o tamanho máximo dos elementos, o tamanho máximo da lista,
	 * colocamos na posicção list_size+1 um elemento a NULL para o qual as pontas apontam,
	 * e colocamos a lista a a pontar para esse mesmo elemento, e colocamos todos
	 * os elementos de occupied a zero
	 * */
	dLL list;
	if (MAX_SIZE_LIST < list_size || MAX_SIZE_ELEMENT < elem_size) {
		printf("Desired size of elem or list surpasses the max size possible, created with default max\n\r");
		printf("The max size of the list is %d and you wanted %d\n\r", MAX_SIZE_LIST, list_size);
		printf("The max size of the elements is %d and you wanted %d\n\r", MAX_SIZE_ELEMENT, elem_size);
		elem_size = MAX_SIZE_ELEMENT;
		elem_size = MAX_SIZE_LIST;
		
	}
	list.size_elem = elem_size;
	list.size_list = list_size;
	node last_node;
	last_node.prev = list_size;
	last_node.next = list_size;
	list.all_nodes[list_size] = last_node;
	for (uint16_t i = 0; i < list_size; i++) {
		list.all_nodes[i].prev = list_size;
		list.all_nodes[i].next = list_size;
	}
	list.place_head = list_size;
	list.order = order;
	return list;
}

uint16_t MyDLLInsert(dLL *list, uint16_t id, unsigned char *element) {
    node node_each;
    uint16_t failure = 1;
    uint16_t i;

	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
    for(i = 0; i < list->size_list; i++) {
        node_each = list->all_nodes[i];
        if(list->all_nodes[node_each.next].prev == i && list->all_nodes[node_each.prev].next == i) {
            continue;
        }

	//list->all_nodes[i].id = id;
	node_each.id = id;
	if (strlen(element) > list->size_elem) {
		printf("Couldn't add node beacuse the element is to big\n\r");
		return ELEMENT_TO_BIG;
	}
        strcpy(node_each.element, element);
        failure = 0;
		break;
    }
    if (failure) {
	printf("Couldn´t allocate space for new node %d\n\r", id);
	return DLL_FULL;
    }
    uint16_t current_index = list->place_head;
    node current_node;

    while(current_index != list->size_list) {
        current_node = list->all_nodes[current_index];
        if(current_node.id == id) { 
			printf("Couldn't insert node, duplicate id detected\n\r");
            return DUPLICATE_ID;
        }
        if((current_node.id > id && list->order) || (current_node.id < id && !list->order)) {
			if(current_index == list->place_head) {
				list->place_head = i;
			}
            node_each.next = current_index;
            node_each.prev = current_node.prev;
            list->all_nodes[current_node.prev].next = i;
            //current_node.prev = i;
			list->all_nodes[current_index].prev = i;
	    	list->all_nodes[i] = node_each;
            return SUCCESS;
        } else {
            current_index = current_node.next;
        }
    }
	
	if(list->place_head == list->size_list) {
		list->place_head = i;
	}
    
    current_node = list->all_nodes[current_index];
    node_each.next = current_index;
    node_each.prev = current_node.prev;
    list->all_nodes[current_node.prev].next = i;
    //current_node.prev = i;
    list->all_nodes[current_index].prev = i;
    list->all_nodes[i] = node_each;
    return SUCCESS;
}


uint16_t MyDLLRemove(dLL *list, uint16_t id, unsigned char *output) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	uint16_t head = list->place_head;
	node node_each;

	//Se estiver a apontar para o local nulo, acaba, não foi achado o elemento
	while (head != list->size_list) {
		node_each = list->all_nodes[head];
		if (node_each.id == id) { //Retira o elemento caso os ids sejam iguais
			list->all_nodes[node_each.next].prev = node_each.prev;
			list->all_nodes[node_each.prev].next = node_each.next;
			if (head == list->place_head) {
				list->place_head = node_each.next;	
			}
			char *element_str = list->all_nodes[head].element;
			memcpy(output, element_str, strlen(element_str));
			return SUCCESS;
		}
		if ((node_each.id < id && list->order) || (node_each.id > id && !list->order)) {
			head = node_each.next;
		} else return ID_NOT_FOUND; 
		/*else {
			head = node_each.prev;
		}*/
	}
	return ID_NOT_FOUND;
}

uint16_t MyDLLFind(dLL *list, uint16_t id, unsigned char *output) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	uint16_t head = list->place_head;
	
	while (head != list->size_list) {
		node node_each = list->all_nodes[head];
		printf("THE HEAD IS: %d and the id is %d\n",head,node_each.id);
		if (node_each.id == id) {
			char *element_str = list->all_nodes[head].element;
			memcpy(output, element_str, strlen(element_str));
			return SUCCESS;
		}
		head = node_each.next;
	}
	return ID_NOT_FOUND;
}

uint16_t MyDLLFindNext(dLL *list, uint16_t id, unsigned char *output) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	uint16_t head = list->place_head;
	
	while (head != list->size_list) {
		node node_each = list->all_nodes[head];
		if (node_each.id == id) {
			if (node_each.next != list->size_list) {
				char *element_str = list->all_nodes[node_each.next].element;
				memcpy(output, element_str, strlen(element_str));
				return SUCCESS;
			}
			return ID_NOT_FOUND;
		}
		head = node_each.next;
	}
	return ID_NOT_FOUND;

}

uint16_t MyDLLFindPrevious(dLL *list, uint16_t id, unsigned char *output) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	uint16_t head = list->place_head;
	
	while (head != list->size_list) {
		node node_each = list->all_nodes[head];
		if (node_each.id == id) {
			if (node_each.prev != list->size_list) {
				char *element_str = list->all_nodes[node_each.prev].element;
				memcpy(output, element_str, strlen(element_str));
				return SUCCESS;
			}
			return ID_NOT_FOUND;
		}
		head = node_each.next;
	}
	return ID_NOT_FOUND;
}

uint16_t MyDLLSizeIncrease(dLL *list, uint16_t size_increment) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	if (size_increment+list->size_list < MAX_SIZE_LIST) {
		uint16_t old_size = list->size_list;
		uint16_t new_size = list->size_list + size_increment;
		list->all_nodes[new_size].prev = list->all_nodes[old_size].prev;
		list->all_nodes[new_size].next = list->all_nodes[old_size].next;
		list->all_nodes[list->all_nodes[old_size].prev].next = new_size;
		list->all_nodes[list->all_nodes[old_size].next].prev = new_size;
		list->size_list = new_size;
		return SUCCESS;
	}
	printf("We couldn't increase the list size by %d\n\r", size_increment);
	return SURPASSES_LIST_SIZE_MAX;

}

uint16_t MyDLLElementSizeIncrease(dLL *list, uint16_t size_increment) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	if(size_increment+list->size_elem < MAX_SIZE_LIST) {
		list->size_elem += size_increment;
		return SUCCESS;
	}
	printf("We couldn't increase the element size by %d\n\r", size_increment);
	return SURPASSES_ELEMENT_SIZE_MAX;
}	


uint16_t MyDLLPrintNode(dLL *list, uint16_t i) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	if (i >= list->size_list) {
		printf("The index is bigger than the list size\n\r");
		return INVALID_INDEX;
	}
	printf("=================");
	printf("NODE %d\n", i);
	printf("ID %d\n", list->all_nodes[i].id);
	printf("ELEMENT %s\n", list->all_nodes[i].element);
	printf("PREV %d\n", list->all_nodes[i].prev);
	printf("NEXT %d\n", list->all_nodes[i].next);
	printf("=================");
	return SUCCESS;
}

uint16_t MyDLLPrintHead(dLL *list) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	printf("========HEAD=========");
	uint16_t i = list->place_head;
	printf("NODE %d\n", i);
	printf("ID %d\n", list->all_nodes[i].id);
	printf("ELEMENT %s\n", list->all_nodes[i].element);
	printf("PREV %d\n", list->all_nodes[i].prev);
	printf("NEXT %d\n", list->all_nodes[i].next);
	printf("=========HEAD========\n");
	return SUCCESS;
}

uint16_t MyDLLPrintAllList(dLL *list) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	uint16_t head = list->place_head;
	while (head != list->size_list) {
		printf("->Node:%d, with element:%s\n", list->all_nodes[head].id, list->all_nodes[head].element);
		head = list->all_nodes[head].next;
	}
	return SUCCESS;
}

uint16_t MyDLLPrintStats(dLL *list) {
	if (list == NULL) {
	    return DLL_NOT_VALID;
	}
	printf("The list size is %d\n\r", list->size_list);
	printf("The nodes element size is %d\n\r", list->size_elem);
	printf("The maximum possible sizes for each are %d and %d\n\r", MAX_SIZE_LIST, MAX_SIZE_ELEMENT);
	return SUCCESS;
}

//EOF
