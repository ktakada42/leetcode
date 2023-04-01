/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	void dfs(TreeNode *root, string &res) {
		if (root == NULL) {
			res += "null,";
			return ;
		}
		res += to_string(root->val) + ",";
		dfs(root->left, res);
		dfs(root->right, res);
	}

	string serialize(TreeNode* root) {
		string res = "";
		dfs(root, res);
		return (res);
	}

	// Decodes your encoded data to tree.
	TreeNode *buildTree(queue<string> &q) {
		string s = q.front();
		q.pop();

		if (s == "null") {
			return (NULL);
		}
		TreeNode *root = new TreeNode(stoi(s));
		root->left = buildTree(q);
		root->right = buildTree(q);
		return (root);
	}

	TreeNode* deserialize(string data) {
		string s = "";
		queue<string> q;

		for (auto &&c : data) {
			if (c == ',') {
				q.push(s);
				s = "";
			} else {
				s += c;
			}
		}
		return (buildTree(q));
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));