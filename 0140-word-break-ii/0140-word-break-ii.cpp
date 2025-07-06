class Solution {
public:
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

    vector<string> dfs(string s) {
        if (memo.count(s)) return memo[s];
        vector<string> result;

        if (dict.count(s)) {
            result.push_back(s);
        }

        for (int i = 1; i < s.size(); ++i) {
            string right = s.substr(i);
            if (!dict.count(right)) continue;

            string left = s.substr(0, i);
            vector<string> leftSentences = dfs(left);
            for (const string& sentence : leftSentences) {
                result.push_back(sentence + " " + right);
            }
        }

        memo[s] = result;
        return result;
    }
};
