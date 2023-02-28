class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 0) {
			return (0);
		}

		sort(nums.begin(), nums.end());
		int res = 0;
		int curSeq = 1;
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] != nums[i + 1]) {
				if (nums[i + 1] - nums[i] == 1) {
					curSeq++;
				} else {
					res = max(res, curSeq);
					curSeq = 1;
				}
			}
		}
		return (max(res, curSeq));
	}
};