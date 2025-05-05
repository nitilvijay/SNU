#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include <iomanip>

using namespace std;

// Class to represent a Graph
class Graph {
private:
    int vertices;                   // Number of vertices
    vector<vector<int>> adjMatrix;  // Adjacency matrix
    
    // Utility function to find the vertex with minimum distance value
    int minDistance(const vector<int>& dist, const vector<bool>& visited) {
        int min = numeric_limits<int>::max();
        int min_index = -1;
        
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
    
    // Utility function for Kruskal's algorithm to find the parent of a node
    int find(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }
    
    // Utility function for Kruskal's algorithm to perform union of two sets
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        
        if (rootX == rootY) return;
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
    
    // Utility function to display the adjacency matrix
    void displayMatrix() {
        cout << "\nAdjacency Matrix:" << endl;
        cout << "    ";
        for (int i = 0; i < vertices; i++) {
            cout << setw(3) << i;
        }
        cout << endl;
        cout << "   ";
        for (int i = 0; i < vertices; i++) {
            cout << "---";
        }
        cout << endl;
        
        for (int i = 0; i < vertices; i++) {
            cout << setw(2) << i << " |";
            for (int j = 0; j < vertices; j++) {
                if (adjMatrix[i][j] == numeric_limits<int>::max()) {
                    cout << setw(3) << "∞";
                } else {
                    cout << setw(3) << adjMatrix[i][j];
                }
            }
            cout << endl;
        }
    }
    
public:
    // Constructor
    Graph(int v) : vertices(v) {
        // Initialize adjacency matrix with infinite weight (no edge)
        adjMatrix.resize(v, vector<int>(v, numeric_limits<int>::max()));
        // Set diagonal elements to 0 (distance to self is 0)
        for (int i = 0; i < v; i++) {
            adjMatrix[i][i] = 0;
        }
    }
    
    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertex!" << endl;
            return;
        }
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }
    
    // Function to remove an edge from the graph
    void removeEdge(int u, int v) {
        if (u < 0 || u >= vertices || v < 0 || v >= vertices) {
            cout << "Invalid vertex!" << endl;
            return;
        }
        adjMatrix[u][v] = numeric_limits<int>::max();
        adjMatrix[v][u] = numeric_limits<int>::max(); // For undirected graph
    }
    
    // Display the graph
    void displayGraph() {
        displayMatrix();
        
        cout << "\nGraph Edges:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = i+1; j < vertices; j++) {
                if (adjMatrix[i][j] != numeric_limits<int>::max()) {
                    cout << i << " -- " << j << " : " << adjMatrix[i][j] << endl;
                }
            }
        }
    }
    
    // Prim's Algorithm for Minimum Spanning Tree
    void primMST() {
        vector<int> parent(vertices);    // Array to store constructed MST
        vector<int> key(vertices);       // Key values used to pick minimum weight edge
        vector<bool> mstSet(vertices);   // To represent set of vertices included in MST
        
        // Initialize all keys as INFINITE
        for (int i = 0; i < vertices; i++) {
            key[i] = numeric_limits<int>::max();
            mstSet[i] = false;
        }
        
        // Always include first vertex in MST
        key[0] = 0;       // Make key 0 so this vertex is picked as first vertex
        parent[0] = -1;   // First node is always root of MST
        
        // The MST will have vertices-1 edges
        for (int count = 0; count < vertices - 1; count++) {
            // Pick the minimum key vertex from the set of vertices not yet included in MST
            int u = minDistance(key, mstSet);
            
            // Add the picked vertex to the MST Set
            mstSet[u] = true;
            
            // Update key value and parent index of the adjacent vertices of the picked vertex
            for (int v = 0; v < vertices; v++) {
                // Update the key only if the vertex is not in MST, there is an edge from u to v,
                // and weight of edge u-v is less than current key value of v
                if (adjMatrix[u][v] != numeric_limits<int>::max() && !mstSet[v] && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                }
            }
        }
        
        // Check if MST is connected
        bool isConnected = true;
        for (int i = 0; i < vertices; i++) {
            if (key[i] == numeric_limits<int>::max()) {
                isConnected = false;
                break;
            }
        }
        
        if (!isConnected) {
            cout << "\nThe graph is not connected. Cannot form a Minimum Spanning Tree." << endl;
            return;
        }
        
        // Print the constructed MST
        cout << "\nPrim's Minimum Spanning Tree:" << endl;
        int totalWeight = 0;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " -- " << i << " : " << adjMatrix[i][parent[i]] << endl;
            totalWeight += adjMatrix[i][parent[i]];
        }
        cout << "Total Weight of MST: " << totalWeight << endl;
    }
    
    // Kruskal's Algorithm for Minimum Spanning Tree
    void kruskalMST() {
        vector<pair<int, pair<int, int>>> edges; // (weight, (u, v))
        
        // Collect all edges from the adjacency matrix
        for (int i = 0; i < vertices; i++) {
            for (int j = i+1; j < vertices; j++) {
                // If there's an edge between i and j
                if (adjMatrix[i][j] != numeric_limits<int>::max()) {
                    edges.push_back({adjMatrix[i][j], {i, j}});
                }
            }
        }
        
        // Sort edges by weight
        sort(edges.begin(), edges.end());
        
        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);
        
        // Create V single-item sets
        for (int i = 0; i < vertices; i++) {
            parent[i] = i;
        }
        
        cout << "\nKruskal's Minimum Spanning Tree:" << endl;
        int totalWeight = 0;
        int edgeCount = 0;
        
        for (auto& edge : edges) {
            int u = edge.second.first;
            int v = edge.second.second;
            int weight = edge.first;
            
            int rootU = find(parent, u);
            int rootV = find(parent, v);
            
            // If including this edge doesn't cause a cycle
            if (rootU != rootV) {
                cout << u << " -- " << v << " : " << weight << endl;
                totalWeight += weight;
                unionSets(parent, rank, rootU, rootV);
                edgeCount++;
            }
        }
        
        // Check if MST is complete
        if (edgeCount != vertices - 1) {
            cout << "The graph is not connected. Cannot form a complete Minimum Spanning Tree." << endl;
        } else {
            cout << "Total Weight of MST: " << totalWeight << endl;
        }
    }
    
    // Dijkstra's Algorithm for Shortest Path
    void dijkstra(int src) {
        if (src < 0 || src >= vertices) {
            cout << "Invalid source vertex!" << endl;
            return;
        }
        
        vector<int> dist(vertices, numeric_limits<int>::max());
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);
        
        // Distance of source vertex from itself is always 0
        dist[src] = 0;
        
        // Find shortest path for all vertices
        for (int count = 0; count < vertices - 1; count++) {
            // Pick the minimum distance vertex from the set of vertices not yet processed
            int u = minDistance(dist, visited);
            
            // If we couldn't find a valid vertex, the graph is disconnected
            if (u == -1) break;
            
            // Mark the picked vertex as processed
            visited[u] = true;
            
            // Update dist value of the adjacent vertices of the picked vertex
            for (int v = 0; v < vertices; v++) {
                // Update dist[v] only if it's not in visited, there is an edge from u to v,
                // and total weight of path from src to v through u is smaller than current value of dist[v]
                if (!visited[v] && adjMatrix[u][v] != numeric_limits<int>::max() && 
                    dist[u] != numeric_limits<int>::max() && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }
        
        // Print the constructed distance array
        cout << "\nDijkstra's Shortest Paths from vertex " << src << ":" << endl;
        for (int i = 0; i < vertices; i++) {
            if (i != src) {
                if (dist[i] == numeric_limits<int>::max()) {
                    cout << "Vertex " << i << ": No path exists" << endl;
                } else {
                    cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path: ";
                    
                    // Print path
                    vector<int> path;
                    int current = i;
                    while (current != -1) {
                        path.push_back(current);
                        current = parent[current];
                    }
                    
                    // Print path in correct order
                    for (int j = path.size() - 1; j >= 0; j--) {
                        cout << path[j];
                        if (j > 0) cout << " -> ";
                    }
                    cout << endl;
                }
            }
        }
    }
    
    // Check if the graph is connected
    bool isConnected() {
        if (vertices == 0) return true;
        
        vector<bool> visited(vertices, false);
        
        // Start DFS from vertex 0
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v = 0; v < vertices; v++) {
                if (adjMatrix[u][v] != numeric_limits<int>::max() && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        
        // Check if all vertices are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        
        return true;
    }
};

int main() {
    int choice, vertices, u, v, weight, src;
    Graph* graph = nullptr;
    
    while (true) {
        cout << "\n===== GRAPH ADT MENU =====" << endl;
        cout << "1. Create a Graph" << endl;
        cout << "2. Add Edge" << endl;
        cout << "3. Remove Edge" << endl;
        cout << "4. Display Graph" << endl;
        cout << "5. Prim's MST Algorithm" << endl;
        cout << "6. Kruskal's MST Algorithm" << endl;
        cout << "7. Dijkstra's Shortest Path Algorithm" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter number of vertices: ";
                cin >> vertices;
                
                if (vertices <= 0) {
                    cout << "Number of vertices must be positive!" << endl;
                    break;
                }
                
                // Delete previous graph if exists
                if (graph != nullptr) {
                    delete graph;
                }
                
                graph = new Graph(vertices);
                cout << "Graph with " << vertices << " vertices created." << endl;
                break;
                
            case 2:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> weight;
                
                if (weight <= 0) {
                    cout << "Weight must be positive!" << endl;
                    break;
                }
                
                graph->addEdge(u, v, weight);
                cout << "Edge added: " << u << " -- " << v << " with weight " << weight << endl;
                break;
                
            case 3:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                cout << "Enter edge to remove (u v): ";
                cin >> u >> v;
                graph->removeEdge(u, v);
                cout << "Edge removed: " << u << " -- " << v << endl;
                break;
                
            case 4:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                graph->displayGraph();
                break;
                
            case 5:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                if (!graph->isConnected()) {
                    cout << "The graph is not connected. Prim's algorithm requires a connected graph." << endl;
                    break;
                }
                
                graph->primMST();
                break;
                
            case 6:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                graph->kruskalMST();
                break;
                
            case 7:
                if (graph == nullptr) {
                    cout << "Please create a graph first!" << endl;
                    break;
                }
                
                cout << "Enter source vertex: ";
                cin >> src;
                
                graph->dijkstra(src);
                break;
                
            case 8:
                cout << "Exiting program..." << endl;
                if (graph != nullptr) {
                    delete graph;
                }
                return 0;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}