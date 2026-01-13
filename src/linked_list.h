#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
  int data;
  Node* next;
};

typedef struct {
  size_t size;
  Node* head;
} List;

List* NewList(void);

void PrettyPrintList(List* list);

void AddNodeStart(List* list, int data);
void AddNodeEnd(List* list, int data);
bool RemoveNode(List* list, size_t idx);


#endif // LINKED_LIST_H_
