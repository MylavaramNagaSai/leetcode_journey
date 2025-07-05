class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;

        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> currLevel;
        currLevel.insert(beginWord);

        bool found = false;

        while (!currLevel.empty() && !found) {
            for (const string& word : currLevel) {
                dict.erase(word); // avoid revisiting
            }

            unordered_set<string> nextLevel;

            for (const string& word : currLevel) {
                string temp = word;
                for (int i = 0; i < temp.size(); ++i) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (!dict.count(temp)) continue;

                        nextLevel.insert(temp);
                        parents[temp].push_back(word);
                        if (temp == endWord) found = true;
                    }
                    temp[i] = original;
                }
            }

            currLevel = nextLevel;
        }

        if (!found) return res;

        vector<string> path = {endWord};
        backtrack(endWord, beginWord, parents, path, res);
        return res;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> temp(path.rbegin(), path.rend());
            res.push_back(temp);
            return;
        }

        for (const string& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
