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
	void dfs(vector<vector<int>> &res, int level, TreeNode *root) {
		if (root == NULL) {
			return ;
		}

		if (res.size() <= level) {
			res.push_back(vector<int>());
		}
		res[level].push_back(root->val);
		dfs(res, level + 1, root->left);
		dfs(res, level + 1, root->right);
	}

	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(res, 0, root);
		return (res);
	}
};