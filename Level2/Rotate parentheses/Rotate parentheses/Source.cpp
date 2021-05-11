#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

bool Check(string s)
{
    stack<char> st;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{')
            st.push(ch);
        else
        {
            if (!st.empty())
            {
                if ((st.top() == '(' && ch == ')'
                    || st.top() == '{' && ch == '}'
                    || st.top() == '[' && ch == ']'))
                    st.pop();
            }
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

string Rotate(string s, int cnt)
{
    deque<char> dq;
    int size = s.size();

    for (int i = 0; i < size; i++)
        dq.push_back(s[i]);

    for (int i = 0; i < cnt; i++)
    {
        char front = dq.front();
        dq.pop_front();
        dq.push_back(front);
    }

    string ret(dq.begin(), dq.end());

    return ret;
}

int solution(string s) 
{
    int answer = 0;
    int size = s.size();

    for (int i = 0; i < size - 1; i++)
    {
        if(Check(Rotate(s, i)))
            answer++;
    }

    return answer;
}

int main()
{
    string s = "}}}";

    cout << solution(s) << "\n";

    return 0;
}