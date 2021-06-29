#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<long long, long long> hashMap;

long long Find(long long v)
{
    if (hashMap.find(v) == hashMap.end())
    {
        return v;
    }

    return hashMap[v] = Find(hashMap[v]);
}

void Union(long long u, long long v)
{
    u = Find(u);
    v = Find(v);
    hashMap[u] = v;
}

vector<long long> solution(long long k, vector<long long> room_number)
{
    vector<long long> answer;

    for (int i = 0; i < room_number.size(); i++)
    {
        long long num = room_number[i];
        long long ret = Find(num);
        answer.push_back(ret);
        Union(ret, ret + 1);
    }

    return answer;
}

int main()
{
    long long k = 10;
    vector<long long> room_number = { 1, 3, 4, 1, 3, 1 };

    vector<long long> ans = solution(k, room_number);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}