#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) 
{

    unordered_map<string, int> m;
    
    for (const string& s : phone_book)
        m[s] = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];

            if (m.count(temp) && temp != phone_book[i])
                return false;
        }
    }

    return true;
}

int main()
{
    vector<string> numbers = { "12","123","1235","567","88" };

    cout << solution(numbers) << "\n";

    return 0;
}