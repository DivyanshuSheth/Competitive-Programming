/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = new ListNode;
        ListNode * ptr1 = l1, * ptr2 = l2, * ptr_ans = head, * ptr_mistake;
        int carry = 0;
        while (ptr1 != NULL && ptr2 != NULL) {
            ptr_ans->val = ((ptr1->val + ptr2->val + carry) % 10);
            carry = (ptr1->val + ptr2->val + carry) > 9 ? 1 : 0;
            ptr_ans -> next = new ListNode;
            ptr_mistake = ptr_ans;
            ptr_ans = ptr_ans -> next;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        ListNode * continue_ptr;
        if ((ptr1 == NULL) && (ptr2 != NULL)) {
            ptr_ans -> val = ptr2 -> val + carry;
            continue_ptr = ptr2->next;
        }
        else if ((ptr2 == NULL) && (ptr1 != NULL)){
            ptr_ans -> val = ptr1 -> val + carry;
            continue_ptr = ptr1->next;
        }
        else if (carry == 1) {
            ptr_ans -> val = carry;
            ptr_ans -> next = NULL;
            return head;
        }
        else {
            ptr_mistake -> next = NULL;
            return head;
        }
        if (continue_ptr != NULL) {
            ptr_ans -> next = new ListNode;
            ptr_ans = ptr_ans -> next;
        }
        else {
            ptr_ans -> next = NULL;
            return head;
        }
        while(continue_ptr != NULL) {
            ptr_ans -> val = continue_ptr -> val;
            ptr_ans -> next = new ListNode;
            ptr_ans = ptr_ans -> next;
            continue_ptr = continue_ptr -> next;
        }
        ptr_ans = NULL;
        return head;
    }
};
