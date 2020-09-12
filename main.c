#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "queue.h"
#include "tree.h"
extern double* averageOfLevels(struct TreeNode* root, int* returnSize);

int test637() {
    int treeList[] = {3, 9, 20, -1, -1, 15, 7};
    int len = ElEMLEN(treeList);
    struct TreeNode* root = treeInit(treeList, len);
    int retSize = 0;
    double* retVals = averageOfLevels(root, &retSize);
    return 0;
}

int main(int argc, char const* argv[]) {
    test637();
    return 0;
}
