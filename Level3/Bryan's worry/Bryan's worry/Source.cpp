#include <iostream>
#include <algorithm>
#include <vector>
#include <ctype.h>
#include <cstring>
#include <string>

using namespace std;

const int SIZE = 1005;
const int INVALID = -2;
const int EMPTY = -1;

int cache[SIZE];
int firstAppear[256];

string sen;

bool isAllUpper(int first, int last)
{
    if (first > last)
        return false;

    for (int i = first; i <= last; i++)
    {
        if (!isupper(sen[i]))
            return false;
    }

    return true;
}

bool isRuleA(int first, int last)
{
    if (first > last)
        return false;
    if ((last - first) % 2 == 1)
        return false;
    char c = '?';

    for (int i = first; i <= last; i++)
    {
        if ((i - first) % 2 == 1)
        {
            if (!islower(sen[i]))
                return false;
            if (c == '?')
            {
                c = sen[i];

                if (firstAppear[c] < first)
                    return false;
            }
            else if (c != sen[i])
                return false;
        }
        else
        {
            if (!isupper(sen[i]))
                return false;
        }
    }

    return true;
}

bool isRuleB(int first, int last)
{
    if (first >= last)
        return false;
    return islower(sen[first]) && sen[first] == sen[last] && firstAppear[sen[first]] == first;
}

bool canBeWord(int first, int last)
{
    if (isRuleB(first, last))
    {
        first++;
        last--;
    }

    return isAllUpper(first, last) || isRuleA(first, last);
}

int getWordStart(int e)
{
    if (e <= -1)
        return 0;

    if (cache[e] != EMPTY)
        return cache[e];

    cache[e] = INVALID;

    for (int s = 0; s <= e; s++)
    {
        if (canBeWord(s, e) && getWordStart(s - 1) != INVALID)
        {
            cache[e] = s;
            break;
        }
    }

    return cache[e];
}

void buildFirstAppear()
{
    memset(firstAppear, EMPTY, sizeof(firstAppear));

    for (int i = 0; i < sen.size(); i++)
    {
        if (islower(sen[i]))
        {
            if (firstAppear[sen[i]] == -1)
            {
                firstAppear[sen[i]] = i;
            }
        }
    }
}

string solution(string sentence) 
{
    string answer = "";
    sen = sentence;

    buildFirstAppear();

    memset(cache, EMPTY, sizeof(cache));
    getWordStart(sen.size() - 1);

    int i = sen.size() - 1;

    if (cache[i] == INVALID)
        return "invalid";

    vector<int> spaces;

    while (1)
    {
        if (cache[i] == 0)
            break;
        i = cache[i] - 1;
        spaces.push_back(i);
    }

    int j = spaces.size() - 1;

    for (int i = 0; i < sen.size(); i++)
    {
        if (isupper(sen[i]))
            answer += sen[i];

        if (j >= 0 && spaces[j] == i)
        {
            answer += " ";
            j--;
        }
    }

    return answer;
}

int main()
{
    while (1)
    {
        string s;

        cin >> s;

        cout << solution(s) << "\n";

    }
    return 0;
}