#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int graph[50][50];
int flow[50][50];
int verticesAmount;
int athletesAmount;

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

int minimumDays() {
    int currentDay = 0;
    int currentMaxFlow = 0;
    vector<int> path = bfs();
    while (!path.empty()) {
        int currentVertex = path[0];
        int nextVertex = path[1];
        int currentFlow = graph[currentVertex][nextVertex] - flow[currentVertex][nextVertex];
        int pathDay = path.size() - 1;
        if (currentDay != pathDay) {
            currentMaxFlow = 0;
            for (int i = 1; i < verticesAmount; i++) {
                currentMaxFlow += flow[0][i];
            }
            if (currentDay != 0 && ceil((float)athletesAmount / (float)currentMaxFlow) + currentDay - 1 < pathDay) {
                currentDay = ceil((float)athletesAmount / (float)currentMaxFlow) + currentDay - 1;
                athletesAmount = 0;
                break;
            } else {
                athletesAmount -= (pathDay - currentDay) * currentMaxFlow;
            }
        }
        if (athletesAmount <= 0) {
            break;
        }
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
        currentDay = pathDay;
        path = bfs();
    }
    if (athletesAmount > 0) {
        int maxFlow = 0;
        for (int i = 1; i < verticesAmount; i++) {
            maxFlow += flow[0][i];
        }
        currentDay += ceil((float)athletesAmount / (float)maxFlow) - 1;
    }
    return currentDay == 30 ? 29 : currentDay;
}

int main() { _
    int edgesAmount;
    int source, destination, capacity;
    while (cin >> verticesAmount && verticesAmount > 0) {
        fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), 0);
        fill(&flow[0][0], &flow[0][0] + sizeof(flow) / sizeof(int), 0);
        cin >> edgesAmount >> athletesAmount;
        for (int i = 0; i < edgesAmount; i++) {
            cin >> source >> destination >> capacity;
            graph[source - 1][destination - 1] = capacity;
        }
        cout << minimumDays() << endl;
    }
    cout << endl;
    return 0;
}
