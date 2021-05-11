#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <string>
#include <vector>

using namespace std;

struct sFileFormat
{
    string head;
    string number;
    string tail;
    string original;

    sFileFormat(string& head, string& number, string& tail, string& original)
    {
        this->head = head;
        this->number = number;
        this->tail = tail;
        this->original = original;
    }
};

vector<string> solution(vector<string> files) 
{
    vector<string> answer;

    vector<sFileFormat> v;

    for (int i = 0; i < files.size(); i++)
    {
        string f = files[i];
        string head;
        string number;
        string tail;
        bool isHead = true;
        bool isNum = true;
        int lastNumIdx = -1;
        for (int j = 0; j < f.size(); j++)
        {
            if (isHead && (isalpha(f[j]) || f[j] == ' ' || f[j] == '.' || f[j] == '-'))
                head += tolower(f[j]);
            else if (isNum && isdigit(f[j]))
            {
                number += f[j];
                isHead = false;
                lastNumIdx = j;
            }
            else if (j > lastNumIdx)
            {
                tail += tolower(f[j]);
                isNum = false;
            }
        }

        if(tail[0] != ' ')
            v.push_back(sFileFormat(head, number, tail, f));
        else
        {
            string tmp = tail.substr(1, tail.length());
            v.push_back(sFileFormat(head, number, tmp, f));
        }
    }



    stable_sort(v.begin(), v.end(), [](const sFileFormat& a, const sFileFormat& b) {
        if (a.head != b.head)
            return a.head < b.head;
        else if (a.head == b.head)
            return stoi(a.number) < stoi(b.number);
    });


    for (auto i : v)
        answer.push_back(i.original);

    return answer;
}

int main()
{

    vector<string> files = {
        "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"
    };


    vector<string> res = solution(files);

    for (auto s : res)
        cout << s << " ";
    cout << "\n";

    return 0;
}