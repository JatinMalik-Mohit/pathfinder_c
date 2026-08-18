# 🚀 Smart City Path Finder (C++)

A simple yet powerful **graph-based pathfinding system** implemented in C++. This project simulates a smart city map and demonstrates how different algorithms find paths between locations.

It compares:

* **BFS (Breadth-First Search)** for basic path traversal
* **A* (A-Star Algorithm)** for optimal pathfinding using heuristics

---

## 📌 Features

* Create a city map using graph data structure
* Add weighted edges between locations
* Visualize adjacency list of the graph
* Find path using:

  * BFS (not cost-optimal)
  * A* (cost-efficient and optimal)
* Calculate total path cost
* User input for start and destination nodes

---

## 🧠 Algorithms Used

### 🔹 Breadth-First Search (BFS)

* Explores nodes level by level
* Does **not guarantee minimum cost path**
* Useful for simple traversal

### 🔹 A* Algorithm

* Uses **g(n) + h(n)**:

  * g(n): actual cost from start
  * h(n): heuristic estimate to goal
* Guarantees optimal path (if heuristic is admissible)

---

## 🗺️ Graph Structure

* Undirected weighted graph
* Nodes represent locations
* Edges represent paths with costs

Example:

```
Location 0 -> (1, cost=4), (2, cost=3)
```

---

## 🛠️ How to Run

### 1. Compile

```bash
g++ main.cpp -o pathfinder
```

### 2. Run

```bash
./pathfinder
```

---

## ▶️ Sample Execution

```
===== MAP FOR PATH FINDER =====

Enter Starting Location: 0
Enter Destination Location: 9

Path using BFS: 0 -> 1 -> 4 -> 9
Total Cost (BFS Path Cost): 31

Optimal Path using A*: 0 -> 2 -> 5 -> 7 -> 8 -> 9
Total Cost (A* Optimal Cost): 22
```

---

## 📊 Heuristic Values

The A* algorithm uses predefined heuristic values:

```
{14, 12, 10, 9, 8, 7, 5, 4, 2, 0}
```

These represent estimated distances to the goal node.

---

## 📁 Project Structure

```
├── main.cpp
├── README.md
```


## 🎯 Learning Objectives

* Understand graph representation using adjacency lists
* Learn BFS vs A* differences
* Implement priority queues in C++
* Apply heuristic-based search algorithms

---

## ⚠️ Limitations

* Heuristic values are hardcoded
* No dynamic graph input
* Console-based interface only

---

## 🔮 Future Improvements

* Add GUI visualization
* Allow dynamic graph creation
* Implement Dijkstra’s algorithm
* Real-world map integration

---

