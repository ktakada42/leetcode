class Solution {
public:
	void combination(vector<int>& candidates, int target, vector<int> candidate, int sum, int idx, vector<vector<int>>& res) {
		if (sum > target) {
			return ;
		}
		if (sum == target) {
			res.push_back(candidate);
			return ;
		}

		for (int i = idx; i < candidates.size(); i++) {
			candidate.push_back(candidates[i]);
			sum += candidates[i];
			combination(candidates, target, candidate, sum, i, res);
			candidate.pop_back();
			sum -= candidates[i];
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> res;
		vector<int> candidate;
		combination(candidates, target, candidate, 0, 0, res);
		return (res);
	}
};