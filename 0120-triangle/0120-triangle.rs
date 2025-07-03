impl Solution {
    pub fn minimum_total(mut triangle: Vec<Vec<i32>>) -> i32 {
        let n = triangle.len();
        if n == 0 {
            return 0;
        }

        // Start from the second last row and move upward
        for row in (0..n-1).rev() {
            for col in 0..triangle[row].len() {
                triangle[row][col] += triangle[row + 1][col].min(triangle[row + 1][col + 1]);
            }
        }

        triangle[0][0]
    }
}
