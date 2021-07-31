#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 501;

int cache[SIZE][SIZE];

int n;

vector<vector<int>> t;

int dp(int r, int c)
{
    if (r == n - 1)
        return t[r][c];

    int& ret = cache[r][c];

    if (ret != -1)
        return ret;

    return ret = max(dp(r + 1, c), dp(r + 1, c + 1)) + t[r][c];
}

int solution(vector<vector<int>> triangle) 
{
    int answer = 0;
    t = triangle;
    n = triangle.size();
    memset(cache, -1, sizeof(cache));
    answer = dp(0, 0);
    return answer;
}

int main()
{
    vector<vector<int>> tri = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };


    cout << solution(tri) << "\n";

    return 0;
}