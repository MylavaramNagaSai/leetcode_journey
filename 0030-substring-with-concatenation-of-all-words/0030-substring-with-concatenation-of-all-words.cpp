class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int windowSize = wordLen * wordCount;

        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }

        // Try every offset in word length (to handle alignment)
        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> windowWords;
            int count = 0;

            while (right + wordLen <= s.length()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.find(word) != wordFreq.end()) {
                    windowWords[word]++;
                    count++;

                    // If word appears too many times, shrink window
                    while (windowWords[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowWords[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // Found valid window
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    windowWords.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
