#include <bits/stdc++.h>
using namespace std;

int minPlantsToMakeBobHappy(string str) {
    int n = str.length();
    int cnt = 0;

    // Check how many characters match from the beginning and end of the string.
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    string str;
    cin >> str;

    int minPlants = minPlantsToMakeBobHappy(str);

    cout << minPlants << endl;

    return 0;
}
