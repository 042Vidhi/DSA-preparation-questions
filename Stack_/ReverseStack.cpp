// Write a program to reverse a stack using recursion. 
// You are not allowed to use loop constructs like while, for.. etc., and you can only use the following functions on Stack S:
// isEmpty(S)
// push(S)
// pop(S)

// Input Format
// First Line contains elements for a stack. Next Line contains the n elements of stack.
// Output Format
// Line containing elements of stack printed in reverse order.
// Example 
// Input
// 5
// 1 2 3 4 5
// Output
// 5 4 3 2 1

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void pushbottom(int x,stack<int> &st)
{
	if(st.empty())
	{
		st.push(x);
		return;
	}
	int temp = st.top();
	st.pop();
	pushbottom(x,st);
	st.push(temp);
	
}
void reverse(stack<int> &st)
{
	if(st.empty())
	{
		return;
	}
	int y = st.top();
	st.pop();
	reverse(st);
	pushbottom(y,st);
	
}
int main() {
    int n;
	cin>>n;
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		st.push(a);
	}
	reverse(st);
	vector<int>v;
	while(!st.empty()){
		int y=st.top();
		v.push_back(y);
		st.pop();
	}
	for(int i=v.size()-1;i>=0;i--)
	{
		cout<<v[i]<<" ";
	}
    return 0;
}