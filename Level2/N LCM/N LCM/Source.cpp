#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a -= b;
        else if (b > a)
            b -= a;
        else
            b -= a;
    }

    if (a < 0)
        return b;
    else
        return a;
}

int solution(vector<int> arr) 
{
    int answer = 0;

    sort(arr.begin(), arr.end());

    while (arr.size() != 1)
    {
        int a = arr.back();
        arr.pop_back();
        int b = arr.back();
        arr.pop_back();

        int gcd = GCD(a, b);

        arr.push_back((a * b) / gcd);
    }

    answer = arr[0];

    return answer;
}

int main()
{
    vector<int> arr = { 2, 6, 8, 14 };
    
    cout << solution(arr) << "\n";

    return 0;
}