/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  struct TreeLinkNode *left, *right, *next;
 * };
 *
 */
void connect(struct TreeLinkNode *root) {
    struct TreeLinkNode *cur = root, *f = NULL;
    if (root) root -> next = NULL;
    
    while (cur) {
        if ((cur -> left) && (f == NULL)) f = cur -> left;
        if (cur -> left) cur -> left -> next = cur -> right;
        if (cur -> right) cur -> right -> next = cur -> next?cur -> next -> left:NULL;
        if (cur -> next) cur = cur -> next;
        else {cur = f; f = NULL;}
    }
}