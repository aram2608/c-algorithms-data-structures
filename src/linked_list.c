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

List* NewList(int data) {
  List* list = (List*) malloc(sizeof(List));
  if (list == NULL) {
    printf("PANIC: Failed to create list\n");
    exit(1);
  }
  Node* head = (Node*) malloc(sizeof(Node));
  if (head == NULL) {
    printf("PANIC: Failed to create list\n");
    exit(1);
  }
  head->next = NULL;
  head->data = data;
  list->head = head;
  list->size = 0;
  return list;
}

void DestroyList(List* list) {
  while (list->head != NULL) {
    Node* next = list->head->next;
    free(list->head);
    list->head = next;
  }
  free(list);
}

void PrintList(List* list) {
  Node* p = list->head;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}

bool SearchList(List* list, int key) {
  Node* temp = list->head;
  while (temp != NULL) {
    if (temp->data == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void AddNodeStart(List* list, int data) {
  Node* node = (Node*) malloc(sizeof(Node));
  if (node == NULL) {
    printf("PANIC: failed to add new node\n");
    exit(1);
  }
  node->data = data;
  node->next = NULL;

  node->next = list->head;
  list->head = node;
  list->size++;
}

void AddNodeEnd(List* list, int data) {
  Node* current = list->head;
  while (current->next != NULL) {
    current = current->next;
  }

  Node* node = (Node*) malloc(sizeof(Node));
  if (node == NULL) {
    printf("PANIC: failed to add new node\n");
    exit(1);
  }
  node->data = data;
  node->next = NULL;

  current->next = node;
  list->size++;
}

int main(void) {
  List* list = NewList(5);
  AddNodeStart(list, 4);
  AddNodeStart(list, 3);
  AddNodeStart(list, 2);
  AddNodeStart(list, 12);
  AddNodeEnd(list, 10);
  AddNodeEnd(list, 15);
  AddNodeStart(list, 12);
  AddNodeStart(list, 50);
  AddNodeEnd(list, 40);
  PrintList(list);
  return 0;
}
