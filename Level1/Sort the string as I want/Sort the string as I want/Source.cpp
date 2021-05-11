#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<string> solution(vector<string> strings, int n) 
{
    vector<string> answer;

    sort(strings.begin(), strings.end(), [&](const string& a, const string& b) {
        if (a[n] != b[n])
            return a[n] < b[n];
        else
            return a < b;
    });


    answer = strings;
    return answer;
}

int main()
{
    vector<string> strings = { "sun", "bed", "car" };

    vector<string>::iterator it;
    vector<string> ans = solution(strings, 1);
    for (it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    cout << "\n";

	return 0;
}