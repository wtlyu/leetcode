/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int innerFindBottomLeftValue(struct TreeNode* root, int* level) {
    if (root == NULL) {
        *level = 0;
        return 0;
    }
    if (!(root -> left || root -> right)) {
        *level = 1;
        return root -> val;
    }
    int ans0, ans1, level0, level1;
    ans0 = innerFindBottomLeftValue(root -> left, &level0);
    ans1 = innerFindBottomLeftValue(root -> right, &level1);
    
    if (level0 == level1) {
        *level = level0 + 1;
        return ans0;
    } else if (level0 < level1) {
        *level = level1 + 1;
        return ans1;
    } else {
        *level = level0 + 1;
        return ans0;
    }
}

int findBottomLeftValue(struct TreeNode* root) {
    int level;
    return innerFindBottomLeftValue(root, &level);
}