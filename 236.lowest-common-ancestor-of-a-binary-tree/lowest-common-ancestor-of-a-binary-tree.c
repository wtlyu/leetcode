/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if ((root == NULL) || (root == p) || (root == q)) return root;
    struct TreeNode* ans0 = lowestCommonAncestor(root -> left, p, q);
    struct TreeNode* ans1 = lowestCommonAncestor(root -> right, p, q);
    if (ans0 && (!ans1)) return ans0;
    if ((!ans0) && ans1) return ans1;
    if ((!ans0) && (!ans1)) return NULL;
    return root;
}