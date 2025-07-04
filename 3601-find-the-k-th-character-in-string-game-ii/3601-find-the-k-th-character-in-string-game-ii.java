class Solution {
    public char kthCharacter(long k, int[] operations) {
        int n = operations.length;
        long[] lengths = new long[n + 1];
        lengths[0] = 1; // initial word is "a"

        // Build the length after each operation
        for (int i = 0; i < n; i++) {
            if (operations[i] == 0) {
                lengths[i + 1] = Math.min(k, lengths[i] * 2);
            } else {
                lengths[i + 1] = Math.min(k, lengths[i] * 2);
            }
        }

        int shift = 0;

        // Trace the origin of the k-th character (backward)
        for (int i = n - 1; i >= 0; i--) {
            long half = lengths[i];

            if (k > half) {
                k -= half; // Move to the second half
                if (operations[i] == 1) {
                    shift++; // Track transformation shift
                }
            }
            // Else: stay in the first half, no change needed
        }

        // Final character is 'a' shifted by total shift
        shift %= 26;
        return (char) ('a' + shift);
    }
}
