#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int graph[38][38];
int flow[38][38];
int verticesAmount;
unordered_map<string, int> shirtTypeToIndex{
    {"XXL", 1},
    {"XL", 2},
    {"L", 3},
    {"M", 4},
    {"S", 5},
    {"XS", 6}
};

vector<int> bfs() {
    int previousVertex[verticesAmount];
    int source = 0;
    int destination = verticesAmount - 1;
    vector<int> path;
    fill_n(previousVertex, verticesAmount, -1);
    queue<int> bfsQueue;
    bfsQueue.push(source);
    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i < verticesAmount; i++) {
            if (previousVertex[i] == -1 && graph[currentVertex][i] - flow[currentVertex][i] > 0) {
                previousVertex[i] = currentVertex;
                if (i == destination) {
                    while (i != source) {
                        path.insert(path.begin(), i);
                        i = previousVertex[i];
                    }
                    path.insert(path.begin(), i);
                    // Return the shortest path if found.
                    return path;
                } else {
                    bfsQueue.push(i);
                }
            }
        }
    }
    return path;
}

int maxFlow() {
    int maxFlow = 0;
    vector<int> path = bfs();
    while (!path.empty()) {
        int currentVertex = path[0];
        int nextVertex = path[1];
        int currentFlow = graph[currentVertex][nextVertex] - flow[currentVertex][nextVertex];
        int pathDay = path.size() - 1;
        for (int i = 1; i < pathDay; i++) {
            currentVertex = path[i];
            nextVertex = path[i + 1];
            currentFlow = min(currentFlow, graph[currentVertex][nextVertex] - flow[currentVertex][nextVertex]);
        }
        for (int i = 0; i < pathDay; i++) {
            currentVertex = path[i];
            nextVertex = path[i + 1];
            flow[currentVertex][nextVertex] += currentFlow;
            // Residual edge.
            flow[nextVertex][currentVertex] -= currentFlow;
        }
        path = bfs();
    }
    for (int i = 1; i < verticesAmount; i++) {
        maxFlow += flow[0][i];
    }
    return maxFlow;
}

int main() { _
    int testCasesAmount;
    int shirtsAmount, volunteersAmount;
    string shirtType;
    cin >> testCasesAmount;
    for (int i = 0; i < testCasesAmount; i++) {
        cin >> shirtsAmount >> volunteersAmount;
        verticesAmount = volunteersAmount + 8; // 6 from the shirts types, 2 from source and sink.
        fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), 0);
        fill(&flow[0][0], &flow[0][0] + sizeof(flow) / sizeof(int), 0);
        // Defines the flow from the source vertex.
        for (int i = 1, amountOfEachShirtType = shirtsAmount / 6; i <= 6; i++) {
            graph[0][i] = amountOfEachShirtType;
        }
        for (int i = 1; i <= volunteersAmount; i++) {
            cin >> shirtType;
            graph[shirtTypeToIndex[shirtType]][i + 6] = 1;
            cin >> shirtType;
            graph[shirtTypeToIndex[shirtType]][i + 6] = 1;
            // Defines the flow to the sink vertex.
            graph[i + 6][verticesAmount - 1] = 1;
        }
        cout << (maxFlow() == volunteersAmount ? "YES" : "NO") << endl;
    }
    return 0;
}
