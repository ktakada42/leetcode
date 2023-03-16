class Solution {
public:
	bool canShip(vector<int>& weights, int days, int cap) {
		int curDays = 1;
		int curWeight = 0;
		for (auto&& w : weights) {
			curWeight += w;
			if (curWeight > cap) {
				curWeight = w;
				curDays++;
			}
		}
		if (curDays <= days) {
			return (true);
		}
		return (false);
	}

	int shipWithinDays(vector<int>& weights, int days) {
		int totalLoad = 0;
		int maxLoad = weights[0];
		for (auto&& w : weights) {
			totalLoad += w;
			maxLoad = max(maxLoad, w);
		}

		int res = totalLoad;
		int left = maxLoad, right = totalLoad;
		while (left <= right) {
			int cap = (left + right) / 2;
			if (canShip(weights, days, cap) == true) {
				res = min(res, cap);
				right = cap - 1;
			} else {
				left = cap + 1;
			}
		}
		return (res);
	}
};