from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.word = None  # Marks the end of a full word

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        
        # Build Trie
        for w in words:
            node = root
            for ch in w:
                if ch not in node.children:
                    node.children[ch] = TrieNode()
                node = node.children[ch]
            node.word = w  # Store the full word at the end node
        
        rows, cols = len(board), len(board[0])
        result = []
        
        def dfs(r, c, node):
            ch = board[r][c]
            if ch not in node.children:
                return
            next_node = node.children[ch]
            if next_node.word:  # Found a word
                result.append(next_node.word)
                next_node.word = None  # Avoid duplicates
            
            board[r][c] = '#'  # Mark visited
            for dr, dc in [(1,0), (-1,0), (0,1), (0,-1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] != '#':
                    dfs(nr, nc, next_node)
            board[r][c] = ch  # Restore after DFS
        
        # Start DFS from each cell
        for r in range(rows):
            for c in range(cols):
                dfs(r, c, root)
        
        return result
