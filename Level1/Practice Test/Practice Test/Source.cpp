#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE1 = 5;
const int SIZE2 = 8;
const int SIZE3 = 10;

int sol1[SIZE1] = { 1, 2, 3, 4, 5 };
int sol2[SIZE2] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int sol3[SIZE3] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int ans(const int* sol, const int num, const int size)
{
    return sol[num % size];
}

vector<int> solution(vector<int> answers) 
{
    vector<int> answer;
    vector<pair<int, int>> candidates;
    candidates.push_back(make_pair(0, 1));
    candidates.push_back(make_pair(0, 2));
    candidates.push_back(make_pair(0, 3));

    for (int i = 0; i < answers.size(); i++)
    {
        int correctAns = answers[i];
        candidates[0].first += ans(sol1, i, SIZE1) == correctAns ? 1 : 0;
        candidates[1].first += ans(sol2, i, SIZE2) == correctAns ? 1 : 0;
        candidates[2].first += ans(sol3, i, SIZE3) == correctAns ? 1 : 0;
    }

    sort(candidates.begin(), candidates.end(), [](pair<int, int> a, pair<int, int> b) {return a.first > b.first; });
    int maxP = candidates[0].first;
    for (int i = 0; i < candidates.size(); i++)
    {
        if (candidates[i].first == maxP)
            answer.push_back(candidates[i].second);
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> ans = { 1,3,2,4,2 };
    solution(ans);
    return 0;
}