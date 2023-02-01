class Solution {
public
	int characterReplacement(string s, int k) {
		int longestLength = 0;
		int left = 0;
		int counter[26] = {0};
		int maxCount = 0;

		for (int right = 0; right < s.size(); right++) {
			counter[s[right] - 'A']++;
			maxCount = max(maxCount, counter[s[right] - 'A']);
			if (right - left + 1 - maxCount > k) {
				counter[s[left] - 'A']--;
				left++;
			}
			longestLength = right - left + 1;
		}
		return (longestLength);
	}
};