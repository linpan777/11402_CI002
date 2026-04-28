#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool is_Vaild(const string s);

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int Case; cin >> Case; cin.ignore();
    string s;
    while (Case--)
    {
        getline(cin, s);
        if (is_Vaild(s))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

bool is_Vaild(const string s)
{
    stack<char> parentheses;
    for (char c : s)
    {
        if (c == '[' || c == '(')
            parentheses.push(c);
        else if (parentheses.empty())
            return false;
        else if (c == ']')
            if (parentheses.top() == '[')
                parentheses.pop();
            else
                return false;
        else if (c == ')')
            if (parentheses.top() == '(')
                parentheses.pop();
            else
                return false;
    }
    if (parentheses.empty())
        return true;
    else
        return false;
}