#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) 
{

    unordered_map<string, int> m;

    for (auto i : phone_book)
        m[i] = 1;


    for (int i = 0; i < phone_book.size(); i++)
    {
        string n;
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            n += phone_book[i][j];
            if (m.count(n) && n != phone_book[i])
                return false;
        }
    }

    return true;
}

int main()
{
    vector<string> numbers = { "119", "97674223", "1195524421" };

    cout << solution(numbers) << "\n";

    return 0;
}