#include <iostream>
#include <stack>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    int size = s.size();

    for (int i = 0; i < size; i++)
    {
        if (st.empty())
            st.push(s[i]);
        else
        {
            if (st.top() == s[i])
                st.pop();
            else
                st.push(s[i]);
        }
    }

    if (st.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}

int main()
{

    string s = "baabaa";
    cout << solution(s) << "\n";

    return 0;
}