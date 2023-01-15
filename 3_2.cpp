class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		unordered_map<char, int> map;

		for (int left = 0, right = 0; right < s.size(); right++) {
			if (map[s[right]] > 0) {
				left = max(left, map[s[right]]);
			}
			ans = max(ans, right - left + 1);
			map[s[right]] = right + 1;
		}
		return (ans);
	}
};