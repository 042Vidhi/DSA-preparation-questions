// You are given N points with non-negative integer x
// and y-coordinates. Your task is to count the num-
// ber of right-angled triangles that can be formed
// using these points as vertices such that one side of
// the triangle is parallel to the x-axis and another
// side is parallel to the y-axis.

// Input format
// The first line of input is an integer N, denoting the number of points. This is followed by
// N lines of input, each containing two integers, separated by a space, specifying the x and y
// coordinate of one point. You may assume that each coordinate x and y lies in the range 0
// to 10^5.

// Output format
// Your output should be a single integer, denoting the number of right-angled triangles of the
// stated type that can be formed from the input points.
// Output the answer modulo 10^4.

// Example
// INPUT
// 3
// 0 0
// 0 1
// 1 0

// OUTPUT
// 1

// CONSTRAINTS
// N<= 10^5

// https://www.codechef.com/problems/CORE4?tab=statement

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_map<int,int> umap_x,umap_y;
	int n;
	cin>>n;
	vector<int> cx(n);
	vector<int> cy(n);
	for(int i=0; i<n; ++i){
	    cin>>cx[i]>>cy[i];
	}
	
	for(int i=0; i<n; ++i){
	    umap_x[cx[i]]++;
	    umap_y[cy[i]]++;
	}
	
	int ans = 0;
	for(int i=0; i<n; ++i){
	    ans += (umap_x[cx[i]] - 1)*(umap_y[cy[i]] - 1);
	}
	cout<<ans%10000<<endl;
	
	
	return 0;
}
