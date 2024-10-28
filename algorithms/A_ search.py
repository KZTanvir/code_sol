from queue import PriorityQueue

class AStarSearch:
    def __init__(self, graph, heuristic):
        self.graph = graph
        self.heuristic = heuristic

    def is_admissible_heuristic(self, node, goal):
        # Check if the heuristic value is less than or equal to the actual cost to reach the goal
        return self.heuristic[node] <= self.heuristic[goal]

    def search(self, start, goal):
        # Check if the heuristic values are admissible
        if not self.is_admissible_heuristic(start, goal) or not self.is_admissible_heuristic(goal, goal):
            raise ValueError("Heuristic values are not admissible.")

        priority_queue = PriorityQueue()
        visited = set()

        # Tuple format: (total_cost, node, path_cost, path)
        priority_queue.put((self.heuristic[start], start, 0, [start]))

        while not priority_queue.empty():
            total_cost, current_node, path_cost, path = priority_queue.get()

            if current_node in visited:
                continue

            print("Visiting:", current_node, "  Path Cost:", path_cost, "  Path:", path)
            visited.add(current_node)

            if current_node == goal:
                print("Goal reached! Total Path Cost:", path_cost)
                break

            for neighbor, weight in self.graph[current_node]:
                if neighbor not in visited:
                    new_cost = path_cost + weight
                    new_path = path + [neighbor]
                    total_cost = new_cost + self.heuristic[neighbor]
                    priority_queue.put((total_cost, neighbor, new_cost, new_path))

# Example usage:
graph = {
    'A': [('B', 3), ('C', 5)],
    'B': [('D', 2)],
    'C': [('E', 8)],
    'D': [('F', 4)],
    'E': [('G', 1)],
    'F': [],
    'G': []
}

heuristic_values = {'A': float('inf'), 'B': 2, 'C': float('inf'), 'D': 4, 'E': 1, 'F': 0, 'G': float('inf')}

# Create an instance of AStarSearch
astar = AStarSearch(graph, heuristic_values)

# Use the search method
astar.search('A', 'G')
