/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur_1 = headA, *cur_2 = headB;
	if( NULL==headA || NULL==headB )
		return NULL;
    while (cur_1 != cur_2) {
        cur_1 = cur_1 -> next;
        if (cur_1 == NULL) cur_1 = headA;
        cur_2 = cur_2 -> next;
        if (cur_2 == NULL) cur_2 = headB;
        if (cur_1==headA && cur_2==headB) return NULL;
    }
    return cur_1;
}