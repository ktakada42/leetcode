class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size(), n = matrix[0].size();
		int top = 0, bottom = m - 1, left = 0, right = n - 1;
		int direction = 0;
		vector<int> res;
		
		while (res.size() < m * n) {
			switch (direction) {
				case 0: // top left to top right
					for (int i = left; i <= right; i++) {
						res.push_back(matrix[top][i]);
					}
					top++;
					direction++;
					break ;
				case 1: // top right to bottom right
					for (int i = top; i <= bottom; i++) {
						res.push_back(matrix[i][right]);
					}
					right--;
					direction++;
					break ;
				case 2: // bottom right to bottom left
					for (int i = right; i >= left; i--) {
						res.push_back(matrix[bottom][i]);
					}
					bottom--;
					direction++;
					break ;
				case 3: // bottom left to top left
					for (int i = bottom; i >= top; i--) {
						res.push_back(matrix[i][left]);
					}
					left++;
					direction = 0;
					break ;
			}
		}
		return (res);
	}
};