class Solution {
public:
	string minWindow(string s, string t) {
		int m = s.size(), n = t.size();
		unordered_map<char, int> window;
		unordered_map<char, int> map;
		for (int i = 0; i < n; i++) {
			map[t[i]]++;
		}

		int tCount = 0;
		int minLen = INT_MAX;
		int minStart = 0;
		for (int left = 0, right = 0; right < m; right++) {
			if (map.find(s[right]) != map.end()) {
				window[s[right]]++;
				if (window[s[right]] <= map[s[right]]) {
					tCount++;
				}
			}
			if (tCount >= n) {
				while (map.find(s[left]) == map.end() || window[s[left]] > map[s[left]]) {
					window[s[left]]--
					left++;
				}
				if (right - left + 1 < minLen) {
					minLen = right - left + 1;
					minStart = left;
				}
			}
		}
		if (minLen == INT_MAX) {
			return ("");
		}
		return (s.substr(minStart, minLen));
	}
};