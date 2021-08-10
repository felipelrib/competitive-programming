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

int shortestPathsDifference(int startingVertex) {
    int minimumDistance[verticesAmount];
    bool visited[verticesAmount] = {false};
    int currentVertex = startingVertex;

    fill_n(minimumDistance, verticesAmount, INF);
    minimumDistance[startingVertex] = 0;

    while (currentVertex != -1) {
        int currentDistance = minimumDistance[currentVertex];
        for (pair<int, int> edge : graph[currentVertex]) {
            int destinationVertex = edge.first;
            int weight = edge.second;
            if (currentDistance + weight < minimumDistance[destinationVertex]) {
                minimumDistance[destinationVertex] = currentDistance + weight;
            }
        }
        visited[currentVertex] = true;
        currentVertex = getMinimumIndex(minimumDistance, visited);
    }
    int minimumPing = INF, maximumPing = 0;
    for (int i = 0; i < verticesAmount; i++) {
        if (i != startingVertex) {
            if (minimumDistance[i] < minimumPing) {
                minimumPing = minimumDistance[i];
            }
            if (minimumDistance[i] > maximumPing) {
                maximumPing = minimumDistance[i];
            }
        }
    }
    return maximumPing - minimumPing;
}

int main(){ _
    int edgesAmount;
    int startingVertex, destinationVertex, weight;
    int serverIndex;
    cin >> verticesAmount >> edgesAmount;
    for (int i = 0; i < edgesAmount; i++) {
        cin >> startingVertex >> destinationVertex >> weight;
        destinationVertex--;
        startingVertex--;
        graph[startingVertex].push_back(make_pair(destinationVertex, weight));
        graph[destinationVertex].push_back(make_pair(startingVertex, weight));
    }
    cin >> serverIndex;
    serverIndex--;

    cout << shortestPathsDifference(serverIndex) << endl;
    return 0;
}
