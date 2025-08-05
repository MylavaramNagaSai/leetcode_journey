class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        temp = s + '#' + rev
        
        # Build KMP prefix table
        lps = [0] * len(temp)
        for i in range(1, len(temp)):
            j = lps[i - 1]
            while j > 0 and temp[i] != temp[j]:
                j = lps[j - 1]
            if temp[i] == temp[j]:
                j += 1
            lps[i] = j
        
        # Longest palindromic prefix length
        longest = lps[-1]
        # Add the remaining part of reverse(s) in front
        return rev[:len(s) - longest] + s
