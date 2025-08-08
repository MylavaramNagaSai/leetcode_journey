class Solution:
    def countDigitOne(self, n: int) -> int:
        count = 0
        factor = 1  # current digit's place value

        while factor <= n:
            low = n % factor
            curr = (n // factor) % 10
            high = n // (factor * 10)

            if curr == 0:
                count += high * factor
            elif curr == 1:
                count += high * factor + low + 1
            else:
                count += (high + 1) * factor

            factor *= 10

        return count
