#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int Case; cin >> Case; cin.ignore();
	string s;
	while (Case--)
	{
		getline(cin, s);
		stack<char> parentheses;
		for (char c : s)
		{
			if (c == '(' || c == '[' || parentheses.empty())//除了上括號，只要stack是空的就無條件push
				parentheses.push(c);

            //首先判斷前面是否對應的上括號，
            //是就pop掉，否則一樣push
			if (c == ']')
				if (parentheses.top() == '[')
					parentheses.pop();
				else
					parentheses.push(c);
			if (c == ')')
				if (parentheses.top() == '(')
					parentheses.pop();
				else
					parentheses.push(c);
		}
		if (parentheses.empty())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

/*
Sample Input
12

([])
(([()]))
([()[]()])()
(([()])
([])
(([()])))
([()[]()])()
(
(]
)(
][

Sample Output
Yes
Yes
No
Yes
No
Yes
No
Yes
No
No
No
No
*/