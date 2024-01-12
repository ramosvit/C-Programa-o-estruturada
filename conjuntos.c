#include "conjuntos.h"
#include <stdlib.h>

LinkedNode* cria_conjunto(int *v, int n) {
    if (n == 0 || v == NULL) return NULL;

    LinkedNode *head = (LinkedNode*)malloc(sizeof(LinkedNode));
    head->data = v[0];
    head->next = NULL;
    
    LinkedNode *tail = head;

    for (int i = 1; i < n; i++) {
        LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
        new_node->data = v[i];
        new_node->next = NULL;
        
        tail->next = new_node;
        tail = new_node;
    }

    return head;
}

int pertence(LinkedNode* c, int v) {
    while (c != NULL) {
        if (c->data == v) return 1;
        c = c->next;
    }
    return 0;
}

int cardinalidade(LinkedNode *c) {
    int count = 0;
    while (c != NULL) {
        count++;
        c = c->next;
    }
    return count;
}

LinkedNode *uniao(LinkedNode *c1, LinkedNode *c2) {
    LinkedNode *result = NULL;
    LinkedNode *tail = NULL;

    while (c1 != NULL) {
        if (!pertence(result, c1->data)) {
            LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
            new_node->data = c1->data;
            new_node->next = NULL;

            if (result == NULL) {
                result = new_node;
                tail = result;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        c1 = c1->next;
    }

    while (c2 != NULL) {
        if (!pertence(result, c2->data)) {
            LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
            new_node->data = c2->data;
            new_node->next = NULL;

            if (result == NULL) {
                result = new_node;
                tail = result;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        c2 = c2->next;
    }

    return result;
}

LinkedNode *interseccao(LinkedNode *c1, LinkedNode *c2) {
    LinkedNode *result = NULL;
    LinkedNode *tail = NULL;

    while (c1 != NULL) {
        if (pertence(c2, c1->data) && !pertence(result, c1->data)) {
            LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
            new_node->data = c1->data;
            new_node->next = NULL;

            if (result == NULL) {
                result = new_node;
                tail = result;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        c1 = c1->next;
    }

    return result;
}

LinkedNode *diferenca(LinkedNode *c1, LinkedNode *c2) {
    LinkedNode *result = NULL;
    LinkedNode *tail = NULL;

    while (c1 != NULL) {
        if (!pertence(c2, c1->data) && !pertence(result, c1->data)) {
            LinkedNode *new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
            new_node->data = c1->data;
            new_node->next = NULL;

            if (result == NULL) {
                result = new_node;
                tail = result;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
        c1 = c1->next;
    }

    return result;
}