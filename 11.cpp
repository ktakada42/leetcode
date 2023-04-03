class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int left = 0, right = height.size() - 1;
		while (left <= right) {
			int leftHeight = height[left], rightHeight = height[right];
			int curHeight = min(leftHeight, rightHeight);
			res = max(res, (right - left) * curHeight);
			if (leftHeight < rightHeight) {
				left++;
			} else {
				right--;
			}
		}
		return (res);
	}
};