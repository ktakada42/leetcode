class Solution {
public:
	int rob(vector<int>& nums) {
		int prev = 0, cur = 0;
		for (auto &&n : nums) {
			int tmp = max(prev + n, cur);
			prev = cur;
			cur = tmp;
		}
		return (cur);
	}
};