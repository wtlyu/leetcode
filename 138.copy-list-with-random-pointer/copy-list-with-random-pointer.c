/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *curptr = head;
    
    while (curptr) {
        struct RandomListNode *newptr = malloc(sizeof(struct RandomListNode));
        newptr -> label = curptr -> label;
        newptr -> next = curptr -> next;
        curptr -> next = newptr;
        curptr = newptr -> next;
    }
    
    curptr = head;
    
    while (curptr) {
        struct RandomListNode *newptr = curptr -> next;
        newptr -> random = curptr -> random?curptr -> random -> next:NULL;
        curptr = newptr -> next;
    }
    
    curptr = head;
    
    struct RandomListNode *t = head?head -> next:NULL;
    
    while (curptr) {
        struct RandomListNode *newptr = curptr -> next;
        
        curptr -> next = newptr -> next?newptr -> next:NULL;
        newptr -> next = newptr -> next?newptr -> next -> next:NULL;
        
        curptr = curptr -> next;
    }
    
    return t;
}