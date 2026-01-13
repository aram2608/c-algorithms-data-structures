#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

/// @struct Node
/// @brief The linked list node
struct Node {
  int data; /**< The underlying data */
  Node* next; /**< A pointer to the next node */
};

/// @struct List
/// @brief An interface for working with linked lists
typedef struct {
  size_t size; /**< Size of the list */
  Node* head; /**< A pointer to the first node */
} List;

/// @struct Package
/// @brief An interface for retrieving list contents
typedef struct {
  bool ok; /**< A boolean to store a retrieval result */
  int data; /**< The underlying data */
} Package;

/**
 * @brief Creates a new linked list that stores integer data
 * 
 * @return A pointer to the newly created list
 */
List* NewList(void);

/**
 * @brief Pretty prints the list contents
 * @param list A pointer to the list
 */
void PrettyPrintList(List* list);

/**
 * @brief Adds a node to the start of the list
 * @param list A pointer to the list
 * @param data The integer to be added
 */
void AddNodeStart(List* list, int data);

/**
 * @brief Adds a node to the end of the list
 * @param list A pointer to the list
 * @param data The integer to be added
 */
void AddNodeEnd(List* list, int data);

/**
 * @brief Searches the list for a node with a particular "key"
 * 
 * The key is the stored integer in the node.
 * 
 * @param list A pointer to the list
 * @param key The integer you suspect is stored
 * @return Either true or false, depending if the key is found
 */
bool IsListData(List* list, int key);

/**
 * @brief Searches the list for a node with a particular index
 * 
 * A package structure is returned on both successful and unsuccessful retrieval attempts.
 * This small structure allows for interacting with the list without having to
 * retrive the entire node. It stores two fields, .ok and .data. If the data was
 * retrieved the ok will be set to true and if unsuccesful it will be false.
 * 
 * The only access that will result in a failure is a bad index request. This occurs
 * for negative indexes and out of bounds indexes.
 * 
 * Example usage:
 * Package p = SearchList(list, idx);
 * if (p.ok) printf("%d\n", p.ok)
 * 
 * @param list A pointer to the list
 * @param idx The list index
 * @return A package structure, contains a bool and the data if found
 */
Package SearchList(List* list, size_t idx);

/**
 * @brief Searches the list for a node with a particular index
 * 
 * This method is the exact same as SearchList but rather than using indirection
 * and returning a Package, this method returns the Node directly.
 * 
 * This method is preferable when the user wishes to interact with the Node directly.
 * This could be useful when you wish to set the underlying data manually.
 * 
 * @param list A pointer to the list
 * @param idx The list inde
 * @return The located node or NULL.
 */
Node* SearchListNode(List* list, size_t idx);

/**
 * @brief Sets node data at a particular index
 * 
 * Will return false if a bad index request is made.
 * @param list A pointer to the list
 * @param idx The index to be searched
 * @param data The data to be set
 * @return True or false depending on success
 */
bool SetData(List* list, size_t idx, int data);

/**
 * @brief Removes a node given a particular index
 * 
 * Returns true if successful.
 * 
 * @param list A pointer to the list
 * @param idx The index of the node to be removed
 */
bool RemoveNode(List* list, size_t idx);

#endif // LINKED_LIST_H_
