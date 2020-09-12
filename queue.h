#include "common.h"

#ifndef __QUEUE_H__
#define __QUEUE_H__

typedef struct {
    void **data;
    int head;
    int tail;
    int len;
    int maxLen;
} QUEUE;

QUEUE *queueInit(int len);
BOOL queueIsEmpty(QUEUE *q);
BOOL queueIsFull(QUEUE *q);
BOOL queueOffer(QUEUE *q, void *e);
int queueLen(QUEUE *q);
void *queuePoll(QUEUE *q);

#endif  // __QUEUE_H__
