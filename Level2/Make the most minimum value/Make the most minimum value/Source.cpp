#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), [](const int& a, const int& b) {
        return a < b;
    });

    sort(B.begin(), B.end(), [](const int& a, const int& b) {
        return a > b;
    });


    for (int i = 0; i < A.size(); i++)
        answer += A[i] * B[i];
   

    return answer;
}

int main()
{
    vector<int> a = { 1, 2 };
    vector<int> b = { 3, 4 };

    cout << solution(a, b) << "\n";

    return 0;
}