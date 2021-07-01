#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

bool graph[26][26] = {false};
int verticesAmount;

void bfs() {
    bool visitedVertices[verticesAmount] = {false};
    int firstVertex = 0;
    int componentsAmount = 0;
    int baseValue = 97; // 'a' to int.
    bool anotherComponent = false;
    queue<int> bfsQueue;
    vector<char> currentComponent;
    for(int i = 0; i < verticesAmount; i++) {
        if (!visitedVertices[i]) {
            bfsQueue.push(i);
            while(bfsQueue.size() > 0) {
                int currentVertex = bfsQueue.front();
                bfsQueue.pop();
                for(int j = 0; j < verticesAmount; j++) {
                    if ((graph[currentVertex][j] || currentVertex == j) && !visitedVertices[j]) {
                        currentComponent.push_back((char)(baseValue + j));
                        if (!anotherComponent) {
                            componentsAmount++;
                            anotherComponent = true;
                        }
                        if (currentVertex != j) {
                            bfsQueue.push(j);
                        }
                        visitedVertices[j] = true;
                    }
                }
            }
            if (anotherComponent) {
                sort(currentComponent.begin(), currentComponent.end());
                for (char vertex : currentComponent) {
                    cout << vertex << ',';
                }
                currentComponent.clear();
                cout << endl;
                anotherComponent = false;
            }
        }
    }
    cout << componentsAmount << " connected components" << endl << endl;
}

int main(){ _
    int testCases;
    int edgesAmount;
    char firstVertex, secondVertex;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cout << "Case #" << i + 1 << ":" << endl;
        cin >> verticesAmount >> edgesAmount;
        fill(&graph[0][0], &graph[0][0] + sizeof(graph), false);
        for (int j = 0; j < edgesAmount; j++) {
            cin >> firstVertex >> secondVertex;
            graph[firstVertex - 'a'][secondVertex - 'a'] = true;
            graph[secondVertex - 'a'][firstVertex - 'a'] = true;
        }
        bfs();
    }
    return 0;
}
