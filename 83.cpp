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
		ListNode* current = head;
		while (current != NULL && current->next != NULL) {
			ListNode* next = current->next;
			if (current->val == next->val) {
				current->next = next->next;
			} else {
				current = next;
			}
		}
		return (head);
    }
};