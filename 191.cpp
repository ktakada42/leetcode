class Solution {
public:
	int hammingWeight(uint32_t n) {
		int bitCount = 0;
		while (n > 0) {
			if (n % 2 == 1) {
				bitCount++;
			}
			n /= 2;
		}
		return (bitCount);
	}
};