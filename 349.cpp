class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, bool> map;
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++) {
			if (map[nums1[i]] == false) {
				map[nums1[i]] = true;
			}
		}
		for (int i = 0; i < nums2.size(); i++) {
			if (map[nums2[i]] == true) {
				res.push_back(nums2[i]);
				map[nums2[i]] = false;
			}
		}
		return (res);
	}
};