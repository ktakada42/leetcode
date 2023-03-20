class Solution {
public:
	int myAtoi(string s) {
		int res = 0;
		int i = 0;
		bool neg = false;
		int cutoff = INT_MAX / 10;
		while (s[i] == ' ') {
			i++;
		}
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '-') {
				neg = true;
			}
			i++;
		}
		while ('0' <= s[i] && s[i] <= '9') {
			if (res > cutoff || (res == cutoff && s[i] > '7')) {
				if (neg) {
					return (INT_MIN);
				}
				return (INT_MAX);
			}
			res = res * 10 + (s[i] - '0');
			i++;
		}
		if (neg) {
			return (-1 * res);
		}
		return (res);
	}
};