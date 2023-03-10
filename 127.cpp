class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<string> choosable;
		choosable.push(beginWord);
		int ladder = 1;
		while (choosable.empty() != true) {
			int n = choosable.size();
			for (int i = 0; i < n; i++) {
				string word = choosable.front();
				choosable.pop();
				if (word == endWord) {
					return (ladder);
				}
				dict.erase(word);
				for (int j = 0; j < word.size(); j++) {
					char c = word[j];
					for (int k = 0; k < 26; k++) {
						word[j] = 'a' + k;
						if (dict.find(word) != dict.end()) {
							choosable.push(word);
						}
					}
					word[j] = c;
				}
			}
			ladder++;
		}
		return (0);
	}
};