/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* cur0 = head, *cur1 = head?head -> next:NULL, *pre = NULL;
    struct ListNode* ret = cur1?cur1:head;
    while (cur0 && cur1) {
        cur0 -> next = cur1 -> next;
        cur1 -> next = cur0;
        if (pre) pre -> next = cur1;
        pre = cur0;
        cur0 = cur0 -> next;
        cur1 = cur0?cur0 -> next:NULL;
    }
    return ret;
}