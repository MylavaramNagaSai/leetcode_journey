class MyQueue:

    def __init__(self):
        self.in_stack = []   # for push operations
        self.out_stack = []  # for pop/peek operations

    def push(self, x: int) -> None:
        self.in_stack.append(x)

    def pop(self) -> int:
        self._move_in_to_out()
        return self.out_stack.pop()

    def peek(self) -> int:
        self._move_in_to_out()
        return self.out_stack[-1]

    def empty(self) -> bool:
        return not self.in_stack and not self.out_stack

    def _move_in_to_out(self):
        """Move elements from in_stack to out_stack only when out_stack is empty."""
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
