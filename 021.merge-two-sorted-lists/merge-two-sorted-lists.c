/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ptr1 = l1, *ptr2 = l2, *pre = NULL;
    while (ptr1 && ptr2) {
        if ((ptr1 -> val) < (ptr2 -> val)) {
            struct ListNode* t = ptr1 -> next;
            if (pre) pre -> next = ptr1;
            pre = ptr1;
            ptr1 = t;
        } else {
            struct ListNode* t = ptr2 -> next;
            if (pre) pre -> next = ptr2;
            pre = ptr2;
            ptr2 = t;
        }
    }
    if (ptr1) if (pre) pre -> next = ptr1;
    if (ptr2) if (pre) pre -> next = ptr2;
    
    if (l1 && l2)
        if ((l1 -> val) < (l2 -> val)) return l1;
        else return l2;
    else return l1?l1:l2;
}