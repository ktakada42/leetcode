class Solution {
public:
	void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& permutation, unordered_map<int, bool>& used) {
		if (permutation.size() == nums.size()) {
			res.push_back(permutation);
			return ;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i] == false) {
				used[i] = true;
				permutation.push_back(nums[i]);
				backtrack(res, nums, permutation, used);
				used[i] = false;
				permutation.pop_back();
			}
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		unordered_map<int, bool> used;
		vector<int> permutation;
		backtrack(res, nums, permutation, used);
		return (res);
	}
};