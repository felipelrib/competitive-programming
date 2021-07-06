#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<int, int>> graph[1010];
int verticesAmount;

int getMinimumIndex(int minimumDistance[], bool visited[]) {
    int minimumIndex = -1;
    int minimumValue = INF;
    for (int i = 0; i < verticesAmount; i++) {
        if (minimumDistance[i] < minimumValue && !visited[i]) {
            minimumIndex = i;
            minimumValue = minimumDistance[i];
        }
    }
    return minimumIndex;
}

int getMaximumIndex(int maximumDistance[], bool visited[]) {
    int maximumIndex = -1;
    int maximumValue = 0;
    for (int i = 0; i < verticesAmount; i++) {
        if (maximumDistance[i] > maximumValue && !visited[i]) {
            maximumIndex = i;
            maximumValue = maximumDistance[i];
        }
    }
    return maximumIndex;
}

int minimumTree() {
    int minimumDistance[verticesAmount];
    int minimumTreeSum = 0;
    bool visited[verticesAmount] = {false};
    int currentVertex = 0;

    fill_n(minimumDistance, verticesAmount, INF);
    minimumDistance[currentVertex] = 0;

    while (currentVertex != -1) {
        minimumTreeSum += minimumDistance[currentVertex];
        for (pair<int, int> edge : graph[currentVertex]) {
            int destinationVertex = edge.first;
            int weight = edge.second;
            if (weight < minimumDistance[destinationVertex]) {
                minimumDistance[destinationVertex] = weight;
            }
        }
        visited[currentVertex] = true;
        currentVertex = getMinimumIndex(minimumDistance, visited);
    }
    return minimumTreeSum;
}

int maximumTree() {
    int maximumDistance[verticesAmount] = {0};
    int maximumTreeSum = 0;
    bool visited[verticesAmount] = {false};
    int currentVertex = 0;

    while (currentVertex != -1) {
        maximumTreeSum += maximumDistance[currentVertex];
        for (pair<int, int> edge : graph[currentVertex]) {
            int destinationVertex = edge.first;
            int weight = edge.second;
            if (weight > maximumDistance[destinationVertex]) {
                maximumDistance[destinationVertex] = weight;
            }
        }
        visited[currentVertex] = true;
        currentVertex = getMaximumIndex(maximumDistance, visited);
    }
    return maximumTreeSum;
}

int main(){ _
    int edgesAmount;
    int startingVertex, destinationVertex, weight;
    cin >> edgesAmount;
    verticesAmount = 0;
    for (int i = 0; i < edgesAmount; i++) {
        cin >> startingVertex >> destinationVertex >> weight;
        destinationVertex--;
        startingVertex--;
        if (destinationVertex > verticesAmount) {
            verticesAmount = destinationVertex;
        }
        if (startingVertex > verticesAmount) {
            verticesAmount = destinationVertex;
        }
        graph[startingVertex].push_back(make_pair(destinationVertex, weight));
        graph[destinationVertex].push_back(make_pair(startingVertex, weight));
    }
    verticesAmount++;
    cout << maximumTree() << endl;
    cout << minimumTree() << endl;
    return 0;
}
