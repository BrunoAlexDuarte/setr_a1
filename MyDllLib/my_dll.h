/** 
 * @file my_dll.h
 * @brief Doubly linked list declarations.
 *
 * This file contains declarations for a doubly linked list and related operations.
 * It includes structures, function prototypes, and descriptions of their functionalities.
 *
 * @author Bruno Duarte
 * @author Diogo Lapa
 *
 * @date 05-03-2024
 * @bug No bugs to report for now
 *
 */

#ifndef __MY_DLL_H__
#define __MY_DLL_H__

#define MAX_SIZE_LIST 512
#define MAX_SIZE_ELEMENT 256

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/** @struct node
 *
 *  @brief Represents a node in a doubly linked list.
 *
 *  This structure contains information for a node in a doubly linked list,
 *  including a unique identifier ('id'), an element with a maximum size ('element'),
 *  and indexes to the previous ('prev') and next ('next') nodes in the all_nodes array.
 *
 *  @var node::id
 *  Unique identifier for the node.
 *
 *  @var node::element
 *  Data element stored in the node.
 *
 *  @var node::prev
 *  Index of the previous node in the all_nodes array
 *
 *  @var node::next
 *  Index of the next node in the all_nodes array
 *
 */
typedef struct stru_node {
	uint16_t id;
	unsigned char element[MAX_SIZE_ELEMENT+1];
	uint16_t prev;
	uint16_t next;
} node;

/** @struct dLL
 *
 *  @brief Represents a doubly linked list along with metadata.
 * 
 *  This structure contains metadata about a doubly linked list, including the max size
 *  of each element ('size_elem'), the max size of the list ('size_list'), an array
 *  of nodes that form the doubly linked list ('all_nodes'), and the index of the head
 *  node ('place_head')
 *
 *  @var dLL::size_elem 
 *  Max size of each element in the list.
 *
 *  @var dLL::size_list 
 *  Max size of the linked list.
 *
 *  @var dLL::all_nodes
 *  Array of nodes forming the doubly linked list.
 *
 *  @var dLL::place_head
 *  Index of the head node.
 *
 */
typedef struct {
	uint16_t size_elem;
	uint16_t size_list;
	node all_nodes[MAX_SIZE_LIST+1];
	uint16_t place_head; //head of the list
	//uint16_t occupied[MAX_SIZE_LIST];
} dLL;

/**
 * @brief Initializes a doubly linked list with specified max element size and max list size.
 *
 * This function initializes a doubly linked list by setting the element size, list size and
 * and preparing the necessary memory structures.
 * 
 * @param[in] elem_size The max size of each element in the doubly linked list.
 * @param[in] list_size The max total size or capacity of the doubly linked list.
 *
 * @note This function should be called before using any other operations on the doubly linked list.
 * @warning Ensure that elem_size and list_size are valid and within acceptable limits.
 *
 */
void MyDLLInit(uint16_t elem_size, uint16_t list_size);

/**
 * \brief Inserts a new node with the specified ID and element into the doubly linked list.
 * 
 * This function inserts a new node with the given ID and element into the doubly linked list.
 *
 * @param[in] id The unique identifier for the new node.
 * @param[in] element String value to be stored in the new node.
 *
 * @return 0 if the insertion is successful, -1 if the insertion fails (e.g., due to duplicate ID or no more space).
 *
 * @note The function returns 0 on successful insertion, and -1 if the insertion fails.
 * @warning Ensure that the provided ID is unique within the doubly linked list.
 * 
 */
uint16_t MyDLLInsert(uint16_t id, unsigned char *element);

/**
 * @brief Removes a node with the specified ID from the doubly linked list.
 * 
 * This function removes a node with the given ID from the doubly linked list and returns 
 * the data element (string value) of the removed node.
 *
 * @param[in] id The unique identifier of the node to be removed.
 * 
 * @return Pointer to the data element of the removed node, or NULL if the node is not found.
 * 
 * @note The returned pointer is the data element of the removed node.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.  
 *
 */
unsigned char *MyDLLRemove(uint16_t id);

/**
 * @brief Finds the data element of a node with the specified ID in the doubly linked list.
 *
 * This function searches for a node with the given ID in the doubly linked list and returns
 * the data element (string value) of the found node.
 *
 * @param[in] id The unique identifier of the node to be found.
 * 
 * @return Pointer to the data element of the found node, or NULL if the node is not found.
 *
 * @note The returned pointer points to the data element of the found node.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFind(uint16_t id);

/**
 * @brief Finds the data element of the next node after the specified ID in the doubly linked list.
 *
 * This function searches for the node with the given ID in the doubly linked list and returns
 * the data element (string value) of the node that comes after it.
 *
 * @param[in] id The unique identifier of the current node.
 *
 * @return Pointer to the data element of the next node, or NULL if the next node is not found.
 *
 * @note The returned pointer points to the data element of the node that comes after the given ID.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFindNext(uint16_t id);

/**
 * @brief Finds the data element of the previous node before the specified ID in the doubly linked list.
 *
 * This function searches for the node with the given ID in the doubly linked list and returns
 * the data element (string value) of the node that comes before it.
 *
 * @param[in] id The unique identifier of the current node.
 *
 * @return Pointer to the data element of the previous node, or NULL if the previous node is not found.
 *
 * @note The returned pointer points to the data element of the node that comes before the given ID.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFindPrevious(uint16_t id);

// to be removed (acho eu)
void PrintNode(uint16_t i);
void PrintHead();

void PrintAllList();



#endif
//EOF
