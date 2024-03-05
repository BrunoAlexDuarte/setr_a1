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

typedef struct stru_node {
	uint_16t id;
	unsigned char element[MAX_SIZE_ELEMENT];
	node *prev;
	node *next;
} node;

typedef struct {
	uint_16t size_elem;
	uint_16t max_size_list;
	uint_16t size_list;
	node *middle_head;
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
void MyDLLInit();

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
uint_16t MyDLLInsert(unsigned char *element);

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
unsigned char *MyDLLRemove(uint_16t id);

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
unsigned char *MyDLLFind(uint_16t id);

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
unsigned char *MyDLLFindNext();

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
unsigned char *MyDLLFindPrevious();




#endif
//EOF
