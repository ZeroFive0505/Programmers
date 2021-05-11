#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string solution(string number, int k)
{
    vector<char> v;
    string answer;
    for (int i = 0; i < number.length(); i++)
    {
        while (!v.empty() && v.back() < number[i] && k > 0)
        {
            v.pop_back();
            k--;
        }

        v.push_back(number[i]);
    }

    while (!v.empty() && k > 0)
    {
        v.pop_back();
        k--;
    }

    for (auto i : v)
        answer += i;

    return answer;
}



int main()
{
    string number = "1231234";
    int k = 3;
    cout << solution(number, k) << "\n";
    return 0;
}