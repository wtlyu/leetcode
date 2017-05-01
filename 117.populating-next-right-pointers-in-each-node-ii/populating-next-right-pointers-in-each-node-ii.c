/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *cur = root, *f = NULL, *prenull;
    bool prenullLevel = false;
    if (root) root -> next = NULL;
    
    while (cur) {
        if (prenullLevel) {
            prenullLevel = false;
            if (cur -> left) 
                prenull -> next = cur -> left;
            else if (cur -> right) 
                prenull -> next = cur -> right;
            else
                prenullLevel = true;
        }
        if (f == NULL) {
            if (cur -> left) 
                f = cur -> left;
            else if (cur -> right) 
                f = cur -> right;
        } 
        if (cur -> left) {
            cur -> left -> next = cur -> right;
            if (cur -> left -> next == NULL) {
                prenull = cur -> left;
                prenullLevel = true;
            }
        }
        if (cur -> right) {
            if (cur -> right -> next == NULL) {
                prenull = cur -> right;
                prenullLevel = true;
            }
        }
        if (cur -> next) cur = cur -> next;
        else {cur = f; f = NULL;prenullLevel = false;}
    }
}