#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

struct LinkedList {
  LinkedList *next;
  void *data;
};

#define isItemInList(listPtr, data) findLinkedList(listPtr, data, compareChar)
#define findAndReturnItemInList(listPtr, data)  findItemInList(listPtr, data, compareChar)

LinkedList *linkListNew(void *data);
void addLinkedList(LinkedList **listPtr, LinkedList *newList);
void removeHeadList(LinkedList **listPtr, LinkedList *listToRemove);
void removeLinkedList(LinkedList **listPtr, LinkedList *listToRemove);
void destroyAllLinkedLists(LinkedList *firstList);
int compareChar(void *dataInCollection, void *targetData);
int findLinkedList(LinkedList **listPtr, void *data, int(*compareChar)(void *dataInCollection, void *data));
LinkedList *findItemInList(LinkedList **listPtr, void *data, int(*compareChar)(void *dataInCollection, void *data));
#endif // LinkedList_H


