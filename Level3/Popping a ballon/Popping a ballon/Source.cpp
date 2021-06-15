#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int solution(vector<int> a) 
{
    int answer = 2;

    if (a.size() <= 2)
        return a.size();

    vector<pair<int, int>> v(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        v[i].first = a[i];
        v[i].second = i;
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });

    int A = min(v[0].second, v[1].second);
    int B = max(v[0].second, v[1].second);

    for (int i = 2; i < v.size(); i++)
    {
        int C = v[i].second;

        if (A < C && C < B)
            continue;

        answer++;
        A = min(A, C);
        B = max(B, C);
    }

    return answer;
}

int main()
{
    vector<int> a = {
       -16,27,65,-2,58,-92,-71,-68,-61,-33
    };

    cout << solution(a) << "\n";

    return 0;
}