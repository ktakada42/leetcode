class Solution {
public:
	bool isPalindrome(string s) {
		string str = "";
		for (auto &&c : s) {
			if ('0' <= c && c <= '9' || 'a' <= c && c <= 'z') {
				str += c;
			} else if ('A' <= c && c <= 'Z') {
				c = c - 'A' + 'a';
				str += c;
			}
		}
		int left = 0, right = str.size() - 1;
		while (left <= right) {
			if (str[left] != str[right]) {
				return (false);
			}
			left++;
			right--;
		}
		return (true);
	}
};