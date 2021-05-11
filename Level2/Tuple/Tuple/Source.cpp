#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    set<int> st;
    vector<string> v;
    bool num = false;
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        if (!num && isdigit(s[i]))
        {
            temp.clear();
            num = true;
        }
        else if (s[i] == '}')
        {
            if (!temp.empty())
            {
                v.push_back(temp);
                temp.clear();
            }
            num = false;
        }

        if (num)
        {
            temp.push_back(s[i]);
        }
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    size_t pos;

    for (int i = 0; i < v.size(); i++)
    {
        string e = v[i];
        if (e.find(",") != string::npos)
        {
            while ((pos = e.find(",")) != string::npos)
            {
                string token = e.substr(0, pos);
                e.erase(0, pos + 1);

                if (st.count(stoi(token)) == 0)
                {
                    st.insert(stoi(token));
                    answer.push_back(stoi(token));
                }

            }
            if (st.count(stoi(e)) == 0)
            {
                st.insert(stoi(e));
                answer.push_back(stoi(e));
            }

        }
        else
        {
            if (st.count(stoi(e)) == 0)
            {
                st.insert(stoi(e));
                answer.push_back(stoi(e));
            }
        }
    }


    return answer;
}

int main()
{
    string s = "{{20,111},{111}}";

    vector<int> ans = solution(s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}