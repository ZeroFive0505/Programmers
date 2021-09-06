#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers) 
{
    string answer = "";

    vector<string> v;

    for (int i : numbers)
        v.push_back(to_string(i));

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });

    if (v[0] == "0")
        return "0";

    for (const string& s : v)
        answer += s;

    return answer;
}

int main()
{
    vector<int> numbers = { 3, 30, 34, 5, 9 };

    cout << solution(numbers) << "\n";

    return 0;
}