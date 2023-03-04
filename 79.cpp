class Solution {
public:
	bool dfs(vector<vector<char>>& board, int m, int n, int curLen, string word, vector<vector<bool>>& visited) {
		if (curLen == word.size()) {
			return (true);
		}
		if (m < 0 || board.size() <= m || n < 0 || board[0].size() <= n || board[m][n] != word[curLen] || visited[m][n] == true) {
			return (false);
		}

		visited[m][n] = true;
		bool exist = dfs(board, m + 1, n, curLen + 1, word, visited) || dfs(board, m, n + 1, curLen + 1, word, visited) || dfs(board, m - 1, n, curLen + 1, word, visited) || dfs(board, m, n - 1, curLen + 1, word, visited);
		visited[m][n] = false;
		return (exist);
	}

	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size(), n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(board, i, j, 0, word, visited) == true) {
					return (true);
				}
			}
		}
		return (false);
	}
};