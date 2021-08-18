#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<int> stacks[3];
int memo[101][101][101];

bool isGamePossible(int firstStackCurrentIndex, int secondStackCurrentIndex, int thirdStackCurrentIndex) {
    if (firstStackCurrentIndex == 0 && secondStackCurrentIndex == 0 && thirdStackCurrentIndex == 0) {
        return true;
    }
    if (memo[firstStackCurrentIndex][secondStackCurrentIndex][thirdStackCurrentIndex] != -1) {
        return memo[firstStackCurrentIndex][secondStackCurrentIndex][thirdStackCurrentIndex] == 1;
    }
    bool gameAlreadyPossible = false;
    if (firstStackCurrentIndex > 0) {
        if (stacks[0][firstStackCurrentIndex - 1] % 3 == 0) {
            gameAlreadyPossible = isGamePossible(firstStackCurrentIndex - 1, secondStackCurrentIndex, thirdStackCurrentIndex);
        }
        if (!gameAlreadyPossible && secondStackCurrentIndex > 0) {
            if ((stacks[0][firstStackCurrentIndex - 1] + stacks[1][secondStackCurrentIndex - 1]) % 3 == 0) {
                gameAlreadyPossible = isGamePossible(firstStackCurrentIndex - 1, secondStackCurrentIndex - 1, thirdStackCurrentIndex);
            }
            if (!gameAlreadyPossible && thirdStackCurrentIndex > 0) {
                if ((stacks[0][firstStackCurrentIndex - 1] + stacks[1][secondStackCurrentIndex - 1] + stacks[2][thirdStackCurrentIndex - 1]) % 3 == 0) {
                    gameAlreadyPossible = isGamePossible(firstStackCurrentIndex - 1, secondStackCurrentIndex - 1, thirdStackCurrentIndex - 1);
                }
            }
        }
        if (!gameAlreadyPossible && thirdStackCurrentIndex > 0) {
            if ((stacks[0][firstStackCurrentIndex - 1] + stacks[2][thirdStackCurrentIndex - 1]) % 3 == 0) {
                gameAlreadyPossible = isGamePossible(firstStackCurrentIndex - 1, secondStackCurrentIndex, thirdStackCurrentIndex - 1);
            }
        }
    }
    if (!gameAlreadyPossible && secondStackCurrentIndex > 0) {
        if (stacks[1][secondStackCurrentIndex - 1] % 3 == 0) {
            gameAlreadyPossible = isGamePossible(firstStackCurrentIndex, secondStackCurrentIndex - 1, thirdStackCurrentIndex);
        }
        if (!gameAlreadyPossible && thirdStackCurrentIndex > 0 && (stacks[1][secondStackCurrentIndex - 1] + stacks[2][thirdStackCurrentIndex - 1]) % 3 == 0) {
            gameAlreadyPossible = isGamePossible(firstStackCurrentIndex, secondStackCurrentIndex - 1, thirdStackCurrentIndex - 1);
        }
    }
    if (!gameAlreadyPossible && thirdStackCurrentIndex > 0) {
        if (stacks[2][thirdStackCurrentIndex - 1] % 3 == 0) {
            gameAlreadyPossible = isGamePossible(firstStackCurrentIndex, secondStackCurrentIndex, thirdStackCurrentIndex - 1);
        }
    }
    memo[firstStackCurrentIndex][secondStackCurrentIndex][thirdStackCurrentIndex] = gameAlreadyPossible ? 1 : 0;
    return gameAlreadyPossible;
}

int main(){ _
    int stackSize;
    int firstStackCard, secondStackCard, thirdStackCard;
    while (cin >> stackSize && stackSize != 0) {
        stacks[0].clear();
        stacks[1].clear();
        stacks[2].clear();
        fill(&memo[0][0][0], &memo[0][0][0] + sizeof(memo) / sizeof(int), -1);
        for (int i = 0; i < stackSize; i++) {
            cin >> firstStackCard >> secondStackCard >> thirdStackCard;
            stacks[0].insert(stacks[0].begin(), firstStackCard);
            stacks[1].insert(stacks[1].begin(), secondStackCard);
            stacks[2].insert(stacks[2].begin(), thirdStackCard);
        }
        cout << isGamePossible(stackSize, stackSize, stackSize) << endl;
    }
    return 0;
}
