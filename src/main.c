#include "linked_list.h"

#define ARRAY_LEN(arr) sizeof(arr)/sizeof(arr[0])

void linked_list_test(void) {
  List* list = NewList();
  const int arr[] = {4, 3, 2, 12};
  for(size_t i = 0; i < ARRAY_LEN(arr); i++) {
    AddNodeStart(list, arr[i]);
  }
  const int arr2[] = {10, 15, 12, 15};
  for(size_t i = 0; i < ARRAY_LEN(arr); i++) {
    AddNodeEnd(list, arr2[i]);
  }
  PrettyPrintList(list);
  printf("%s\n", IsListData(list, 50) ? "true" : "false");
  printf("%s\n", IsListData(list, 100) ? "true" : "false");
  if (!RemoveNode(list, 4)) printf("Index out of bounds\n");
  PrettyPrintList(list);
  if (!RemoveNode(list, 20)) printf("Index too large\n");
  if (!RemoveNode(list, 4)) printf("Index too large\n");
  if (!RemoveNode(list, 4)) printf("Index too large\n");
  PrettyPrintList(list);
  if (!RemoveNode(list, 0)) printf("Index too large\n");
  PrettyPrintList(list);

  Package temp = SearchList(list, 2);
  if(temp.ok) {
    printf("%d\n", temp.data);
  }
}

int main(void) {
  linked_list_test();
  return 0;
}