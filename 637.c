#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "queue.h"
#include "tree.h"

#define MAX_LEVEL 5000
double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    COND(returnSize != NULL, NULL);
    *returnSize = 0;
    double* aves = (double*)malloc(sizeof(double) * (MAX_LEVEL));
    aves[0] = 0;
    COND(root != NULL, aves);
    QUEUE* q = queueInit(MAX_LEVEL);
    queueOffer(q, root);
    int level = 0;
    while (queueLen(q)) {
        int innerLen = queueLen(q);
        double innerSum = 0;
        for (int innerId = 0; innerId < innerLen; innerId++) {
            struct TreeNode* cur = (struct TreeNode*)queuePoll(q);
            innerSum += (double)(cur->val);
            queueOffer(q, cur->left);
            queueOffer(q, cur->right);
        }
        double ave = innerSum / innerLen;
        aves[level++] = ave;
        *returnSize = level;
    }
    return aves;
}