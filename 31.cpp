class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int left = nums.size() - 2;
		while (left >= 0 && nums[left] >= nums[left + 1]) {
			left--;
		}
		if (left >= 0) {
			int tail = nums.size() - 1;
			while (nums[left] >= nums[tail]) {
				tail--;
			}
			int tmp = nums[left];
			nums[left] = nums[tail];
			nums[tail] = tmp;
		}
		reverse(nums.begin() + left + 1, nums.end());
		return ;
	}
};