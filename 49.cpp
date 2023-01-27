class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, vector<string>> map;
		for (int i = 0; i < strs.size(); i++) {
			string s = strs[i];
			sort(s.begin(), s.end());
			map[s].push_back(strs[i]);
		}

		for (auto it = map.begin(); it != map.end(); it++) {
			res.push_back(it->second);
		}
		return (res);
	}
};