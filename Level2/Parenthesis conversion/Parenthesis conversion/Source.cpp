#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(string p)
{
    stack<char> s;
    int len = p.length();

    for (int i = 0; i < len; i++)
    {
        char ch = p[i];

        if (ch == '(')
            s.push(ch);
        else
        {
            if (!s.empty() && s.top() == '(')
                s.pop();
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

string recur(string p)
{
    if (p.length() == 0)
        return "";

    int openCount = 0;
    int closeCount = 0;
    string u, v;

    for (int i = 0; i < p.length(); i++)
    {
        char ch = p[i];

        if (ch == '(')
            openCount++;
        else
            closeCount++;

        if (openCount == closeCount)
        {
            u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }

    if (check(u))
        return u + recur(v);

    string t;

    t += '(';

    t += recur(v);

    t += ')';

    u = u.substr(1, u.length() - 2);

    for (int i = 0; i < u.length(); i++)
    {
        if (u[i] == '(')
            t += ')';
        else
            t += '(';
    }

    return t;
}

string solution(string p)
{
    if (check(p))
        return p;

    return recur(p);
}

int main()
{
    string p = "()))((()";

    cout << solution(p) << "\n";

    return 0;
}