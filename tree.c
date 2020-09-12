#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

struct TreeNode* createNode(int e) {
    if (e < 0) {
        return NULL;
    }
    struct TreeNode* rt = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (rt == NULL) {
        return NULL;
    }
    rt->val = e;
    rt->left = NULL;
    rt->right = NULL;
    return rt;
}

void destroyNode(struct TreeNode* n) {
    if (n != NULL) {
        destroyNode(n->left);
        destroyNode(n->right);
        free(n);
        n = NULL;
    }
    return;
}

struct TreeNode* treeInit(int treeList[], int treeLen) {
    if (treeList == NULL || treeLen <= 0) {
        return NULL;
    }
    struct TreeNode* nodeList[treeLen];
    for (int nodeIdx = 0; nodeIdx < treeLen; nodeIdx++) {
        nodeList[nodeIdx] = NULL;
    }
    struct TreeNode* cur = NULL;
    for (int listIdx = 0; listIdx < treeLen; listIdx++) {
        cur = createNode(treeList[listIdx]);
        if (cur == NULL) {
            continue;
        }
        nodeList[listIdx] = cur;
        if (listIdx == 0) {
            continue;
        }
        int parentIdx = (listIdx - 1) / 2;
        if (nodeList[parentIdx] == NULL) {
            destroyNode(cur);
            return nodeList[0];
        }
        if ((listIdx & 0x1) == 1) {
            // left node
            nodeList[parentIdx]->left = cur;
        } else {
            // right node
            nodeList[parentIdx]->right = cur;
        }
    }
    return nodeList[0];
}
