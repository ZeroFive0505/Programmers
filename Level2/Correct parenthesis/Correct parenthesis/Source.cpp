#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (ch == '(')
            st.push(ch);
        else
        {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
    }

    if (st.empty())
        answer = true;
    else
        answer = false;


    return answer;
}

int main()
{
    string s = "(()(";

    cout << solution(s) << "\n";

    return 0;
}