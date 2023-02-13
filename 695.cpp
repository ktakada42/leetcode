class Solution {
public:
	int dfs(vector<vector<int>>& grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
			return (0);
		}
		if (grid[i][j] == 0 || grid[i][j] == 2) {
			return (0);
		}

		int area = 1;
		grid[i][j]++;

		area += dfs(grid, i - 1, j);
		area += dfs(grid, i, j - 1);
		area += dfs(grid, i + 1, j);
		area += dfs(grid, i, j + 1);
		return (area);
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int maxArea = 0;
		int m = grid.size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				maxArea = max(maxArea, dfs(grid, i, j));
			}
		}
		return (maxArea);
	}
};