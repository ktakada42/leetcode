class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int sLen = s.size();
		vector<bool> dp(sLen + 1, false);
		dp[sLen] = true;

		for (int i = sLen - 1; i >= 0; i--) {
			for (auto&& w : wordDict) {
				int wLen = w.size();
				if (i + wLen <= sLen && s.substr(i, wLen) == w) {
					dp[i] = dp[i + wLen];
				}
				if (dp[i] == true) {
					break ;
				}
			}
		}
		return (dp[0]);
	}
};