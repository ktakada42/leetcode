/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		int n = 0;
		stack<TreeNode*> stack;
		while (true) {
			while (root != NULL) {
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			n++;
			if (n == k) {
				return (root->val);
			}
			root = root->right;
		}
		return (-1);
	}
};