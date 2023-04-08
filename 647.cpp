class Solution {
public:
	int countSubstrings(string s) {
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			int left = i, right = i;
			while (0 <= left && right < s.size() && s[left] == s[right]) {
				res++;
				left--;
				right++;
			}

			left = i + 1, right = i;
			while (0 <= left && right < s.size() && s[left] == s[right]) {
				res++;
				left--;
				right++;
			}
		}
		return (res);
	}
};