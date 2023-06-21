// Watchmen are in a danger and Doctor Manhattan together with his friend Daniel Dreiberg should warn them as soon as possible. There are n watchmen on a plane, the i-th watchman is located at point (xi, yi).

// They need to arrange a plan, but there are some difficulties on their way. As you know, Doctor Manhattan considers the distance between watchmen i and j to be |xi - xj| + |yi - yj|. Daniel, as an ordinary person, calculates the distance using the formula [(xi-xj)^2 + (yi-yj)^2]^1/2.

// The success of the operation relies on the number of pairs (i, j) (1 ≤ i < j ≤ n), such that the distance between watchman i and watchmen j calculated by Doctor Manhattan is equal to the distance between them calculated by Daniel. You were asked to compute the number of such pairs.

// Input
// The first line of the input contains the single integer n (1 ≤ n ≤ 200 000) — the number of watchmen.

// Each of the following n lines contains two integers xi and yi (|xi|, |yi| ≤ 109).

// Some positions may coincide.

// Output
// Print the number of pairs of watchmen such that the distance between them calculated by Doctor Manhattan is equal to the distance calculated by Daniel.

// Examples
// inputCopy
// 3
// 1 1
// 7 5
// 1 5
// outputCopy
// 2
// inputCopy
// 6
// 0 0
// 0 1
// 0 2
// -1 1
// 0 1
// 1 1
// outputCopy
// 11
// Note
// In the first sample, the distance between watchman 1 and watchman 2 is equal to |1 - 7| + |1 - 5| = 10 for Doctor Manhattan and [(1-7)^2 + (1-5)^2]^1/2 = 3.(13)^1/2 for Daniel. For pairs (1, 1), (1, 5) and (7, 5), (1, 5) Doctor Manhattan and Daniel will calculate the same distances.

// https://codeforces.com/contest/651/problem/C

//approach : when x1 = x2 or y1 = y2, then the distance calculated by both the methods will be same. So, we need to find the number of points with same x or y coordinates and then find the number of pairs of such points.
// For this we can use map to store the frequency of x and y coordinates and a map of pair to store the frequency of points with same x and y coordinates. Then we can iterate over the map of pair and find the number of pairs of points with same x and y coordinates.

#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    map<int,int> xc;
    map<int,int> yc;
    map<pair<int,int>,int> xyc;
    long long sum =0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        sum += xc[x]++;
        sum += yc[y]++;
        sum -= xyc[make_pair(x,y)]++;
    }
    
    cout<<sum<<endl;
}