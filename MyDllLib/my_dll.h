/** \file my_dll.h
 * \brief Function description Header file of the library that contains the dLL functionality
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05-03-2024
 * \bug No bugs to report for now
 *
 * */
#ifndef __MY_DLL_H__
#define __MY_DLL_H__

#define MAX_SIZE_LIST 512
#define MAX_SIZE_ELEMENT 256

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct stru_node {
	uint16_t id;
	unsigned char element[MAX_SIZE_ELEMENT+1];
	uint16_t prev;
	uint16_t next;
} node;

typedef struct {
	uint16_t size_elem;
	uint16_t size_list;
	node all_nodes[MAX_SIZE_LIST+1];
	uint16_t place_middle; //head of the list
	//uint16_t occupied[MAX_SIZE_LIST];
} dLL;


/**
 * \brief Initiates the dLL
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
void MyDLLInit(uint16_t elem_size, uint16_t list_size);

/**
 * \brief Inserts the given element in the dLL and returns the id
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
uint16_t MyDLLInsert(uint16_t id, unsigned char *element);

/**
 * \brief Function description
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
unsigned char *MyDLLRemove(uint16_t id);

/**
 * \brief Function description
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
unsigned char *MyDLLFind(uint16_t id);

/**
 * \brief Function description
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
unsigned char *MyDLLFindNext(uint16_t id);

/**
 * \brief Function description
 *
 * \author Bruno Duarte
 * \author Diogo Lapa
 *
 * \date 05/03/2024
 *
 * \param[in]
 * \param[out]
 *
 */
unsigned char *MyDLLFindPrevious(uint16_t id);

void PrintNode(uint16_t i);
void PrintCABECA();



#endif
//EOF
