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
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode *dummy = new ListNode();
		ListNode *tail = dummy;

		while (list1 != NULL && list2 != NULL) {
			if (list1->val <= list2->val) {
				tail->next = list1;
				list1 = list1->next;
			} else {
				tail->next = list2;
				list2 = list2->next;
			}
			tail = tail->next;
		}

		if (list1 != NULL) {
			tail->next = list1;
		} else if (list2 != NULL) {
			tail->next = list2;
		}

		return (dummy->next);
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *res = NULL;
		for (int i = 0; i < lists.size(); i += 2) {
			ListNode *newList = lists[i];
			if (i < lists.size() - 1) {
				newList = mergeTwoLists(lists[i], lists[i + 1]);
			}
			res = mergeTwoLists(res, newList);
		}
		return (res);
	}
};