#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;
    int zeroCnt = 0;
    int idx = 0;
    while (s != "1")
    {
        int size = s.size();
        string subS;
        for (int i = 0; i < size; i++)
        {
            if (s[i] != '0')
                subS.push_back(s[i]);
            else
                zeroCnt++;
        }
        
        size = subS.size();
        subS.clear();
        while (size)
        {
            subS.push_back(size % 2 + '0');
            size /= 2;
        }
        string res(subS.rbegin(), subS.rend());
        s = res;

        idx++;

    }

    answer.push_back(idx);
    answer.push_back(zeroCnt);

    return answer;
}

int main()
{
    string s = "1111111";

    vector<int> ans = solution(s);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}