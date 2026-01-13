#include "linked_list.h"

List* NewList(void) {
  List* list = (List*) malloc(sizeof(List));
  if (list == NULL) {
    printf("PANIC: Failed to create list\n");
    exit(1);
  }

  list->head = NULL;
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

void PrettyPrintList(List* list) {
  printf("------------\n");
  printf("Linked list data\n");
  Node* p = list->head;
  for (size_t it = 0; it < list->size; ++it) {
    printf("Data: %d --- Index: %zu\n", p->data, it);
    p = p->next;
  }
  printf("------------\n");
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

bool RemoveNode(List* list, size_t idx) {
  if (list->size <= idx || idx < 0) {
    return false;
  }

  Node* prev = list->head;
  if (idx == 0) {
    list->head = prev->next;
    free(prev);
    --list->size;
    return true;
  } else {
    for (size_t it = 0; it < idx - 1; ++it) {
      prev = prev->next;
    }
  }

  Node* forward = list->head;
  for (size_t it = 0; it < idx + 1; ++it) {
    forward = forward->next;
  }

  free(prev->next);
  prev->next = forward;

  --list->size;
  return true;
}
