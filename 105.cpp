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
	TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
		if (ps > pe) {
			return (NULL);
		}

		TreeNode *node = new TreeNode(preorder[ps]);
		int pos;
		for (int i = is; i <= ie; i++) {
			if (inorder[i] == node->val) {
				pos = i;
				break ;
			}
		}
		node->left = helper(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
		node->right = helper(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
		return (node);
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return (helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1));
	}
};