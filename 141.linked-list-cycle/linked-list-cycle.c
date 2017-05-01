/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *ptr1 = head, *ptr2 = head?head -> next:NULL;
    while (1) {
        if (ptr1 && ptr2) {
            if (ptr1 == ptr2) return true;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next?ptr2 -> next -> next:NULL;
        } else return false;
    }
}