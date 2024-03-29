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
		ListNode *dummy = new ListNode();
		ListNode *current = dummy;
		int carry = 0;
		while (l1 != NULL || l2 != NULL) {
			int val1 = 0, val2 = 0;
			if (l1 != NULL) {
				val1 = l1->val;
			}
			if (l2 != NULL) {
				val2 = l2->val;
			}
			int sum = carry + val1 + val2;
			current->next = new ListNode(sum % 10);
			carry = sum / 10;
			current = current->next;
			if (l1 != NULL) {
				l1 = l1->next;
			}
			if (l2 != NULL) {
				l2 = l2->next;
			}
		}
		if (carry == 1) {
			current->next = new ListNode(1);
		}
		return (dummy->next);
	}
};