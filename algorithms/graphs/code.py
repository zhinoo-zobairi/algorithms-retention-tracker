# Graphs implementation

from queue.code import LinkedListQueue

class DisjointSet:
    def __init__(self, n):
        self.parent = [-1] * (n + 1)  # assuming 1-based indexing

    def find(self, x):  # Each node points to its parent
        if self.parent[x] < 0: # The root node is the one whose parent is -1 or a negative number. If x has a negative value in parent[x], it means x is the root of its set.
            return x
        self.parent[x] = self.find(self.parent[x])  # We recursively call find() on x’s parent. This finds the true root of the tree. Then we update x’s parent directly to point to the root.This is called path compression.
        return self.parent[x]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            self.parent[root_v] = root_u


class Graph:

    def __init__(self, adjacency_matrix):
        self.matrix = adjacency_matrix

    def bfs(self, start):
        visited = [0] * len(self.matrix)
        queue = LinkedListQueue()
        queue.enqueue(start)
        visited[start] = 1

        while not queue.is_empty():
            i = queue.dequeue()
            print(i, end=' ')
            for j in range(1, len(self.matrix[i])):  # skip column 0
                if self.matrix[i][j] == 1 and visited[j] == 0:
                    queue.enqueue(j)
                    visited[j] = 1

    def dfs(self, start, visited=None):
        if visited is None:
            visited = [0] * len(self.matrix)
        visited[start] = 1
        print(start, end=' ')
        for j in range(1, len(self.matrix[start])):  # skip column 0
            if self.matrix[start][j] == 1 and visited[j] == 0:
                self.dfs(j, visited)

    def kruskal(self, edges, n):
        selected = [False] * len(edges)
        min_cost = 0
        edge_count = 0
        ds = DisjointSet(n)

        while edge_count < n - 1:
            min_val = float('inf')
            index = -1

            for i in range(len(edges)):
                if not selected[i] and edges[i][2] < min_val:
                    min_val = edges[i][2]
                    index = i

            u, v, cost = edges[index]
            if ds.find(u) != ds.find(v):
                min_cost += cost
                selected[index] = True
                edge_count += 1
                ds.union(u, v)
                print(f"Selected Edge: ({u}, {v}) with cost {cost}")
            else:
                selected[index] = True

        print("Minimum cost of spanning tree:", min_cost) # time taken by this is |V| * |E| or O(n^2) BUT if it is a complete graph, since the |E| in a complete graph is n(n-1) / 2, then it can go up until O(n^3) AND if we use a min-heap for exrtracting minimum, we will have O(nlog)

    def dijkstra(self, cost, source):
        n = len(cost)
        selected = [False] * n
        d = [float('inf')] * n
        d[source] = 0

        for _ in range(n):
            min_dist = float('inf')
            u = -1
            for i in range(n):
                if not selected[i] and d[i] < min_dist:
                    min_dist = d[i]
                    u = i
            if u == -1:
                break

            selected[u] = True
            for v in range(n):
                if not selected[v] and cost[u][v] != 0 and d[u] + cost[u][v] < d[v]:
                    d[v] = d[u] + cost[u][v]
        return d

    def prim(self, cost):
        n = len(cost)
        selected = [False] * n
        min_cost = 0
        near = [-1] * n

        selected[0] = True
        for i in range(1, n):
            near[i] = 0

        for _ in range(n - 1):
            min_val = float('inf')
            u = v = -1
            for j in range(n):
                if not selected[j] and cost[near[j]][j] < min_val:
                    min_val = cost[near[j]][j]
                    u = near[j]
                    v = j
            selected[v] = True
            min_cost += cost[u][v]
            for k in range(n):
                if not selected[k] and cost[v][k] < cost[near[k]][k]:
                    near[k] = v

        return min_cost


# no use of column zero and row zero, because graph starts from vertex 1 onwards
matrix = [[0,0,0,0,0,0,0],
          [0,0,1,1,0,0,0],
          [0,1,0,0,1,0,0],
          [0,1,0,0,1,0,0],
          [0,0,1,1,0,1,1],
          [0,0,0,0,1,0,0],
          [0,0,0,0,1,0,0]]

edges = [  # (u, v, cost)
    (1, 2, 28), (1, 6, 10), (2, 3, 16), (2, 7, 14),
    (3, 4, 12), (4, 5, 22), (4, 7, 18), (5, 6, 25), (5, 7, 24)
]

graph = Graph(matrix)

print("BFS starting from 1:")
graph.bfs(1)
print("\nDFS starting from 3:")
graph.dfs(3)
print("\nKruskal's MST:")
graph.kruskal(edges, n=7)