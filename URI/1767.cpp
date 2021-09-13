#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

#define ll long long

#define INF 0x3f3f3f3f

vector<pair<int, int>> packages;
vector<unordered_map<int, int>> dynamicMatrix;
int packagesAmount;

int getMaximumToysAmount(int currentIndex, int currentCapacity) {
    if (currentIndex == -1 || currentCapacity == 0) {
        return 0;
    }
    int maximumToys;
    if (dynamicMatrix[currentIndex].find(currentCapacity) != dynamicMatrix[currentIndex].end()) {
        maximumToys = dynamicMatrix[currentIndex][currentCapacity];
    } else {
        if (packages[currentIndex].second > currentCapacity) {
            maximumToys = getMaximumToysAmount(currentIndex - 1, currentCapacity);
        } else {
            int toysWithCurrentPackage = packages[currentIndex].first + getMaximumToysAmount(currentIndex - 1, currentCapacity - packages[currentIndex].second);
            int toysWithoutCurrentPackage = getMaximumToysAmount(currentIndex - 1, currentCapacity);
            maximumToys = max(toysWithCurrentPackage, toysWithoutCurrentPackage);
        }
        dynamicMatrix[currentIndex][currentCapacity] = maximumToys;
    }
    return maximumToys;
}

int main(){ _
    int testCases;
    int toysAmount, packageWeight;
    int weight, selectedPackagesAmount;
    bool selectedPackages[100];
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> packagesAmount;
        packages.clear();
        dynamicMatrix.clear();
        fill_n(selectedPackages, 100, false);
        for (int j = 0; j < packagesAmount; j++) {
            cin >> toysAmount >> packageWeight;
            packages.push_back(make_pair(toysAmount, packageWeight));
            unordered_map<int, int> map{};
            dynamicMatrix.push_back(map);
        }
        int maximumToysAmount = getMaximumToysAmount(packagesAmount - 1, 50);
        weight = 50;
        selectedPackagesAmount = 0;
        for (int i = packagesAmount - 1; i > 0; i--) {
            if (dynamicMatrix[i][weight] > dynamicMatrix[i - 1][weight]) {
                selectedPackages[i] = true;
                weight -= packages[i].second;
                selectedPackagesAmount++;
            }
        }
        if (dynamicMatrix[0][weight] > 0) {
            weight -= packages[0].second;
            selectedPackagesAmount++;
        }
        cout << maximumToysAmount << " brinquedos" << endl;
        cout << "Peso: " << 50 - weight << " kg" << endl;
        cout << "sobra(m) " << packagesAmount - selectedPackagesAmount << " pacote(s)" << endl << endl;
    }
    return 0;
}
