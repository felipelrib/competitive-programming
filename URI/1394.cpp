#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

// 40 + 40 * 39 / 2 + 2
map<int, int> graph[822];
int flow[822][822];
int verticesAmount;
int matchesAmount;

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
        for (auto it = graph[currentVertex].begin(); it != graph[currentVertex].end(); it++) {
            int i = it->first;
            int value = it->second;
            if (previousVertex[i] == -1 && value - flow[currentVertex][i] > 0) {
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
            if (graph[nextVertex].find(currentVertex) == graph[nextVertex].end()) {
                graph[nextVertex][currentVertex] = 0;
            }
        }
        path = bfs();
    }
    for (int i = 1; i <= matchesAmount; i++) {
        maxFlow += flow[0][i];
    }
    return maxFlow;
}

int main() { _
    int teamsAmount, correspondingNumber, finishedMatches;
    int firstTeam, secondTeam;
    char result;
    int totalPoints[40];
    int matchesRemainingForTeam[40];
    int maximumPointsForFirstTeam;
    map<char, int> resultValue {
        {'<', 0},
        {'=', 1}
    };
    while (cin >> teamsAmount && teamsAmount != 0) {
        cin >> correspondingNumber >> finishedMatches;
        matchesAmount = teamsAmount * (teamsAmount - 1) / 2;
        verticesAmount = teamsAmount + matchesAmount + 2; // Teams + matches + source + sink
        for (int i = 0; i < 822; i++) {
            graph[i].clear();
        }
        fill(&flow[0][0], &flow[0][0] + sizeof(flow) / sizeof(int), 0);
        fill_n(totalPoints, 40, 0);
        fill_n(matchesRemainingForTeam, 40, (teamsAmount - 1) * correspondingNumber);
        for (int i = 1; i <= matchesAmount; i++) {
            graph[0][i] = correspondingNumber * 2;
        }
        for (int i = 0; i < finishedMatches; i++) {
            cin >> firstTeam >> result >> secondTeam;
            totalPoints[firstTeam] += resultValue[result];
            totalPoints[secondTeam] += 2 - resultValue[result];

            // Gave up on creating a formula for this
            int minimumIndex = min(firstTeam, secondTeam);
            int maximumIndex = max(firstTeam, secondTeam);
            int matchIndex = maximumIndex - minimumIndex - 1;
            for (int j = 0; j < minimumIndex; j++) {
                matchIndex += teamsAmount - 1 - j;
            }
            graph[0][1 + matchIndex] -= 2;

            matchesRemainingForTeam[firstTeam]--;
            matchesRemainingForTeam[secondTeam]--;
        }

        maximumPointsForFirstTeam = totalPoints[0] + 2 * matchesRemainingForTeam[0];
        graph[matchesAmount + 1][verticesAmount - 1] = maximumPointsForFirstTeam - totalPoints[0];
        bool canWin = true;
        for (int i = 1; i < teamsAmount; i++) {
            if (totalPoints[i] >= maximumPointsForFirstTeam) {
                canWin = false;
                break;
            }
            int maximumPointsAmount = maximumPointsForFirstTeam - totalPoints[i] - 1;
            graph[matchesAmount + i + 1][verticesAmount - 1] = maximumPointsAmount;
        }
        if (!canWin) {
            cout << 'N' << endl;
        } else {
            // Fill all matches to teams as total points available
            for (int i = 0, matchIndex = 1; i < teamsAmount - 1; i++) {
                for (int j = i + 1; j < teamsAmount; j++, matchIndex++) {
                    graph[matchIndex][matchesAmount + i + 1] = graph[0][matchIndex];
                    graph[matchIndex][matchesAmount + j + 1] = graph[0][matchIndex];
                }
            }
            cout << (maxFlow() == ((matchesAmount * correspondingNumber) - finishedMatches) * 2 ? 'Y' : 'N') << endl;
        }
    }
    return 0;
}
