class Solution {
public:
	bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		string str;

		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j]) {
				str.push_back(s[i]);
				i++;
			}
			j++;
		}
		if (str == s) {
			return (true);
		} else {
			return (false);
		}
	}
};