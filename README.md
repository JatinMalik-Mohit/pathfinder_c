# 🚀 Campus Path Finder (C++)

A graph-based pathfinding and navigation system implemented in C++. This project models **Chandigarh University** as a smart mini-city to simulate, visualize, and compare different pathfinding algorithms across campus locations, blocks, and amenities.

---

## 📌 Features

* **Campus Graph Model:** Models Chandigarh University locations (academic blocks, hostels, food courts, sports facilities) as nodes with weighted edges representing distances/travel times.
* **Algorithm Comparison:**
  * **BFS (Breadth-First Search):** Finds the path with the fewest location hops (unweighted traversal).
  * **A* (A-Star Algorithm):** Finds the most cost-efficient and shortest physical path using distance-based heuristics.
* **Adjacency List Visualization:** Displays the full campus network structure.
* **Path & Cost Calculation:** Computes total travel distance and step-by-step route navigation from source to destination.
* **Interactive CLI:** Custom user input for selecting start and end points.

---

## 🧠 Algorithms Used

### 🔹 Breadth-First Search (BFS)
* Traverses the graph level-by-level.
* Finds the route with the minimum number of intermediate stops/nodes.
* **Limitation:** Does not account for path weights (distance/time).

### 🔹 A* Search Algorithm
* Uses the evaluation function $f(n) = g(n) + h(n)$:
  * $g(n)$: Actual path cost from the starting campus location to node $n$.
  * $h(n)$: Heuristic estimate of the distance from node $n$ to the target destination.
* **Advantage:** Guarantees the optimal path while exploring significantly fewer nodes than uninformed search algorithms.

---

## 🗺️ Campus Graph Representation

* **Type:** Undirected Weighted Graph
* **Nodes:** Campus landmarks (e.g., Block C3, South Campus, Main Gate, Food Court).
* **Edges:** Pathways/roads connecting locations, with weights representing distance (in meters) or travel time (in minutes).

```text
[ Main Gate ] --(400m)--> [ Academic Block C1 ] --(200m)--> [ Central Library ]
      |                                                        |
   (300m)                                                   (150m)
      v                                                        v
[ Student Centre ] -------------------------------------> [ Sports Complex ]
