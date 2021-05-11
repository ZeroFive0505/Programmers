#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    vector<int>::iterator it1;
    vector<int>::iterator it2;

    it1 = arr1.begin();
    it2 = arr2.begin();

    while (it1 != arr1.end() && it2 != arr2.end())
    {
        unsigned int decode;
        decode = *it1 | *it2;
        string m;
        unsigned int b = 1;
        for (int i = 0; i < n; i++, b <<= 1)
        {
            if (b & decode)
                m.push_back('#');
            else
                m.push_back(' ');
        }
        string r(m.rbegin(), m.rend());
        answer.push_back(r);
        m.clear();
        it1++;
        it2++;
    }


    return answer;
}

int main()
{
    int n = 6;
    vector<int> arr1 = { 46, 33, 33, 22, 31, 50 };
    vector<int> arr2 = { 27, 56, 19, 14, 14, 10 };
    vector<string> s = solution(n, arr1, arr2);
    vector<string>::iterator it;
    for (it = s.begin(); it != s.end(); it++)
        cout << *it << "\n";
    return 0;
}