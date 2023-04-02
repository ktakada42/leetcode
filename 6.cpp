class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1 || s.size() <= numRows) {
			return (s);
		}

		vector<string> vec(numRows, "");
		int cycle = numRows * 2 - 2;
		for (int i = 0; i < s.size(); i++) {
			int place = i % cycle;
			if (place >= numRows) {
				place = numRows - 2 - (place - numRows);
			}
			vec[place] += s[i];
		}
		string res = "";
		for (auto &&s : vec) {
			res += s;
		}
		return (res);
	}
};