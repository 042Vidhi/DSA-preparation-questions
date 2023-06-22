// Mad scientist Mike has just finished constructing a new device to search for extraterrestrial intelligence! He was in such a hurry to launch it for the first time that he plugged in the power wires without giving it a proper glance and started experimenting right away. After a while Mike observed that the wires ended up entangled and now have to be untangled again.

// The device is powered by two wires "plus" and "minus". The wires run along the floor from the wall (on the left) to the device (on the right). Both the wall and the device have two contacts in them on the same level, into which the wires are plugged in some order. The wires are considered entangled if there are one or more places where one wire runs above the other one. For example, the picture below has four such places (top view):


// Mike knows the sequence in which the wires run above each other. Mike also noticed that on the left side, the "plus" wire is always plugged into the top contact (as seen on the picture). He would like to untangle the wires without unplugging them and without moving the device. Determine if it is possible to do that. A wire can be freely moved and stretched on the floor, but cannot be cut.

// To understand the problem better please read the notes to the test samples.

// Input
// The single line of the input contains a sequence of characters "+" and "-" of length n (1 ≤ n ≤ 100000). The i-th (1 ≤ i ≤ n) position of the sequence contains the character "+", if on the i-th step from the wall the "plus" wire runs above the "minus" wire, and the character "-" otherwise.

// Output
// Print either "Yes" (without the quotes) if the wires can be untangled or "No" (without the quotes) if the wires cannot be untangled.

// Examples
// input
// -++-
// output
// Yes
// input
// +-
// output
// No
// input
// ++
// output
// Yes
// input
// -
// output
// No

// https://codeforces.com/contest/343/problem/B


#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty() && st.top()==s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
if(st.empty())
{
    cout<<"Yes"<<endl;
}
else{
    cout<<"No"<<endl;
}
    return 0;
}