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
	void reorderList(ListNode* head) {
		ListNode *slow = head, *fast = head->next;
		while (fast != NULL && fast->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		
		ListNode *second = slow->next;
		ListNode *prev = NULL;
		slow->next = NULL;
		while (second != NULL) {
			ListNode *tmp = second->next;
			second->next = prev;
			prev = second;
			second = tmp;
		}

		second = prev;
		while (second != NULL) {
			ListNode *tmp1 = head->next, *tmp2 = second->next;
			head->next = second;
			second->next = tmp1;
			head = tmp1;
			second = tmp2;
		}
	}
};