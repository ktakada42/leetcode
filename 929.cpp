class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> set;
		for (int i = 0; i < emails.size(); i++) {
			string shortEmail = "";
			for (int j = 0; j < emails[i].size(); j++) {
				if (emails[i][j] == '+' || emails[i][j] == '@') {
					break ;
				} else if (emails[i][j] != '.') {
					shortEmail += emails[i][j];
				}
			}
			shortEmail += emails[i].substr(emails[i].find('@'));
			set.insert(shortEmail);
		}
		return (set.size());
	}
};