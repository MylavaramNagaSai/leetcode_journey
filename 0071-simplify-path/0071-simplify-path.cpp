class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string token;

        // Split the path by '/'
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!stack.empty()) stack.pop_back();  // Go up one directory
            } else {
                stack.push_back(token);  // Valid directory name
            }
        }

        // Reconstruct the canonical path
        string simplified;
        for (const string& dir : stack) {
            simplified += "/" + dir;
        }

        return simplified.empty() ? "/" : simplified;
    }
};
