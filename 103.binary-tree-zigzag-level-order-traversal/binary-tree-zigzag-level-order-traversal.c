/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
void reverse(int *array, int size) {
    for (int i = 0; i < (size >> 1); i ++) {
        int t = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = t;
    }
}
 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode* queue[10000];
    int q = 0, h = 2;
    queue[0] = root;
    queue[1] = NULL;
    if (root == NULL) {
        *returnSize = 0;
        *columnSizes = NULL;
        return NULL;
    }
    *returnSize = 1;
    *columnSizes = malloc(sizeof(int)); (*columnSizes)[0] = 0;
    int **ans = malloc(sizeof(int *)); ans[0] = NULL;
    while (q!=h) {
        struct TreeNode* cur = queue[q]; q = (q + 1) % 10000;
        if (cur) {
            (*columnSizes)[(*returnSize) - 1]++;
            ans[(*returnSize) - 1] = realloc(ans[(*returnSize) - 1], sizeof(int)*(*columnSizes)[(*returnSize) - 1]);
            ans[(*returnSize) - 1][(*columnSizes)[(*returnSize) - 1] - 1] = cur -> val;
            if (cur -> left) { queue[h] = cur -> left; h = (h + 1) % 10000;}
            if (cur -> right) { queue[h] = cur -> right; h = (h + 1) % 10000;}
        } else {
            if (((*returnSize) & 1) == 0) reverse(ans[(*returnSize) - 1], (*columnSizes)[(*returnSize) - 1]);
            if (q == h) break;
            (*returnSize)++;
            (*columnSizes) = realloc((*columnSizes), sizeof(int)*(*returnSize));
            (*columnSizes)[(*returnSize) - 1] = 0;
            ans = realloc(ans, sizeof(int *)*(*returnSize));
            ans[(*returnSize) - 1] = NULL;
            queue[h] = NULL; h = (h + 1) % 10000;
        }
    }
    return ans;
}