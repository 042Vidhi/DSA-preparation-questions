

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
	if(a.first!=b.first)
    return a.first <= b.first;
	return a.second<b.second;
}

int lastOccurence(int n, int m, const vector<vector<int>>& arr, int i) {
    int l = 0, h = m - 1;
    int last = -1;

    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[i][mid] == 1) {
            last = mid;
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    return last;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> rows;
    for (int i = 0; i < n; i++) {
        int last = lastOccurence(n, m, arr, i);
        rows.push_back(make_pair(last + 1, i));
    }

    sort(rows.begin(), rows.end(), comparator);

    for (int i = 0; i < n; i++) {
        cout << rows[i].second << " ";
    }

    return 0;
}
