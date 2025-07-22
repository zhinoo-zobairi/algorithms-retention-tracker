# Graphs

A graph is a collection of vertices (nodes) and edges (connections).
It is denoted as:
G = (V, E)
Where:
- V = set of vertices
- E = set of edges connecting pairs of vertices

---

## Directed vs. Undirected Graphs
- If edges have a direction → Directed Graph
- If edges have no direction → Undirected Graph

In directed graphs:
- Indegree: number of edges coming into a node
- Outdegree: number of edges going out from a node
- In undirected graphs, we just say degree.

---

## Graph Representations

1. **Adjacency Matrix (for undirected or directed)**
    - A 2D matrix where:
        - matrix[i][j] = 1 → edge exists between i and j
        - For weighted graphs, the 1 is replaced by the weight (cost)

2. **Adjacency List**
    - Each vertex maintains a list (e.g. linked list or hash map) of connected nodes
    - Time complexity:
        - Space: O(n + 2e) for undirected
        - Space: O(n + e) for directed

3. **Compact List Representation**
    - Flattened list that stores all adjacency info in a 1D array
    - Allocate:
        - n slots for vertex headers
        - 2e slots for edges (for undirected), e for directed
        - +1 extra cell for offset handling

---

## Connectivity
- A graph that is not fully connected may have connected components
- Key structural concepts:
    - Articulation points: nodes whose removal increases the number of connected components
    - Bridges: edges whose removal disconnects the graph
    - Biconnected components: maximal subgraphs where no single vertex removal disconnects it
    - Strongly connected (in directed graphs): from any vertex, all other vertices are reachable

---

## Special Graphs
- Cycle: a path that starts and ends at the same vertex
- DAG (Directed Acyclic Graph): a directed graph with no cycles
- Topological Sort: a linear ordering of vertices such that all directed edges go from earlier to later — only possible in DAGs

---

## Traversal Methods

1. **BFS (Breadth-First Search)**
    - Similar to level-order traversal in trees
    - Uses a queue to explore vertices layer by layer
    - Spanning Tree: if we convert the graph into a tree by removing cross edges
    - Time complexity:
        - Theoretical: O(n + e)
        - With adjacency matrix: O(n²)

    **Steps:**
    - Visit start node, enqueue it
    - While queue is not empty:
        - Dequeue node
        - Visit all unvisited adjacent nodes and enqueue them

---

2. **DFS (Depth-First Search)**
    - Similar to pre-order traversal
    - Uses stack or recursion
    - On visiting a vertex:
        - Suspend current exploration
        - Dive deeper into an unvisited neighbor
        - Back edges form dotted lines in DFS spanning trees

    **Steps:**
    - Visit node, mark as visited
    - For each unvisited neighbor:
        - Recursively explore
    - Backtrack when no unvisited neighbor remains

    **Time complexity:**
    - Theoretical: O(n + e)
    - With adjacency matrix: O(n²)

---

## Spanning Trees
A spanning tree of a connected graph:
- Is a subset of edges that:
    - Connect all vertices
    - Has no cycles
    - Has exactly n – 1 edges
- A graph can have many different spanning trees.

---

## Minimum Spanning Tree (MST)
Finds a spanning tree with the minimum total edge cost.

**Greedy Strategy**
Greedy algorithms work well for MST because:
- The greedy choice property and
- Optimal substructure are satisfied

---

## How Greedy Algorithms Work in Graphs
Greedy method:
- Always makes the best local choice
- Does not backtrack
- Works only when the problem satisfies:
    - Greedy choice property
    - Optimal substructure

**Works well for:**
- MST (e.g. Kruskal, Prim)
- Dijkstra’s shortest path

**Doesn’t work for:**
- NP-hard problems without those properties (e.g. TSP)

---

## Kruskal’s Algorithm
- Sort all edges by weight
- Pick the smallest edge that doesn’t form a cycle
- Use Disjoint Set (Union-Find) to track connected components

**Time Complexity:**
O(E log E) due to sorting

---

## Disjoint Set (Union-Find)
Used to efficiently manage dynamic connectivity:
- MakeSet(x) → initializes a singleton set
- Find(x) → returns the representative of the set
- Union(x, y) → merges two sets

Used in Kruskal’s algorithm to avoid cycles.

Optimized with:
- Path compression
- Union by rank

---

## Prim’s Algorithm
Finds a minimum spanning tree by growing a single tree.
- Start from any vertex.
- Use a min-priority queue to select the edge with the smallest weight that connects a visited vertex to an unvisited vertex.
- Add the selected edge and vertex to the tree.
- Repeat until all vertices are included.

**Steps:**
1. Initialize all vertex costs as ∞, except the start vertex (cost 0).
2. Use a min-priority queue to pick the next minimum-cost edge.
3. For each newly added vertex, update costs for its adjacent unvisited vertices.
4. Continue until all vertices are included in the MST.

**Time Complexity:**
- With min-heap and adjacency list: O((n + e) log n)
- With adjacency matrix: O(n²)

---

## Dijkstra’s Algorithm
Solves single-source shortest path for graphs with non-negative edge weights.

**Steps:**
1. Initialize distances as ∞, except start node = 0
2. Use a min-priority queue (e.g. heap)
3. Relax each edge:
    - If distance[u] + weight < distance[v], update distance[v]

**Time complexity:**
- With min-heap: O((n + e) log n)

---

## Optimization Problems with Constraints
A typical form:
- Objective: minimize or maximize some function (e.g. cost, time, distance)
- Constraints: conditions the solution must satisfy (e.g. connected, no cycle, capacity limits)