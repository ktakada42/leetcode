class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> map;
		for (int i = 0; i < strs.size(); i++) {
			map[strSort(strs[i])].push_back(strs[i]);
		}

		for (auto it = map.begin(); it != map.end(); it++) {
			res.push_back(it->second);
		}
		return (res);
	}
private:
	string strSort(string s) {
		int counter[26] = {0};
		for (int i = 0; i < s.size(); i++) {
			counter[s[i] - 'a']++;
		}

		string t;
		for (int i = 0; i < 26; i++) {
			t += string(counter[i], 'a' + i);
		}
		return (t);
	}
};