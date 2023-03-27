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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) {
			return (res);
		}

		queue<TreeNode *> q;
		q.push(root);
		int level = 1;
		while (q.empty() != true) {
			int qLen = q.size();
			vector<int> nodes;
			for (int i = 0; i < qLen; i++) {
				TreeNode *node = q.front();
				q.pop();
				if (node != NULL) {
					nodes.push_back(node->val);
					q.push(node->left);
					q.push(node->right);
				}
			}
			if (nodes.size() != 0) {
				if (level % 2 == 0) {
					reverse(nodes.begin(), nodes.end());
				}
				res.push_back(nodes);
			}
			level++;
		}
		return (res);
	}
};