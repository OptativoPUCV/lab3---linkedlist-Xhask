#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* list=(List*) malloc (sizeof (List));
  list -> head = NULL;
  list -> tail = NULL;
  list -> current = NULL;
  return list;
  
}

void * firstList(List * list) {
  list -> current = list -> head;
  if (list -> current) return list -> current -> data;
    return NULL;
}

void * nextList(List * list) {
  if (list -> current != NULL)
    list -> current = list -> current -> next;
  if (list -> current != NULL)
    return list -> current -> data;
  else return NULL;
}

void * lastList(List * list) {
  
  list -> current = list -> tail;
  if (list -> current) return list -> current -> data;
  return NULL;
}

void * prevList(List * list) {
  if (list -> current != NULL)
  {
    list -> current = list -> current -> prev;
  }
  if (list -> current != NULL)
    return list -> current -> data;
  else return NULL;
}

void pushFront(List * list, void * data) {
  Node * new = createNode(data);
  if (list -> head == NULL){    
    list -> head = new;
    list -> tail = new;
  }
  else
  {
    new -> next = list -> head;
    list -> head = new;
    list -> tail = new;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * new = createNode(data);
  if (list -> current == NULL)
  {
    list -> head = new;
    list -> tail = new;
  }
  else{
    new -> next = list -> current -> next;
    new -> prev = list -> current;
    list -> current -> next = new;
    if (new -> next != NULL)
      new -> next -> prev = new;
    else
      list -> tail = new;
  }
}


void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}