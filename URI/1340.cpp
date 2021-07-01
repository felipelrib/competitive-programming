#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

int main(){ _
    int operationsAmount;
    int operation, number;
    queue<int> queueTest;
    stack<int> stackTest;
    priority_queue<int> priorityQueueTest;
    while (cin >> operationsAmount) {
        bool canBeQueue = true;
        bool canBeStack = true;
        bool canBePriorityQueue = true;
        for (int i = 0; i < operationsAmount; i++) {
            cin >> operation >> number;
            if (operation == 1) {
                queueTest.push(number);
                stackTest.push(number);
                priorityQueueTest.push(number);
            } else {
                if (queueTest.front() != number) {
                    canBeQueue = false;
                }
                if (stackTest.top() != number) {
                    canBeStack = false;
                }
                if (priorityQueueTest.top() != number) {
                    canBePriorityQueue = false;
                }
                queueTest.pop();
                stackTest.pop();
                priorityQueueTest.pop();
            }
        }
        if ((canBeQueue ^ canBeStack ^ canBePriorityQueue) && !(canBeQueue && canBeStack && canBePriorityQueue)) {
            if (canBeQueue) {
                cout << "queue" << endl;
            } else if (canBeStack) {
                cout << "stack" << endl;
            } else {
                cout << "priority queue" << endl;
            }
        } else if (canBeQueue || canBeStack || canBePriorityQueue) {
            cout << "not sure" << endl;
        } else {
            cout << "impossible" << endl;
        }
        queueTest = queue<int>();
        stackTest = stack<int>();
        priorityQueueTest = priority_queue<int>();
    }
    return 0;
}
