#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

bool graph[1002][1002] = {false};
int weights[1002] = {0};
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

int shortestPath(int startingVertex, int destinationVertex) {
    int minimumDistance[verticesAmount];
    bool visited[verticesAmount] = {false};
    int currentVertex = startingVertex;

    fill_n(minimumDistance, verticesAmount, INF);
    minimumDistance[startingVertex] = 0;

    while (currentVertex != -1) {
        int currentDistance = minimumDistance[currentVertex];
        for (int i = 0; i < verticesAmount; i++) {
            if (graph[currentVertex][i] && currentDistance + weights[i] < minimumDistance[i]) {
                minimumDistance[i] = currentDistance + weights[i];
            }
        }
        visited[currentVertex] = true;
        currentVertex = getMinimumIndex(minimumDistance, visited);
    }
    minimumDistance[destinationVertex] += weights[startingVertex];
    return minimumDistance[destinationVertex];
}

int main(){ _
    int edgesAmount, ammunitionAmount;
    int snipersAmount, sniperPosition;
    int startingVertex, destinationVertex;
    int minimumSnipersThroughPathAmount;
    double hitProbability;
    double successProbability = 0;
    while (cin >> verticesAmount) {
        fill(&graph[0][0], &graph[0][0] + sizeof(graph), false);
        memset(weights, 0, sizeof(weights));
        cin >> edgesAmount >> ammunitionAmount >> hitProbability;
        for (int i = 0; i < edgesAmount; i++) {
            int firstVertex, secondVertex;
            cin >> firstVertex >> secondVertex;
            graph[firstVertex - 1][secondVertex - 1] = true;
            graph[secondVertex - 1][firstVertex - 1] = true;
        }
        cin >> snipersAmount;
        for (int i = 0; i < snipersAmount; i++) {
            cin >> sniperPosition;
            weights[sniperPosition - 1]++;
        }
        cin >> startingVertex >> destinationVertex;
        minimumSnipersThroughPathAmount = shortestPath(startingVertex - 1, destinationVertex - 1);
        successProbability = 0;
        if (minimumSnipersThroughPathAmount <= ammunitionAmount) {
            successProbability = pow(hitProbability, minimumSnipersThroughPathAmount);
        }
        cout << fixed << setprecision(3) << successProbability << endl;
    }
    return 0;
}
