from typing import List
from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        
        # Build graph & indegree count
        for a, b in prerequisites:
            graph[b].append(a)
            indegree[a] += 1
        
        # Start with courses having no prerequisites
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        visited = 0
        
        while queue:
            course = queue.popleft()
            visited += 1
            for nxt in graph[course]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)
        
        return visited == numCourses
