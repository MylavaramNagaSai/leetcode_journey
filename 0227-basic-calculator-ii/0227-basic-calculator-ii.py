class Solution:
    def calculate(self, s: str) -> int:
        s = s.replace(" ", "")
        stack = []
        num = 0
        sign = '+'
        
        for i, ch in enumerate(s):
            if ch.isdigit():
                num = num * 10 + int(ch)
            # if we see an operator or we're at the end, process the previous number
            if ch in '+-*/' or i == len(s) - 1:
                if sign == '+':
                    stack.append(num)
                elif sign == '-':
                    stack.append(-num)
                elif sign == '*':
                    stack.append(stack.pop() * num)
                elif sign == '/':
                    prev = stack.pop()
                    stack.append(int(prev / num))  # truncate toward zero
                sign = ch
                num = 0

        return sum(stack)
