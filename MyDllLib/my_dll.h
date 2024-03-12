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

#define SUCCESS 0
#define DLL_FULL 1
#define DLL_NOT_VALID 2
#define ELEMENT_TO_BIG 3
#define DUPLICATE_ID 4
#define SURPASSES_LIST_SIZE_MAX 5
#define SURPASSES_ELEMENT_SIZE_MAX 6
#define INVALID_ID 7

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
typedef struct {
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
 *  @var dLL::order
 *  Specified the order in which new nodes are inserted (0 for ascending, 1 for descending)
 * 
 */
typedef struct {
	uint16_t size_elem;
	uint16_t size_list;
	node all_nodes[MAX_SIZE_LIST+1];
	uint16_t place_head; //head of the list
	uint16_t order;
} dLL;

/**
 * @brief Initializes a doubly linked list with specified max element size, max list size, and order.
 *
 * This function initializes a doubly linked list by setting the element size, list size,
 * and preparing the necessary memory structures. The order parameter determines whether
 * the list inserts new nodes in ascending (order=0) or descending (order=1) order.
 * 
 * @param[in] elem_size The max size of each element in the doubly linked list.
 * @param[in] list_size The max total size or capacity of the doubly linked list.
 * @param[in] order Specifies the order of the doubly linked list (0 for ascending, 1 for descending).
 * 
 * @return Initiliazed doubly linked list with the specified sizes if they are valid, otherwise uses default parameters.
 *
 * @note This function should be called before using any other operations on the doubly linked list.
 * @warning Ensure that elem_size and list_size are valid and within acceptable limits.
 *
 */
dLL MyDLLInit(uint16_t elem_size, uint16_t list_size, uint16_t order);

/**
 * \brief Inserts a new node with the specified ID and element into the doubly linked list.
 * 
 * This function inserts a new node with the given ID and element into the doubly linked list.
 *
 * @param[in] list Pointer to the DLL where the node is being inserted to.
 * @param[in] id The unique identifier for the new node.
 * @param[in] element String value to be stored in the new node.
 *
 * @return 0 if the insertion is successful, -1 if the insertion fails (e.g., due to duplicate ID or no more space).
 *
 * @note The function returns 0 on successful insertion, and -1 if the insertion fails.
 * @warning Ensure that the provided ID is unique within the doubly linked list.
 * 
 */
uint16_t MyDLLInsert(dLL *list, uint16_t id, unsigned char *element);

/**
 * @brief Removes a node with the specified ID from the doubly linked list.
 * 
 * This function removes a node with the given ID from the doubly linked list and returns 
 * the data element (string value) of the removed node.
 *
 * @param[in] list Pointer to the DLL where the node is being removed from.
 * @param[in] id The unique identifier of the node to be removed.
 * 
 * @return Pointer to the data element of the removed node, or NULL if the node is not found.
 * 
 * @note The returned pointer is the data element of the removed node.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.  
 *
 */
unsigned char *MyDLLRemove(dLL *list,uint16_t id);

/**
 * @brief Finds the data element of a node with the specified ID in the doubly linked list.
 *
 * This function searches for a node with the given ID in the doubly linked list and returns
 * the data element (string value) of the found node.
 *
 * @param[in] list Pointer to the DLL where the node is being inserted to.
 * @param[in] id The unique identifier of the node to be found.
 * 
 * @return Pointer to the data element of the found node, or NULL if the node is not found.
 *
 * @note The returned pointer points to the data element of the found node.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFind(dLL *list,uint16_t id);

/**
 * @brief Finds the data element of the next node after the specified ID in the doubly linked list.
 *
 * This function searches for the node with the given ID in the doubly linked list and returns
 * the data element (string value) of the node that comes after it.
 *
 * @param[in] list Pointer to the DLL where the node is.
 * @param[in] id The unique identifier of the current node.
 *
 * @return Pointer to the data element of the next node, or NULL if the next node is not found.
 *
 * @note The returned pointer points to the data element of the node that comes after the given ID.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFindNext(dLL *list,uint16_t id);

/**
 * @brief Finds the data element of the previous node before the specified ID in the doubly linked list.
 *
 * This function searches for the node with the given ID in the doubly linked list and returns
 * the data element (string value) of the node that comes before it.
 *
 * @param[in] list Pointer to the DLL where the node is.
 * @param[in] id The unique identifier of the current node.
 *
 * @return Pointer to the data element of the previous node, or NULL if the previous node is not found.
 *
 * @note The returned pointer points to the data element of the node that comes before the given ID.
 * @warning Ensure that the provided ID corresponds to an existing node in the doubly linked list.
 *
 */
unsigned char *MyDLLFindPrevious(dLL *list,uint16_t id);

/**
 * @brief Prints the node in the position i
 *
 * This funtion prints all the information of the node in the position i
 *
 * @param[in] list Pointer to the DLL where the node is.
 * @param[in] i The position of the node in the array alocator.
 *
 */
void MyDLLPrintNode(dLL *list,uint16_t i);

/**
 * @brief Prints information about the head node of the doubly linked list.
 *
 * This function prints details about the node at the head of the doubly linked list,
 * including its unique identifier and data element.
 * 
 * @param[in] list Pointer to the DLL from which the head is being printed.
 *
 * @note This function is intended for debugging and informational purposes.
 * @warning Ensure that the doubly linked list is not empty before calling this function.
 * 
 */
void MyDLLPrintHead(dLL *list);

/**
 * @brief Prints information about all nodes in the doubly linked list.
 *
 * This function iterates through the entire doubly linked list and prints details
 * about each node, including unique identifiers and data elements.
 * 
 * @param[in] list Pointer to the DLL being printed.
 *
 * @note This function is intended for debugging and informational purposes.
 * @warning Ensure that the doubly linked list is not empty before calling this function.
 *
 */
void MyDLLPrintAllList(dLL *list);

/**
 * @brief Increases the size capacity of the doubly linked list.
 *
 * This function increments the size capacity of the doubly linked list by the specified amount.
 * 
 * @param[in] list Pointer to the DLL from which the size is being increased.
 * @param[in] size_increment The amount by which to increase the size capacity of the list.
 *
 * @note Use this function when you need to increase the capacity of the doubly linked list.
 * @warning Ensure that the size_increment value is valid and within acceptable limits.
 *
 */
void MyDLLSizeIncrease(dLL *list, uint16_t size_increment);

/**
 * @brief Increases the maximum element size of the doubly linked list.
 *
 * This function increments the maximum element size of the doubly linked list by the specified amount.
 * 
 * @param[in] list Pointer to the DLL from which the element size is being increased.
 * @param[in] size_increment The amount by which to increase the maximum element size of the list.
 *
 * @note Use this function when you need to increase the maximum element size of the doubly linked list.
 * @warning Ensure that the size_increment value is valid and within acceptable limits.
 *
 */
void MyDLLElementSizeIncrease(dLL *list, uint16_t size_increment);

/**
 * @brief Prints statistics about the doubly linked list, including list size and element size.
 *
 * This function prints various statistics about the doubly linked list,
 * maximum size, and maximum element size.
 * 
 * @param[in] list Pointer to the DLL from which the statistics are being printed.
 *
 * @note This function is intended for debugging and informational purposes.
 * @warning Ensure that the doubly linked list is properly initialized before calling this function.
 *
 */
void MyDLLPrintStats(dLL *list);

#endif
//EOF
