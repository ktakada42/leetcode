class Solution {
public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		vector<vector<int>> res;
		int m = heights.size(), n = heights[0].size();

		vector<vector<bool>> pacific(m, vector<bool>(n));
		vector<vector<bool>> atlantic(m, vector<bool>(n));

		for (int i = 0; i < m; i++) {
			dfs(heights, pacific, i, 0);
			dfs(heights, atlantic, i, n - 1);
		}
		for (int i = 0; i < n; i++) {
			dfs(heights, pacific, 0, i);
			dfs(heights, atlantic, m - 1, i);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (pacific[i][j] && atlantic[i][j]) {
					res.push_back({i, j});
				}
			}
		}
		return (res);
	}

	void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, vector<vector<bool>>& ocean, int i, int j) {
		int m = heights.size(), n = heights[0].size();

		ocean[i][j] = true;

		if (i - 1 >= 0 && ocean[i - 1][j] != true && heights[i - 1][j] >= heights[i][j]) {
			dfs(heights, ocean, i - 1, j);
		}
		if (i + 1 < m && ocean[i + 1][j] != true && heights[i + 1][j] >= heights[i][j]) {
			dfs(heights, ocean, i + 1, j);
		}
		if (j - 1 >= 0 && ocean[i][j - 1] != true && heights[i][j - 1] >= heights[i][j]) {
			dfs(heights, ocean, i, j - 1);
		}
		if (j + 1 < n && ocean[i][j + 1] != true && heights[i][j + 1] >= heights[i][j]) {
			dfs(heights, ocean, i, j + 1);
		}
	}
};