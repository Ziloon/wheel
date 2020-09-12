#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

QUEUE *queueInit(int len) {
    COND(len > 0, NULL);
    QUEUE *ret = (QUEUE *)malloc(sizeof(QUEUE));
    COND(ret != NULL, NULL);
    ret->data = (void **)malloc(sizeof(void *) * len);
    ret->head = 0;
    ret->tail = 0;
    // [head , tail)
    ret->len = 0;
    ret->maxLen = len;
    return ret;
}
BOOL queueIsEmpty(QUEUE *q) {
    COND(q != NULL, FALSE);
    if (q->len == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}
BOOL queueIsFull(QUEUE *q) {
    COND(q != NULL, FALSE);
    if (q->len >= q->maxLen) {
        return TRUE;
    } else {
        return FALSE;
    }
}
BOOL queueOffer(QUEUE *q, void *e) {
    COND(e != NULL, FALSE);
    COND(q != NULL, FALSE);
    if (queueIsFull(q)) {
        return FALSE;
    }
    q->data[q->tail] = e;
    q->tail = (q->tail + 1) % q->maxLen;
    q->len++;
    return TRUE;
}
int queueLen(QUEUE *q) {
    COND(q != NULL, 0);
    return q->len;
}
void *queuePoll(QUEUE *q) {
    COND(q != NULL, NULL);
    COND(queueIsEmpty(q) == FALSE, NULL);
    void *re = q->data[q->head];
    q->head = (q->head + 1) % q->maxLen;
    q->len--;
    return re;
}