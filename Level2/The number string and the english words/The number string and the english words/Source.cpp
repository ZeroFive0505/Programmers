#include <iostream>
#include <ctype.h>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    map<string, int> hashMap;

    hashMap["zero"] = 0;
    hashMap["one"] = 1;
    hashMap["two"] = 2;
    hashMap["three"] = 3;
    hashMap["four"] = 4;
    hashMap["five"] = 5;
    hashMap["six"] = 6;
    hashMap["seven"] = 7;
    hashMap["eight"] = 8;
    hashMap["nine"] = 9;

    for (int i = 0; i < s.size();)
    {
        if (isdigit(s[i]))
        {
            int num = s[i] - '0';
            answer = answer * 10 + num;
            i++;
        }
        else
        {
            int j;
            string temp;
            for (j = i; j < s.size(); j++)
            {
                temp.push_back(s[j]);

                if (hashMap.find(temp) != hashMap.end())
                {
                    int num = hashMap[temp];
                    answer = answer * 10 + num;
                    break;
                }
            }

            i += j - i;
            i++;
        }
    }

    return answer;
}

int main()
{
    string s = "123";

    cout << solution(s) << "\n";

    return 0;
}