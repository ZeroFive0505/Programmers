#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> s) 
{
    vector<string> answer(s.size(), "");

    for (int i = 0; i < s.size(); i++)
    {
        int cnt = 0;
        stack<char> st;

        for (int j = 0; j < s[i].size(); j++)
        {
            st.push(s[i][j]);

            if (st.size() >= 3)
            {
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                char c = st.top();
                st.pop();


                if (a == '0' && b == '1' && c == '1')
                    cnt++;
                else
                {
                    st.push(c);
                    st.push(b);
                    st.push(a);
                }
            }
        }

        if (cnt == 0)
            answer[i] = s[i];
        else
        {
            int idx = st.size();

            string temp;

            while (!st.empty() && st.top() == '1')
            {
                idx--;
                temp = st.top() + temp;
                st.pop();
            }

            while (!st.empty())
            {
                temp = st.top() + temp;
                st.pop();
            }


            while (cnt--)
                temp.insert(idx, "110");

            answer[i] = temp;
        }
    }

    return answer;
}

int main()
{
    vector<string> s = {
        "1110",
        "100111100",
        "0111111010"
    };


    vector<string> ans = solution(s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}