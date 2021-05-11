#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int HIT = 1;
const int MISS = 5;

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;
    
    if (cacheSize == 0)
        answer = MISS * cities.size();
    else
    {
        vector<string> cache;

        for (int i = 0; i < cities.size(); i++)
        {
            transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::towlower);
            int j;
            for (j = 0; j < cache.size(); j++)
            {
                if (cache[j] == cities[i])
                {
                    answer += HIT;
                    cache.erase(cache.begin() + j);
                    cache.push_back(cities[i]);
                    break;
                }
            }

            if (j == cache.size())
            {
                answer += MISS;
                if(cache.size() >= cacheSize)
                    cache.erase(cache.begin());
                cache.push_back(cities[i]);
            }
        }
    }

    return answer;
}

int main()
{
    int size = 5;

    vector<string> cities = { "SEOUL", "SEOUL", "SEOUL" };

    cout << solution(size, cities) << "\n";

    return 0;
}