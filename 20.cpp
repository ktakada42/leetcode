//
// Created by Keisuke Takada on 2023/01/05.
//

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				stack.push(s[i]);
			} else if ((s[i] == ')' && stack.size() > 0 && stack.top() == '(') || (s[i] == '}' && stack.size() > 0 && stack.top() == '{') || (s[i] == ']' && stack.size() > 0 && stack.top() == '[')) {
				stack.pop();
			} else {
				return (false);
			}
		}

		if (stack.size() == 0) {
			return (true);
		}
		return (false);
	}
};
