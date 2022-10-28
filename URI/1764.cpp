#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<int, int>> graph[40000];
int verticesAmount;

typedef pair<int, int> VertexWeight;

ll prim() {
    auto compareLesserWeight = [](VertexWeight firstElement, VertexWeight secondElement) {
        return firstElement.second > secondElement.second;
    };
    priority_queue<VertexWeight, vector<VertexWeight>, decltype(compareLesserWeight)> primQueue(compareLesserWeight);
    bool vertexAlreadyUsed[40000];
    int minimumValueForVertex[40000];
    ll minimumSpanningTreeWeightSum = 0;

    fill_n(vertexAlreadyUsed, verticesAmount, 0);
    fill_n(minimumValueForVertex, verticesAmount, INF);

    // Add first vertex with weight 0.
    primQueue.push(make_pair(0, 0));
    for (int i = 0; i < verticesAmount; i++) {
        int currentVertex;
        int currentWeight;

        // Due to not having an "extract-min" operation, allows inserting the
        // same vertex more than once, as long as the minimum weight for it is
        // retrieved at the correct time.
        do {
            pair<int, int> vertexWeightPair = primQueue.top();
            currentVertex = vertexWeightPair.first;
            currentWeight = vertexWeightPair.second;
            primQueue.pop();
        } while (vertexAlreadyUsed[currentVertex]);

        minimumSpanningTreeWeightSum += currentWeight;
        vertexAlreadyUsed[currentVertex] = true;

        // Discover all adjacent vertices from the current one.
        for (pair<int, int> edge : graph[currentVertex]) {
            int destinationVertex = edge.first;
            int edgeWeight = edge.second;
            if (edgeWeight > 0 && !vertexAlreadyUsed[destinationVertex] && edgeWeight < minimumValueForVertex[destinationVertex]) {
                minimumValueForVertex[destinationVertex] = edgeWeight;
                primQueue.push(make_pair(destinationVertex, edgeWeight));
            }
        }
    }

    return minimumSpanningTreeWeightSum;
}

int main() { _
    int edgesAmount;
    while (cin >> verticesAmount && verticesAmount > 0) {
        cin >> edgesAmount;

        for (int i = 0; i < verticesAmount; i++) {
            graph[i].clear();
        }

        for (int i = 0; i < edgesAmount; i++) {
            int firstVertex, secondVertex, weight;
            cin >> firstVertex >> secondVertex >> weight;

            graph[firstVertex].push_back(make_pair(secondVertex, weight));
            graph[secondVertex].push_back(make_pair(firstVertex, weight));
        }

        ll minimumSpanningTreeWeightSum = prim();
        cout << minimumSpanningTreeWeightSum << endl;
    }
    return 0;
}
