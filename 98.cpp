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
	bool validateSubtree(TreeNode *root, TreeNode *low, TreeNode *high) {
		if (root == NULL) {
			return (true);
		}

		if (low != NULL && root->val <= low->val) {
			return (false);
		}
		if (high != NULL && root->val >= high->val) {
			return (false);
		}

		return (validateSubtree(root->left, low, root) && validateSubtree(root->right, root, high));
	}

	bool isValidBST(TreeNode* root) {
		return (validateSubtree(root, NULL, NULL));
	}
};