#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<pair<int,int>>> adj; // (neighbor, cost)

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int cost) {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    void displayGraph() {
        cout << "\n========= SMART CITY MAP =========\n";
        for (int i = 0; i < V; i++) {
            cout << "Location " << i << " -> ";
            for (auto neighbor : adj[i]) {
                cout << "(" << neighbor.first 
                     << ", cost=" << neighbor.second << ") ";
            }
            cout << endl;
        }
        cout << "==================================\n";
    }

    // ---------------- BFS ----------------
    void BFS(int start, int dest) {
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neighbor : adj[node]) {
                int next = neighbor.first;

                if (!visited[next]) {
                    visited[next] = true;
                    parent[next] = node;
                    q.push(next);
                }
            }
        }

        if (!visited[dest]) {
            cout << "\nNo path found using BFS.\n";
            return;
        }

        vector<int> path;
        int current = dest;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());

        int totalCost = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i + 1];

            for (auto neighbor : adj[u]) {
                if (neighbor.first == v) {
                    totalCost += neighbor.second;
                    break;
                }
            }
        }

        cout << "\nPath using BFS: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << "\nTotal Cost (BFS Path Cost): " 
             << totalCost << endl;
    }

    // ---------------- A* ----------------
    void aStar(int start, int dest, vector<int>& heuristic) {

        vector<int> gCost(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);
        vector<bool> visited(V, false);

        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        gCost[start] = 0;
        pq.push({heuristic[start], start});

        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if (node == dest)
                break;

            if (visited[node])
                continue;

            visited[node] = true;

            for (auto neighbor : adj[node]) {
                int next = neighbor.first;
                int cost = neighbor.second;

                int newCost = gCost[node] + cost;

                if (newCost < gCost[next]) {
                    gCost[next] = newCost;
                    parent[next] = node;
                    int fCost = gCost[next] + heuristic[next];
                    pq.push({fCost, next});
                }
            }
        }

        if (gCost[dest] == numeric_limits<int>::max()) {
            cout << "\nNo path found using A*.\n";
            return;
        }

        vector<int> path;
        int current = dest;
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        reverse(path.begin(), path.end());

        cout << "\nOptimal Path using A*: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << "\nTotal Cost (A* Optimal Cost): " 
             << gCost[dest] << endl;
    }
};

// ---------------- MAIN ----------------
int main() {

    cout << "===== MAP FOR PATH FINDER =====\n";

    Graph g(10);

    // Bigger predefined map
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 5);
    g.addEdge(1, 4, 12);
    g.addEdge(2, 5, 7);
    g.addEdge(3, 6, 4);
    g.addEdge(4, 6, 3);
    g.addEdge(5, 7, 6);
    g.addEdge(6, 8, 5);
    g.addEdge(7, 8, 2);
    g.addEdge(8, 9, 4);
    g.addEdge(4, 9, 15);

    // Heuristic values (destination assumed near node 9)
    vector<int> heuristic = {14, 12, 10, 9, 8, 7, 5, 4, 2, 0};

    g.displayGraph();

    int start, dest;

    cout << "\nEnter Starting Location: ";
    cin >> start;

    cout << "Enter Destination Location: ";
    cin >> dest;

    g.BFS(start, dest);
    g.aStar(start, dest, heuristic);

    cout << "\nThank you for using Smart Path Finder!\n";

    return 0;
}