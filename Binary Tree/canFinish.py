from collections import defaultdict, deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Build adjacency list and calculate in-degrees
        graph = defaultdict(list)
        in_degree = [0] * numCourses
        
        for course, prereq in prerequisites:
            graph[prereq].append(course)
            in_degree[course] += 1
        
        # Initialize queue with courses that have no prerequisites
        queue = deque()
        for i in range(numCourses):
            if in_degree[i] == 0:
                queue.append(i)
        
        completed = 0
        
        # Process courses using topological sort
        while queue:
            course = queue.popleft()
            completed += 1
            
            # Remove this course as prerequisite for other courses
            for next_course in graph[course]:
                in_degree[next_course] -= 1
                if in_degree[next_course] == 0:
                    queue.append(next_course)
        
        # If we completed all courses, there's no cycle
        return completed == numCourses

# Alternative DFS approach for cycle detection
class SolutionDFS:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for course, prereq in prerequisites:
            graph[prereq].append(course)
        
        # 0: unvisited, 1: visiting, 2: visited
        state = [0] * numCourses
        
        def has_cycle(course):
            if state[course] == 1:  # Currently visiting - cycle detected
                return True
            if state[course] == 2:  # Already visited
                return False
            
            state[course] = 1  # Mark as visiting
            for next_course in graph[course]:
                if has_cycle(next_course):
                    return True
            state[course] = 2  # Mark as visited
            return False
        
        for i in range(numCourses):
            if state[i] == 0 and has_cycle(i):
                return False
        
        return True

# Test cases
if __name__ == "__main__":
    sol = Solution()
    
    # Test case 1: Can finish
    print(sol.canFinish(2, [[1,0]]))  # True
    
    # Test case 2: Cannot finish (cycle)
    print(sol.canFinish(2, [[1,0],[0,1]]))  # False
    
    # Test case 3: More complex case
    print(sol.canFinish(4, [[1,0],[2,0],[3,1],[3,2]]))  # True