#include "unity.h"
#include "LinkedList.h"

void setUp(void)  {}

void tearDown(void) {}

/** test linkListNew()
 ** Create a new list for linkedList and return the linkList pointer
 **/
void test_linkListNew_should_add_list_into_LinkedList(void) {
  char *name = "LinkList";
  LinkedList *link = linkListNew(name);

  TEST_ASSERT_NOT_NULL(link);
  char *result = (char*)link->data;
  TEST_ASSERT_EQUAL_STRING("LinkList", result);
  TEST_ASSERT_NULL(link->next);

  destroyAllLinkedLists(link);
}

/** test addLinkedList()
 ** Given one created newList should add into LinkedList
 *
 *       Head               Head            
 *        V                  V              
 *    +---------+        +---------+    +---------+
 *   |   NULL   |  ---> | newList  |-> |   NULL   |
 *   +---------+        +---------+    +---------+
 **/
void test_addLinkedList_should_add_created_list_into_LinkedList(void) {
  char *name = "YOLO~";
  LinkedList *head = NULL;
  LinkedList *newList = linkListNew(name);

  printf("Start test_addLinkedList_should_add_created_list_into_LinkedList\n");
  addLinkedList(&head, newList);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NULL(head->next);

  char *result = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("YOLO~", result);
  destroyAllLinkedLists(head);
}


/** test addLinkedList()
 ** Given two created newList should add into LinkedList
 *
 *       Head
 *        V
 *    +---------+
 *   |   NULL   |
 *   +---------+
 *
 *      Head            
 *       V              
 *   +---------+    +---------+
 *   |   IM    | -> |  NULL   |
 *   +---------+    +---------+
 *
 *      Head                           
 *       V                             
 *   +---------+    +---------+    +---------+
 *   |   IM    | -> |  JUST   | -> |  LIST   |  ->  NULL
 *   +---------+    +---------+    +---------+
 **/
void test_addLinkedList_should_add_two_created_list_into_LinkedList(void) {
  char *name1 = "IM";
  char *name2 = "JUST";
  char *name3 = "LIST";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);

  printf("Start test_addLinkedList_should_add_created_list_into_LinkedList\n");

  addLinkedList(&head, list1);

  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NULL(head->next);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("IM", result1);

  addLinkedList(&head, list2);
  TEST_ASSERT_NOT_NULL(head->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("JUST", result2);

  addLinkedList(&head, list3);
  TEST_ASSERT_NOT_NULL(head->next->next);
  char *result3 = (char*)head->next->next->data;
  TEST_ASSERT_EQUAL_STRING("LIST", result3);

  TEST_ASSERT_NULL(head->next->next->next);

  printf("----------------------------------------------------------------");

  destroyAllLinkedLists(head);
}

/*
 *      Head
 *       V
 *   +---------+     +---------+    +---------+     +---------+    +---------+
 *   |   IM    | -> |   JUST   | -> |  LIST   | ->  |   ADD   | -> |  DUMMY  | -> NULL
 *   +---------+    +---------+     +---------+     +---------+    +---------+
 **/
void test_addLinkedList_should_add_5_created_list_into_LinkedList(void) {
  char *name1 = "WHY";
  char *name2 = "SO";
  char *name3 = "SERIOUS";
  char *name4 = "ADD";
  char *name5 = "DUMMY";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);
  LinkedList *list4 = linkListNew(name4);
  LinkedList *list5 = linkListNew(name5);

  printf("Start test_addLinkedList_should_add_created_list_into_LinkedList\n");

  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  addLinkedList(&head, list4);
  addLinkedList(&head, list5);

  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NOT_NULL(head->next);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("WHY", result1);

  TEST_ASSERT_NOT_NULL(head->next->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("SO", result2);

  TEST_ASSERT_NOT_NULL(head->next->next->next);
  char *result3 = (char*)head->next->next->data;
  TEST_ASSERT_EQUAL_STRING("SERIOUS", result3);

  TEST_ASSERT_NOT_NULL(head->next->next->next->next);
  char *result4 = (char*)head->next->next->next->data;
  TEST_ASSERT_EQUAL_STRING("ADD", result4);

  TEST_ASSERT_NULL(head->next->next->next->next->next);
  char *result5 = (char*)head->next->next->next->next->data;
  TEST_ASSERT_EQUAL_STRING("DUMMY", result5);

  printf("----------------------------------------------------------------");

  destroyAllLinkedLists(head);
}

/** test int compare(void *dataInCollection, void *targetData)
 ** Given 2 completely equal string should return 1
 **/
void test_compare_given_2_completely_equal_string_should_return_1(void) {
  char *name1 = "YOLO";
  char *name2 = "YOLO";
  int result = 0;

  printf("Start test_compare_given_2_completely_equal_string_should_return_1\n");
  result = compareChar(name1, name2);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_EQUAL(1, result);
}

/** test int compare(void *dataInCollection, void *targetData)
 ** Given 2 different string should return 0
 **/
void test_compare_given_2_different_string_should_return_0(void) {
  char *name1 = "BYE";
  char *name2 = "HI";
  int result = 0;

  printf("Start test_compare_given_2_different_string_should_return_0\n");
  result = compareChar(name1, name2);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_EQUAL(0, result);
}

/** test findLinkedList
 ** Given targetName "newName" should return 1
 **/
void test_findLinkedList_given_targetName_newName_should_return_1(void) {
  char *name = "newName";
  char *target = "newName";
  int result;
  LinkedList *head = NULL;
  LinkedList *newList = linkListNew(name);

  printf("Start test_findLinkedList_given_targetName_newName_should_return_1\n");
  addLinkedList(&head, newList);
  result = isItemInList(&head, target);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_EQUAL(1, result);
  destroyAllLinkedLists(head);
}

/** test findLinkedList
 ** Given targetName "name2" should return 1
 **/
void test_findLinkedList_given_target_name_name2_should_return_1(void) {
  char *name1 = "name1";
  char *name2 = "name2";
  char *name3 = "name3";
  char *target = "name2";
  int result = 0;
  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);

  printf("test_findLinkedList_given_target_name_name2_should_return_1\n");
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  result = isItemInList(&head->next, target);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_EQUAL(1, result);
  destroyAllLinkedLists(head);
}

/** test findLinkedList
 ** Given target name doesnt exist in LinkedList should return 0
 **/
void test_findLinkedList_given_target_name_doesnt_exist_in_LinkedList_should_return_0(void) {
  char *name1 = "Oh";
  char *name2 = "Yeah";
  char *name3 = "Baby~";
  char *target = "What!?";
  int result = 0;
  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);

  printf("test_findLinkedList_given_target_name_doesnt_exist_in_LinkedList_should_return_0\n");
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  result = isItemInList(&head, target);
  printf("----------------------------------------------------------------");

  TEST_ASSERT_EQUAL(0, result);
  destroyAllLinkedLists(head);
}

/*  Remove At Head
 *
 *      Head
 *       V
 *      NULL
 *
 **/
void test_removeHeadList_shouldnt_remove_because_list_is_empty(void) {
  char *name1 = "IAmNothing";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);

  printf("test_removeHeadList_shouldn't_remove_because_list_is_empty\n");
  //Find & remove here
  removeHeadList(&head, list1);

  TEST_ASSERT_NULL(head);
  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

/*  Remove At Head
 *      Head
 *       V
 *   +------+
 *   | XMAN | -> NULL
 *   +------+
 *
 *      Head
 *       V
 *      NULL
 *
 **/
void test_removeHeadList_should_remove_head_in_List_and_point_to_NULL(void) {
  char *name1 = "XMAN";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);

  printf("test_removeLinkedList_should_remove_XMAN_in_List\n");
  //Add List here
  addLinkedList(&head, list1);

  TEST_ASSERT_NOT_NULL(head);
  TEST_ASSERT_NULL(head->next);
  char *result = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("XMAN", result);

  //Find & remove here
  removeHeadList(&head, list1);

  TEST_ASSERT_NULL(head);
  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

/*  Remove At Head
 *      Head
 *       V
 *   +---------+    +--------+
 *   | WARRIOR | -> | ARCHER | -> NULL
 *   +---------+    +--------+
 *
 *     Head
 *      V
 *  +--------+
 *  | ARCHER | -> NULL
 *  +--------+
 **/
void test_removeHeadList_should_remove_WARRIOR_and_point_to_ARCHER(void) {
  char *name1 = "WARRIOR";
  char *name2 = "ARCHER";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);

  printf("test_removeHeadList_should_remove_WARRIOR_and_point_to_ARCHER\n");
  //Add List here
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);

  //Find & remove here
  removeHeadList(&head, list1);

  TEST_ASSERT_NOT_NULL(head);
  char *result = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("ARCHER", result);
  TEST_ASSERT_NULL(head->next);
  
  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

/*  Remove At Body
 *      Head                               Tail
 *       V                                  V
 *   +----------+    +----------+    +------------+
 *   | SUPERMAN | -> |  BATMAN  | -> |  ULTRAMAN  |  ->  NULL
 *   +----------+    +----------+    +------------+
 *
 *      Head              Tail
 *       V                 V
 *   +----------+    +------------+
 *   | SUPERMAN | -> |  ULTRAMAN  |  ->  NULL
 *   +----------+    +------------+
 **/
void test_removeLinkedList_should_remove_BATMAN_in_List(void) {
  char *name1 = "SUPERMAN";
  char *name2 = "BATMAN";
  char *name3 = "ULTRAMAN";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);

  printf("test_removeLinkedList_should_remove_BATMAN_in_List\n");
  //Add List here
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);

  //Find & remove here
  removeLinkedList(&head, list2);

  TEST_ASSERT_NOT_NULL(head);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("SUPERMAN", result1);

  TEST_ASSERT_NOT_NULL(head->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("ULTRAMAN", result2);

  TEST_ASSERT_NULL(head->next->next);

  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

/*  Remove At Tail
 *      Head                                                
 *       V                                                  
 *   +----------+    +----------+    +------------+     +------------+
 *   | SUPERMAN | -> |  BATMAN  | -> |  ULTRAMAN  |  -> |  IamTail   |
 *   +----------+    +----------+    +------------+     +------------+
 *
 *      Head                                                
 *       V                                                  
 *   +----------+    +----------+    +------------+     
 *   | SUPERMAN | -> |  BATMAN  | -> |  ULTRAMAN  |  -> NULL
 *   +----------+    +----------+    +------------+     
 **/
void test_removeLinkedList_should_remove_IamTail_in_List(void) {
  char *name1 = "SUPERMAN";
  char *name2 = "BATMAN";
  char *name3 = "ULTRAMAN";
  char *name4 = "IamTail";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);
  LinkedList *list4 = linkListNew(name4);

  printf("test_removeLinkedList_should_remove_IamTail_in_List\n");
  //Add List here
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  addLinkedList(&head, list4);

  //Find & remove here
  removeLinkedList(&head, list4);

  TEST_ASSERT_NOT_NULL(head);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("SUPERMAN", result1);

  TEST_ASSERT_NOT_NULL(head->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("BATMAN", result2);

  TEST_ASSERT_NOT_NULL(head->next->next);
  char *result3 = (char*)head->next->next->data;
  TEST_ASSERT_EQUAL_STRING("ULTRAMAN", result3);

  TEST_ASSERT_NULL(head->next->next->next);

  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

void test_removeLinkedList_should_remove_list_in_sequence_2_1_4_3_expect_head_to_NULL(void) {
  char *name1 = "SUPERMAN";
  char *name2 = "BATMAN";
  char *name3 = "ULTRAMAN";
  char *name4 = "IamTail";

  LinkedList *head = NULL;
  LinkedList *list1 = linkListNew(name1);
  LinkedList *list2 = linkListNew(name2);
  LinkedList *list3 = linkListNew(name3);
  LinkedList *list4 = linkListNew(name4);

  printf("test_removeLinkedList_should_remove_IamTail_in_List\n");
  //Add List here
  addLinkedList(&head, list1);
  addLinkedList(&head, list2);
  addLinkedList(&head, list3);
  addLinkedList(&head, list4);

  //Remove List 2
  removeLinkedList(&head, list2);
  TEST_ASSERT_NOT_NULL(head);
  char *result1 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("SUPERMAN", result1);
  
  TEST_ASSERT_NOT_NULL(head->next);
  char *result2 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("ULTRAMAN", result2);
  
  TEST_ASSERT_NOT_NULL(head->next->next);
  char *result3 = (char*)head->next->next->data;
  TEST_ASSERT_EQUAL_STRING("IamTail", result3);
  TEST_ASSERT_NULL(head->next->next->next);

  //Remove List 1
  removeLinkedList(&head, list1);
  TEST_ASSERT_NOT_NULL(head);
  char *result4 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("ULTRAMAN", result4);
  
  TEST_ASSERT_NOT_NULL(head->next);
  char *result5 = (char*)head->next->data;
  TEST_ASSERT_EQUAL_STRING("IamTail", result5);
  TEST_ASSERT_NULL(head->next->next);
  
  //Remove list 4
  removeLinkedList(&head, list4);
  TEST_ASSERT_NOT_NULL(head);
  char *result6 = (char*)head->data;
  TEST_ASSERT_EQUAL_STRING("ULTRAMAN", result6);
  TEST_ASSERT_NULL(head->next);
  
  //Remove list 3
  removeLinkedList(&head, list3);
  TEST_ASSERT_NULL(head);

  printf("----------------------------------------------------------------");
  destroyAllLinkedLists(head);
}

void test_findAndReturnItemInList_find_RockU_in_list_should_return_listA(void) {
  char *name1 = "RockU";
  
  LinkedList *result = NULL;
  LinkedList *head = NULL;
  LinkedList *listA = linkListNew(name1);

  printf("test_findAndReturnItemInList_find_RockU_in_list_should_return_listA\n");
  addLinkedList(&head, listA);
  
  result = findAndReturnItemInList(&head, "RockU");
  printf("----------------------------------------------------------------");

  TEST_ASSERT_NOT_NULL(result);
  char *resultA = (char*)result->data;
  TEST_ASSERT_EQUAL_STRING("RockU", resultA);
  TEST_ASSERT_NULL(result->next);
  
  destroyAllLinkedLists(head);
}

void test_findAndReturnItemInList_find_Bacon_in_list_should_return_listB(void) {
  char *name1 = "RockU";
  char *name2 = "Bacon";
  char *name3 = "PorkBelly";
  
  LinkedList *result = NULL;
  LinkedList *head = NULL;
  LinkedList *listA = linkListNew(name1);
  LinkedList *listB = linkListNew(name2);
  LinkedList *listC = linkListNew(name3);

  printf("test_findAndReturnItemInList_find_Bacon_in_list_should_return_listB\n");
  addLinkedList(&head, listA);
  addLinkedList(&head, listB);
  addLinkedList(&head, listC);
  
  result = findAndReturnItemInList(&head, "Bacon");
  printf("----------------------------------------------------------------");

  TEST_ASSERT_NOT_NULL(result);
  char *resultA = (char*)result->data;
  TEST_ASSERT_EQUAL_STRING("Bacon", resultA);
  TEST_ASSERT_NOT_NULL(result->next);
  
  destroyAllLinkedLists(head);
}

void test_findAndReturnItemInList_find_Sashimi_in_list_should_return_NULL(void) {
  char *name1 = "RockU";
  char *name2 = "Bacon";
  char *name3 = "PorkBelly";
  char *name4 = "Beef";
  char *name5 = "BeefStick";
  
  LinkedList *result = NULL;
  LinkedList *head = NULL;
  LinkedList *listA = linkListNew(name1);
  LinkedList *listB = linkListNew(name2);
  LinkedList *listC = linkListNew(name3);
  LinkedList *listD = linkListNew(name4);
  LinkedList *listE = linkListNew(name5);

  printf("test_findAndReturnItemInList_find_Sashimi_in_list_should_return_NULL\n");
  addLinkedList(&head, listA);
  addLinkedList(&head, listB);
  addLinkedList(&head, listC);
  addLinkedList(&head, listD);
  addLinkedList(&head, listE);
  
  result = findAndReturnItemInList(&head, "Sashimi");
  printf("----------------------------------------------------------------");

  TEST_ASSERT_NULL(result);
  
  destroyAllLinkedLists(head);
}