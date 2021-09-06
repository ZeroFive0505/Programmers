#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int index = 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = index; j < B.size(); j++)
        {
            if (A[i] < B[j])
            {
                answer++;
                index = j + 1;
                break;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> a = { 5,1,3,7 };
    vector<int> b = { 2,2,6,8 };

    cout << solution(a, b) << "\n";

    return 0;
}