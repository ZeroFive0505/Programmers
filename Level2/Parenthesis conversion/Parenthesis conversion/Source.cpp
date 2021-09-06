#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool Check(const string& s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (!st.empty() && s[i] == ')')
                st.pop();
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

string recur(string p)
{
    if (p.empty())
        return "";
    int openCount = 0;
    int closeCount = 0;

    string u, v;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
            openCount++;
        else if (p[i] == ')')
            closeCount++;

        if (openCount == closeCount)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (Check(u))
        return u + recur(v);

    string temp = "(";

    temp += recur(v);

    temp += ")";

    u.erase(u.begin());
    u.pop_back();

    for (int i = 0; i < u.size(); i++)
    {
        if (u[i] == '(')
            temp += ')';
        else
            temp += '(';
    }

    return temp;
}

string solution(string p)
{
    if (Check(p))
        return p;

    return recur(p);
}

int main()
{
    string p = "()))((()";

    cout << solution(p) << "\n";

    return 0;
}