#include "common.h"

#ifndef __TREE_H__
#define __TREE_H__

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *treeInit(int treeList[], int treeLen);

#endif  //__TREE_H__