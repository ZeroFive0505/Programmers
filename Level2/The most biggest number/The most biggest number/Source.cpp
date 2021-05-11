#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) 
{
    string answer = "";

    vector<string> v;

    for (auto i : numbers)
        v.push_back(to_string(i));

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    for (auto i : v)
        answer += i;

    return answer;
}

int main()
{
    vector<int> numbers = { 6, 10, 2 };

    cout << solution(numbers) << "\n";

    return 0;
}