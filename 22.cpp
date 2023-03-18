class Solution {
public:
	void dfs(vector<string> &res, string pattern, int left, int right) {
		if (right == 0) {
			res.push_back(pattern);
			return ;
		} else if (left == 0) {
			dfs(res, pattern + ")", left, right - 1);
			return ;
		} else if (left == right) {
			dfs(res, pattern + "(", left - 1, right);
			return ;
		} else {
			dfs(res, pattern + "(", left - 1, right);
			dfs(res, pattern + ")", left, right - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> res;
		dfs(res, "(", n - 1, n);
		return (res);
	}
};