#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;

    sort(people.begin(), people.end(), [](const int a, const int b) {
        return a > b;
    });

    int lim = limit;
    int i = 0;
    int j = people.size() - 1;
    
    while (i <= j)
    {
        int p = people[i];
        lim -= p;
        i++;

        if (people.size() >= 1 && people[j] <= lim)
            j--;
        lim = limit;
        answer++;
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 80, 50 };
    int lim = 100;

    cout << solution(people, lim) << "\n";

    return 0;
}