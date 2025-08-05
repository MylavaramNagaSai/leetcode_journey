from typing import List
from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for _ in range(numCourses)]
        indegree = [0] * numCourses
        
        # Build graph & indegree count
        for a, b in prerequisites:
            graph[b].append(a)
            indegree[a] += 1
        
        # Start with courses having no prerequisites
        queue = deque([i for i in range(numCourses) if indegree[i] == 0])
        order = []
        
        while queue:
            course = queue.popleft()
            order.append(course)
            for nxt in graph[course]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    queue.append(nxt)
        
        # If we processed all courses, return order; otherwise, cycle exists
        return order if len(order) == numCourses else []
