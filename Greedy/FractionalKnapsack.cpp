// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get 
// the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 
// Example 1:
// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(Item a,Item b)
    {
        return (a.value*b.weight) > (b.value*a.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        sort(arr,arr+n,cmp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(W-arr[i].weight>=0)
            {
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else{
                double r=(W*arr[i].value*1.0)/arr[i].weight;
                ans+=r;
                break;
            }
        }
        
        return ans;
    }
        
};


int main(){
    int t; cin >> t;
    while(t--){
        int n, w;
        cin >> n>> w;

        Item arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i].value >> arr[i].weight;
        }
        Solution ob;
        cout << ob.fractionalKnapsack(w, arr, n) << endl;
    }
    return 0;
}