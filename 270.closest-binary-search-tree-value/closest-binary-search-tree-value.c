/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int closestValue(struct TreeNode* root, double target) {
    struct TreeNode* pre_min = root, *pre_max = root, *cur = root;
    while (cur) {
        if (target < (cur->val)) {
            pre_max = cur;
            cur = cur -> left;
        } else if (target > (cur->val)) {
            pre_min = cur;
            cur = cur -> right;
        } else
            return cur -> val;
    }

    if (fabs(target - (pre_min -> val)) < fabs((pre_max -> val) - target))
        return pre_min -> val;
    else 
        return pre_max -> val;
}