class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int zeroCount = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) {
				zeroCount++;
			} else {
				nums[i - zeroCount] = nums[i];
			}
		}
		for (int i = n - zeroCount; i < n; i++) {
			nums[i] = 0;
		}
	}
};