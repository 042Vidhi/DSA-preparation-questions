#include <iostream>
#include <unordered_set>

using namespace std;
void helper(int marbles,int A,int B, unordered_set<int>&visited) {
        if (marbles <= 1 || visited.count(marbles)) {
            return;
        }
        visited.insert(marbles);
        helper(marbles - A,A,B,visited);
        helper(marbles - B,A,B,visited);
    };

int unique_marbles_count(int N, int A, int B) {
    unordered_set<int> visited;
    helper(N,A,B,visited);
    return visited.size();
}

int main() {
    int N = 4;
    int A = 2;
    int B = 1;
    int result = unique_marbles_count(N, A, B);
    cout <<"Result:"<< result << endl;
    return 0;
}
