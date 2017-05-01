/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    if (root == NULL) return true;
    bool ans0 = root -> left?isValidBST(root-> left):true, 
        ans1 = root -> right?isValidBST(root-> right):true;
    if (ans0 && ans1) {
        struct TreeNode* cur = root -> left;
        long long maxc, minc;
        if (cur) {
            while (cur -> right)
                cur = cur -> right;
            maxc = cur -> val;
        } else maxc = (long long)root -> val - 1;
        
        cur = root -> right;
        if (cur) {
            while (cur -> left)
                cur = cur -> left;
            minc = cur -> val;
        } else minc = (long long)root -> val + 1;
        
        if ((maxc < (root -> val)) && (minc > (root -> val))) return true;
    }
    return false;
}