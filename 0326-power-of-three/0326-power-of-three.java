class Solution {
    // Method to check if a number is a power of three
    public boolean isPowerOfThree(int n) {
        // 1162261467 is the maximum integer that is a power of three
        // (it is 3^19, as 3^20 is bigger than int).
        // If 'n' is a power of three, it must divide this number without a remainder.
      
        // The condition 'n > 0' ensures that 'n' is positive,
        // because negative numbers and zero cannot be powers of three.
        return n > 0 && 1162261467 % n == 0;
    }
}