/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		int rv = root->val, pv = p->val, qv = q->val;
		if (pv < rv && qv < rv) {
			return (lowestCommonAncestor(root->left, p, q));
		} else if (rv < pv && rv < qv) {
			return (lowestCommonAncestor(root->right, p, q));
		} else {
			return (root);
		}
	}
};