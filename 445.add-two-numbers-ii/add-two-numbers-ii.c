/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseTwoNumbers(struct ListNode* l) {
    struct ListNode* cur = l, *pre = NULL;
    
    while (cur) {
        struct ListNode* t = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = t;
    }
    
    return pre;
}

struct ListNode* append(struct ListNode* x, int val) {
    struct ListNode* t = malloc(sizeof(struct ListNode));
    t -> val = val; t -> next = x;

    return t;
}
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* rev_l1 = reverseTwoNumbers(l1), *rev_l2 = reverseTwoNumbers(l2);
    struct ListNode* ans = NULL;
    
    struct ListNode* cur1 = rev_l1, *cur2 = rev_l2;
    int preadd = 0;
    while (cur1 || cur2 || preadd) {
        int bit = cur1?
                    cur2?
                        (cur1 -> val + cur2 -> val + preadd)
                        :
                        (cur1 -> val + preadd)
                    :
                    cur2?
                        (cur2 -> val + preadd)
                        :
                        (preadd);
        ans = append(ans, bit % 10);
        preadd = bit / 10;
        cur1 = cur1?cur1 -> next:NULL;
        cur2 = cur2?cur2 -> next:NULL;
    }
    
    reverseTwoNumbers(rev_l1);
    reverseTwoNumbers(rev_l2);
    
    return ans;
}