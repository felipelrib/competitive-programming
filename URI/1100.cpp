#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f
#define VERTICES_AMOUNT 64

int graph[VERTICES_AMOUNT][VERTICES_AMOUNT];

void createKnightMovesGraph() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int toIndex;
            int fromIndex = i * 8 + j;
            // Create edge for each valid move possibility
            if (i - 2 >= 0 && j - 1 >= 0) {
                toIndex = (i - 2) * 8 + j - 1;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i - 2 >= 0 && j + 1 < 8) {
                toIndex = (i - 2) * 8 + j + 1;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i - 1 >= 0 && j - 2 >= 0) {
                toIndex = (i - 1) * 8 + j - 2;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i - 1 >= 0 && j + 2 < 8) {
                toIndex = (i - 1) * 8 + j + 2;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i + 1 < 8 && j - 2 >= 0) {
                toIndex = (i + 1) * 8 + j - 2;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i + 1 < 8 && j + 2 < 8) {
                toIndex = (i + 1) * 8 + j + 2;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i + 2 < 8 && j - 1 >= 0) {
                toIndex = (i + 2) * 8 + j - 1;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
            if (i + 2 < 8 && j + 1 < 8) {
                toIndex = (i + 2) * 8 + j + 1;
                graph[fromIndex][toIndex] = 1;
                graph[toIndex][fromIndex] = 1;
            }
        }
    }
}

vector<int> bfs(int source, int destination) {
    int previousVertex[VERTICES_AMOUNT];
    vector<int> path;
    fill_n(previousVertex, VERTICES_AMOUNT, -1);
    queue<int> bfsQueue;
    bfsQueue.push(source);
    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i < VERTICES_AMOUNT; i++) {
            if (previousVertex[i] == -1 && graph[currentVertex][i] > 0) {
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

int getCellIndexFromString(string cell) {
    int line = (int) cell[0] - 'a';
    int column = (int) cell[1] - '1';
    return line * 8 + column;
}

int main() { _
    createKnightMovesGraph();
    string fromCell, toCell;
    while (cin >> fromCell) {
        cin >> toCell;
        int fromCellIndex = getCellIndexFromString(fromCell);
        int toCellIndex = getCellIndexFromString(toCell);
        vector<int> shortestPath = bfs(fromCellIndex, toCellIndex);
        cout << "To get from " << fromCell << " to " << toCell << " takes " << shortestPath.size() - 1 << " knight moves." << endl;
    }
    return 0;
}
