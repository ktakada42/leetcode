class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size(), n = text2.size();
		int dp[m + 1][n + 1];
		for (int i = 0; i < m + 1; i++) {
			dp[i][n] = 0;
		}
		for (int i = 0; i < n + 1; i++) {
			dp[m][i] = 0;
		}

		for (int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (text1[i] == text2[j]) {
					dp[i][j] = 1 + dp[i + 1][j + 1];
				} else {
					dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
		return (dp[0][0]);
	}
};