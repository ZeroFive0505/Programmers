#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int minV = INT_MAX;

    for (auto i : arr)
    {
        if (minV > i)
            minV = i;
    }

    arr.erase(remove(arr.begin(), arr.end(), minV), arr.end());

    if (arr.size() != 0)
        answer = arr;
    else
        answer.push_back(-1);

    return answer;
}

int main()
{
    vector<int> a = { 4, 3, 2, 1 };
    a = solution(a);
    for (auto i : a)
        cout << i << " ";
    cout << "\n";
    return 0;
}