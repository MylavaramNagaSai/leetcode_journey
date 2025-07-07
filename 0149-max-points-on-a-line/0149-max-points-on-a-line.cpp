class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();

        int result = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<string, int> slopeMap;
            int duplicates = 1;
            int currMax = 0;

            for (int j = i + 1; j < points.size(); ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    // Duplicate point
                    duplicates++;
                } else {
                    int g = gcd(dx, dy);
                    dx /= g;
                    dy /= g;

                    // Normalize slope direction
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }

                    string slope = to_string(dy) + "/" + to_string(dx);
                    slopeMap[slope]++;
                    currMax = max(currMax, slopeMap[slope]);
                }
            }

            result = max(result, currMax + duplicates);
        }

        return result;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
