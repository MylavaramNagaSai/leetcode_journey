int longestValidParentheses(char* s) {
    int maxLen = 0;
    int len = strlen(s);

    int* stack = (int*)malloc(sizeof(int) * (len + 1));
    int top = -1;

    // Initialize with -1 to handle edge cases
    stack[++top] = -1;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stack[++top] = i;  // push index of '('
        } else {
            top--;  // pop matching '('
            if (top == -1) {
                stack[++top] = i;  // unmatched ')', reset base index
            } else {
                int validLen = i - stack[top];
                if (validLen > maxLen)
                    maxLen = validLen;
            }
        }
    }

    free(stack);
    return maxLen;
}
