#include "linked_list.h"

int main(void) {
  List* list = NewList();
  AddNodeStart(list, 4);
  AddNodeStart(list, 3);
  AddNodeStart(list, 2);
  AddNodeStart(list, 12);
  // AddNodeEnd(list, 10);
  // AddNodeEnd(list, 15);
  AddNodeStart(list, 12);
  AddNodeStart(list, 50);
  // AddNodeEnd(list, 40);
  PrettyPrintList(list);
  printf("%s\n", SearchList(list, 50) ? "true" : "false");
  printf("%s\n", SearchList(list, 100) ? "true" : "false");
  if (!RemoveNode(list, 4)) printf("Index out of bounds\n");
  PrettyPrintList(list);
  if (!RemoveNode(list, 20)) printf("Index too large\n");
  if (!RemoveNode(list, 4)) printf("Index too large\n");
  if (!RemoveNode(list, 4)) printf("Index too large\n");
  PrettyPrintList(list);
  if (!RemoveNode(list, 0)) printf("Index too large\n");
  PrettyPrintList(list);
  return 0;
}