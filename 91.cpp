class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') {
			return (0);
		}

		int f0 = 1, f1 = 1;
		for (int i = 2; i <= s.size(); i++) {
			int f2 = 0;
			if (s[i - 1] != '0') {
				f2 += f1;
			}
			if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') {
				f2 += f0;
			}
			f0 = f1;
			f1 = f2;
		}
		return (f1);
	}
};