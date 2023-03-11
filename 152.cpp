class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int res = nums[0];
		int curMax = nums[0], curMin = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int tmp = curMax;
			curMax = max(max(curMax * nums[i], curMin * nums[i]), nums[i]);
			curMin = min(min(tmp * nums[i], curMin * nums[i]), nums[i]);
			res = max(res, curMax);
		}
		return (res);
	}
};