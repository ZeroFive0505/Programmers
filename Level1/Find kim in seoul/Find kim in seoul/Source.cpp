#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) 
{
    string answer = "";
    int i;

    for (i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
            break;
    }

    answer = "�輭���� " + to_string(i) + "�� �ִ�";

    return answer;
}

int main()
{
    vector<string> s = { "Jane", "Kim" };
    cout << solution(s) << "\n";
    return 0;
}