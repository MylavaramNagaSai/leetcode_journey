class Solution {
    func numDistinct(_ s: String, _ t: String) -> Int {
        let sChars = Array(s)
        let tChars = Array(t)
        let m = sChars.count
        let n = tChars.count

        if n > m { return 0 }

        var dp = Array(repeating: Array(repeating: 0.0, count: n + 1), count: m + 1)

        for i in 0...m {
            dp[i][0] = 1.0
        }

        for i in 1...m {
            for j in 1...n {
                if sChars[i - 1] == tChars[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
                } else {
                    dp[i][j] = dp[i - 1][j]
                }
            }
        }

        return Int(dp[m][n])
    }
}
