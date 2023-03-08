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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *dummy = new ListNode(0, head);
		ListNode *ptr = dummy;
		while (ptr->next != NULL && ptr->next->next != NULL) {
			if (ptr->next->val == ptr->next->next->val) {
				ListNode *dup = ptr->next->next;
				while (dup->next != NULL && dup->val == dup->next->val) {
					dup = dup->next;
				}
				ptr->next = dup->next;
			} else {
				ptr = ptr->next;
			}
		}
		return (dummy->next);
	}
};