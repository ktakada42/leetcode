class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> row(n, 1);

		for (int i = 0; i < m - 1; i++) {
			vector<int> upperRow(n, 1);
			for (int j = n - 2; j >= 0; j--) {
				upperRow[j] = upperRow[j + 1] + row[j];
			}
			row = upperRow;
		}
		return (row[0]);
	}
};