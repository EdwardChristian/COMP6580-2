#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct Node {
    int64_t head;
    struct List* tail;
} Node;

typedef struct List {
    Node* node;
} List;

List* makeList(int64_t hd) {
    List* list = (List*) malloc(sizeof(List));
    list->node->head = hd;
    list->node->tail = NULL;
    return list;
}

Node* cons(int64_t head, int64_t tail) {
    List* list = (List*) malloc(sizeof(List));
    Node* node = (Node*) malloc(sizeof(Node));
    node->head = head;
    node->tail = tail;
    list->node = node;
    return node;
}

int64_t hd(List* list) {
    if (list->node != NULL) {
        return list->node->head;
    } else {
        printf("Error: List is empty\n");
        exit(1);
    }
}

List* tl(List* list) {
    if (list->node != NULL) {
        return list->node->tail;
    } else {
        printf("Error: List is empty\n");
        exit(1);
    }
}

int empty(List* list) {
    return list->node == NULL || (list->node->head == 0L && list->node->tail == NULL);
}