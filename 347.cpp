class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (k == nums.size()) {
			return (nums);
		}

		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]] += 1;
		}

		vector<vector<int>> freq(nums.size() + 1);
		for (auto it = map.begin(); it != map.end(); it++) {
			freq[it->second].push_back(it->first);
		}

		vector<int> res;
		for (int i = freq.size() - 1; i > 0; i--) {
			if (freq[i].size() != 0) {
				for (int j = 0; j < freq[i].size(); j++) {
					res.push_back(freq[i][j]);
				}
			}
			if (res.size() == k) {
				break ;
			}
		}
		return (res);
	}
};