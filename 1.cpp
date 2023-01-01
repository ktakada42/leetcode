//
// Created by Keisuke Takada on 2023/01/01.
//

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); i++) {
			int left = target - nums[i];
			if (hash[left] != hash.end()) {
				return {hash[left], i};
			}
			hash[nums[i]] = i;
		}
		return {};
	}
};
