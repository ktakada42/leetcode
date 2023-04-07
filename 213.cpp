class Solution {
public:
	int robWithPos(vector<int>& nums, int start, int end) {
		int prev = 0, cur = 0;
		for (int i = start; i < end; i++) {
			int tmp = max(prev + nums[i], cur);
			prev = cur;
			cur = tmp;
		}
		return (cur);
	}

	int rob(vector<int>& nums) {
		int n = nums.size();
		if (n == 1) {
			return (nums[0]);
		}
		return (max(robWithPos(nums, 0, n - 1), robWithPos(nums, 1, n)));
	}
};