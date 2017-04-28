/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* cur = root;
    while (cur) {
        if (((p->val < cur-> val) && (q->val > cur-> val)) || ((p->val > cur-> val) && (q->val < cur-> val)))
            return cur;
        if ((p->val == cur-> val) || (q->val == cur-> val))
            return cur;
        if ((p->val < cur-> val) && (q->val < cur-> val)) 
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    return cur;
}