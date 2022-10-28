#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int graph[2500][2500];
int accessibleCells[2500];
int verticesAmount;

void bfs(int source) {
    vector<int> path;
    queue<int> bfsQueue;
    bfsQueue.push(source);
    accessibleCells[source] = 3;
    while (!bfsQueue.empty()) {
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        for (int i = 0; i < verticesAmount; i++) {
            if (accessibleCells[i] == 1 && graph[currentVertex][i] > 0) {
                accessibleCells[i] = 3;
                bfsQueue.push(i);
            }
        }
    }
}

void printMap(int rowsAmount, int columnsAmount) {
    for (int i = 0; i < rowsAmount; i++) {
        for (int j = 0; j < columnsAmount; j++) {
            int currentIndex = i * columnsAmount + j;
            char currentCellRepresentation;
            switch (accessibleCells[currentIndex]) {
                case 0:
                    currentCellRepresentation = 'X';
                    break;
                case 1:
                    currentCellRepresentation = 'A';
                    break;
                case 2:
                case 3:
                    currentCellRepresentation = 'T';
                    break;
                default:
                    throw "There's something *really* wrong";
            }
            cout << currentCellRepresentation;
        }
        cout << endl;
    }
}

int main() { _
    int rowsAmount, columnsAmount;
    queue<int> startingCells;
    string shirtType;
    while (cin >> rowsAmount && rowsAmount > 0) {
        cin >> columnsAmount;
        verticesAmount = rowsAmount * columnsAmount;
        fill(&graph[0][0], &graph[0][0] + sizeof(graph) / sizeof(int), 0);
        fill_n(&accessibleCells[0], 2500, 0);
        for (int i = 0; i < rowsAmount; i++) {
            string currentRow;
            cin >> currentRow;
            for (int j = 0; j < columnsAmount; j++) {
                if (currentRow[j] == 'A' || currentRow[j] == 'T') {
                    int adjacentCellIndex;
                    int currentIndex = i * columnsAmount + j;
                    if (currentRow[j] == 'A') {
                        accessibleCells[currentIndex] = 1;
                    } else {
                        accessibleCells[currentIndex] = 2;
                        startingCells.push(currentIndex);
                    }

                    // Add edges to adjacent accessible cells.
                    if (i - 1 >= 0) {
                        adjacentCellIndex = (i - 1) * columnsAmount + j;
                        graph[currentIndex][adjacentCellIndex] = 1;
                        graph[adjacentCellIndex][currentIndex] = 1;
                    }
                    if (i + 1 < rowsAmount) {
                        adjacentCellIndex = (i + 1) * columnsAmount + j;
                        graph[currentIndex][adjacentCellIndex] = 1;
                        graph[adjacentCellIndex][currentIndex] = 1;
                    }
                    if (j - 1 >= 0) {
                        adjacentCellIndex = i * columnsAmount + j - 1;
                        graph[currentIndex][adjacentCellIndex] = 1;
                        graph[adjacentCellIndex][currentIndex] = 1;
                    }
                    if (j + 1 < columnsAmount) {
                        adjacentCellIndex = i * columnsAmount + j + 1;
                        graph[currentIndex][adjacentCellIndex] = 1;
                        graph[adjacentCellIndex][currentIndex] = 1;
                    }
                }
            }
        }
        while (!startingCells.empty()) {
            int currentVertex = startingCells.front();
            startingCells.pop();
            if (accessibleCells[currentVertex] == 2) {
                bfs(currentVertex);
            }
        }
        printMap(rowsAmount, columnsAmount);
        cout << endl;
    }
    return 0;
}
