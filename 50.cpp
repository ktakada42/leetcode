class Solution {
public:
	double myPow(double x, int n) {
		if (n < 0) {
			x = 1 / x;
		}
		
		long num = labs(n);
		double pow = 1;
		while (num != 0) {
			if (num % 2 != 0) {
				pow *= x;
			}

			x *= x;
			num = num / 2;
		}

		return (pow);
	}
};