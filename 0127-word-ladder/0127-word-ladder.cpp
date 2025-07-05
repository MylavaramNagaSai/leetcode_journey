class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                string word = q.front(); q.pop();

                for (int j = 0; j < word.length(); ++j) {
                    char original = word[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[j] = c;
                        if (word == endWord) return level + 1;

                        if (dict.count(word)) {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = original;
                }
            }

            level++;
        }

        return 0;
    }
};
