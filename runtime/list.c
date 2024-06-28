#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct list {
    int64_t head;
    struct list* tail;
} list

#define S sizeof(struct list)

;
struct list* makeList (int64_t v) {
    struct list* l = malloc(S);
    l->head = v;
    l->tail = NULL;
    return l;
}

struct list* cons (int64_t h, int64_t count, ...) {
    struct list* l = malloc(S);
    l->head = h;
    l->tail = NULL;
    printf("Hello world %li \n", count);
    va_list args;
    va_start(args, count);

    int64_t arg;
    struct list* current = l;
    for (int64_t i = 0; i < count; i++) {
        int64_t arg = va_arg(args, int64_t);
        // printf("Hello world %li \n", arg);
        current->tail = malloc(S);
        current = current->tail;
        current->head = arg;
    }

    va_end(args);
    return l;
}

int64_t hd (struct list* l) {
    return l->head;
}

struct list* tl (struct list* l) {
    if (l->tail == NULL) {
        return cons(0L, 0L);
    } else {
        return l->tail;
    }
}
/* A list is empty when the head is 0 and the tail is NULL or [] */
int64_t empty (struct list* l) {
    if (l == NULL) {
        return 1;  // Assume that an uninitialized list is empty
    }
    return l->head == 0 && l->tail == NULL;
}
