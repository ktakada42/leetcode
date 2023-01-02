//
// Created by Keisuke Takada on 2023/01/02.
//

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return (false);
		}

		int rev = 0;
		while (rev < x) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		if (x == rev || x == rev / 10) {
			return (true);
		}
		return (false);
	}
};
