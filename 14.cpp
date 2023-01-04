//
// Created by Keisuke Takada on 2023/01/04.
//

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int strNum = strs.size();
		sort(strs.begin(), strs.end());
		string first = strs[0];
		string last = strs[strNum - 1];
		string ans = "";

		for (int i = 0; i < first.size(); i++) {
			if (first[i] == last[i]) {
				ans += first[i];
			} else {
				break ;
			}
		}
		return (ans);
	}
};
