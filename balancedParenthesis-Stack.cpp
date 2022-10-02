#include<bits/stdc++.h>
using namespace std;

void dfile() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

// Can also implement this by using unordered map

bool isBalanced(string s) {

	stack<char> st;
	bool ans = true;

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '{' or s[i] == '[' or s[i] == '(')
		{
			st.push(s[i]);
		}
		else if (!st.empty() and s[i] == ')')
		{
			if (st.top() == '(')
			{
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
		else if (!st.empty() and s[i] == ']')
		{
			if (st.top() == '[')
			{
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
		else if (!st.empty() and s[i] == '}')
		{
			if (st.top() == '{')
			{
				st.pop();
			}
			else {
				ans = false;
				break;
			}
		}
	}
	return ans;
}

int main()
{
	dfile();

	string s = " {[()]} ";

	if (isBalanced(s))
	{
		cout << "Balanced Parenthesis \n";
	}
	else {
		cout << "Not Balanced Parenthesis \n";
	}

	return 0;
}
