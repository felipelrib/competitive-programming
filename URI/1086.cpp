#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int height, width;
int plankHeight, plankWidth, planksAmount;
int horizontalAmount, verticalAmount;
vector<int> planksWidth;

int minimumPlanksAmountHorizontal() {
    int minimumPlanksAmount = -1;
    int lastUsedFirstIndex = -1;
    if (height % plankHeight == 0) {
        int currentRows = 0;
        int targetRows = height / plankHeight;
        int usedPlanksAmount = 0;
        for (int i = planksAmount - 1; i >= 0; i--) {
            if (planksWidth[i] == width) {
                currentRows++;
                usedPlanksAmount++;
            } else if (planksWidth[i] < width) {
                for (int j = lastUsedFirstIndex + 1; j < i; j++) {
                    if (planksWidth[i] + planksWidth[j] == width) {
                        currentRows++;
                        usedPlanksAmount += 2;
                        lastUsedFirstIndex = j;
                        break;
                    } else if (planksWidth[i] + planksWidth[j] > width) {
                        break;
                    }
                }
            }
            if (currentRows == targetRows) {
                minimumPlanksAmount = usedPlanksAmount;
                break;
            }
        }
    }
    return minimumPlanksAmount;
}

int minimumPlanksAmountVertical() {
    int minimumPlanksAmount = -1;
    int lastUsedFirstIndex = -1;
    if (width % plankHeight == 0) {
        int currentRows = 0;
        int targetRows = width / plankHeight;
        int usedPlanksAmount = 0;
        for (int i = planksAmount - 1; i >= 0; i--) {
            if (planksWidth[i] == height) {
                currentRows++;
                usedPlanksAmount++;
            } else if (planksWidth[i] < height) {
                for (int j = lastUsedFirstIndex + 1; j < i; j++) {
                    if (planksWidth[i] + planksWidth[j] == height) {
                        currentRows++;
                        usedPlanksAmount += 2;
                        lastUsedFirstIndex = j;
                        break;
                    } else if (planksWidth[i] + planksWidth[j] > height) {
                        break;
                    }
                }
            }
            if (currentRows == targetRows) {
                minimumPlanksAmount = usedPlanksAmount;
                break;
            }
        }
    }
    return minimumPlanksAmount;
}

int main(){ _
    cin >> height >> width;
    while (height != 0) {
        cin >> plankHeight;
        cin >> planksAmount;
        for (int i = 0; i < planksAmount; i++) {
            cin >> plankWidth;
            planksWidth.push_back(plankWidth * 100);
        }
        height *= 100;
        width *= 100;
        sort(planksWidth.begin(), planksWidth.end());
        if (height % plankHeight == 0 && width % plankHeight == 0) {
            if (height * 2 <= width) {
                horizontalAmount = minimumPlanksAmountHorizontal();
                if (horizontalAmount != -1) {
                    verticalAmount = -1;
                } else {
                    verticalAmount = minimumPlanksAmountVertical();
                }
            } else if (width * 2 <= height) {
                verticalAmount = minimumPlanksAmountVertical();
                if (verticalAmount != -1) {
                    horizontalAmount = -1;
                } else {
                    horizontalAmount = minimumPlanksAmountHorizontal();
                }
            } else {
                horizontalAmount = minimumPlanksAmountHorizontal();
                verticalAmount = minimumPlanksAmountVertical();
            }
        } else {
            horizontalAmount = minimumPlanksAmountHorizontal();
            verticalAmount = minimumPlanksAmountVertical();
        }
        if (horizontalAmount != -1 || verticalAmount != -1) {
            if (horizontalAmount == -1 || verticalAmount == -1) {
                cout << (horizontalAmount != -1 ? horizontalAmount : verticalAmount) << endl;
            } else {
                cout << (horizontalAmount < verticalAmount ? horizontalAmount : verticalAmount) << endl;
            }
        } else {
            cout << "impossivel" << endl;
        }
        planksWidth.clear();
        cin >> height >> width;
    }
    return 0;
}
