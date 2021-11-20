#include <stdlib.h>
#include <string.h>

#include "list.h"

void list_init(List *list, void (*destroy)(void *data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
}

void list_destroy(List *list) {
    void *data;

    while (list_size(list) > 0) {
        int list_next_removed = list_rem_next(list, NULL, (void**)&data) == 0;

        if (list_next_removed && list->destroy != NULL) {
            list->destroy(data);
        }
    }

    memset(list, 0, sizeof(List)); // Clear the structure
}

int list_ins_next(List *list, Node *node, const void *data) {
    Node *new_node;

    if ((new_node = (Node *) malloc(sizeof(Node))) == NULL) {
        return -1;
    }

    new_node->data = (void *) data;

    // Insert node in list
    if (node == NULL) {
        // Insert in head
        if (list_size(list) == 0) {
            list->tail = new_node;
        }

        new_node->next = list->head;
        list->head = new_node;
    } else {
        // Insert where specified
        if (node->next == NULL) {
            list->tail = new_node;
        }

        new_node->next = node->next;
        node->next = new_node;
    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, Node *node, void **data) {
    Node *node;

    if (list_size(list) == 0) {
        return -1;
    }

    // Remove element from list
    if (node == NULL) {

    }
}
