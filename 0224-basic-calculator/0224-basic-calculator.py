class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        result = 0
        number = 0
        sign = 1  # 1 for '+', -1 for '-'

        for char in s:
            if char.isdigit():
                number = number * 10 + int(char)
            elif char in '+-':
                result += sign * number
                number = 0
                sign = 1 if char == '+' else -1
            elif char == '(':
                # Push current result and sign
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif char == ')':
                result += sign * number
                number = 0
                result *= stack.pop()  # last sign
                result += stack.pop()  # last result
            # Ignore spaces

        # Add any number left
        return result + sign * number
