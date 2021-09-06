#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const char vowel[] = { 'A', 'E', 'I', 'O', 'U' };
vector<string> v;

void recur(int depth, string temp)
{
    if (depth == 5)
        return;

    for (int i = 0; i < 5; i++)
    {
        temp.push_back(vowel[i]);
        v.push_back(temp);
        recur(depth + 1, temp);
        temp.pop_back();
    }
}

int solution(string word) 
{
    int answer = 0;

    v.push_back("");
    recur(0, "");

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        if (word == v[i])
        {
            answer = i;
            break;
        }
    }

    return answer;
}

int main()
{
    // cout << solution("AAAAE") << "\n";
    // cout << solution("AAAE") << "\n";
    // cout << solution("I") << "\n";
    // cout << solution("EIO") << "\n";

	return 0;
}