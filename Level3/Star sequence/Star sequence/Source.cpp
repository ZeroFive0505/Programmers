#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) 
{
    int answer = -1;
    vector<int> cnt(a.size() + 1, 0);

    for (int i = 0; i < a.size(); i++)
        cnt[a[i]]++;

    for (int i = 0; i < cnt.size(); i++)
    {
        if (cnt[i] == 0)
            continue;
        if (cnt[i] <= answer)
            continue;

        int result = 0;

        for (int j = 0; j < a.size() - 1; j++)
        {
            if (a[j] != i && a[j + 1] != i)
                continue;

            if (a[j] == a[j + 1])
                continue;

            result++;
            j++;
        }

        answer = max(answer, result);
    }

    return answer * 2;
}

int main()
{
    vector<int> a = { 0,3,3,0,7,2,0,2,2,0 };
    cout << solution(a) << "\n";
    return 0;
}