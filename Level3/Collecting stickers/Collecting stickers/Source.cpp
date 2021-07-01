#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cache[100001];

int solution(vector<int> sticker)
{
    int answer = 0;

    if (sticker.size() == 1)
        return sticker[0];

    cache[0] = sticker[0];
    cache[1] = cache[0];

    for (int i = 2; i < sticker.size() - 1; i++)
    {
        cache[i] = max(cache[i - 2] + sticker[i], cache[i - 1]);
    }

    answer = max(answer, cache[sticker.size() - 2]);

    cache[0] = 0;
    cache[1] = sticker[1];

    for (int i = 2; i < sticker.size(); i++)
    {
        cache[i] = max(cache[i - 2] + sticker[i], cache[i - 1]);
    }

    answer = max(answer, cache[sticker.size() - 1]);

    return answer;
}

int main()
{
    vector<int> stickers = { 14, 6, 5, 11, 3, 9, 2, 10 };

    cout << solution(stickers) << "\n";

    return 0;
}