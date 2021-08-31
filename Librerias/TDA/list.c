#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
    List* lista = (List*) malloc(sizeof(List));
    lista->head = NULL;
    lista->tail = NULL;
    lista->current = NULL;
    return lista;
}

void * firstList(List * list) {
    if(list->head == NULL) return NULL;
    list->current = list->head;
    return (void*) (list->current->data);
}

void * nextList(List * list) {
    if(list->current != NULL && list->current->next != NULL){
        list->current = list->current->next;
        return (void*) (list->current->data);
    }
    else return NULL;
}

void * lastList(List * list) {
    if(list->tail == NULL) return NULL;
    list->current = list->tail;
    return (void*) (list->current->data);
}

void * prevList(List * list) {
    if(list->current != NULL && list->current->prev != NULL){
        list->current = list->current->prev;
        return (void*) (list->current->data);
    }
    return NULL;
}

void pushFront(List * list, const void * data) {
    Node * nuevo = createNode(data);
    nuevo->next = list->head;
    if(list->head){
        list->head->prev = nuevo;
    }
    if(!list->tail){
        list->tail = nuevo;
    }
    list->head = nuevo;
    nuevo->prev = NULL;
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
    Node * nuevo = createNode(data);
    if(!list->current){
        list->head = nuevo;
        list->tail = nuevo;
        list->current = nuevo;
    }
    else if(list->current == list->tail){
        nuevo->prev = list->current;
        list->current->next = nuevo;
        list->tail = nuevo;
        list->current = nuevo;
    }
    else{
        nuevo->prev = list->current;
        Node * aux = list->current->next;
        list->current->next = nuevo;
        nuevo->next = aux;
        aux->prev = nuevo;
        list->current = nuevo;
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
    const void * dato = list->current->data;
    Node* aux;
    if(list->current == list->head){
        aux = list->current->next;
        aux->prev = NULL;
        list->head = aux;
        free(list->current);
        list->current = aux;
    }
    else if(list->current == list->tail){
        aux = list->current->prev;
        aux->next = NULL;
        list->tail = aux;
        free(list->current);
        list->current =aux;
    }
    else{
        aux = list->current->prev;
        aux->next = list->current->next;
        aux = list->current->next;
        aux->prev = list->current->prev;
        free(list->current);
        list->current = aux;
    }
    return (void*) dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}