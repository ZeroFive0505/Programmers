#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 10000000 + 19;

void Calculate_Combination(vector<vector<long long>>& v, int row)
{
    v[0][0] = 1;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 0; j <= row; j++)
        {
            if (j == 0)
                v[i][j] = 1;
            else if (i == j)
                v[i][j] = 1;
            else
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];

            v[i][j] %= MOD;
        }
    }
}

void Calculate_OneCnt(vector<int>& v, vector<vector<int>>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
        {
            v[j] += a[i][j];
        }
    }
}

int solution(vector<vector<int>> a) 
{
    int row = a.size();
    int col = a[0].size();

    vector<vector<long long>> nCr(row + 1, vector<long long>(row + 1, 0));
    Calculate_Combination(nCr, row);

    vector<int> ones(col + 1, 0);
    Calculate_OneCnt(ones, a);

    vector<vector<long long>> dp(col + 2, vector<long long>(row + 1, 0));
    dp[1][row - ones[0]] = nCr[row][row - ones[0]];


    for (int c = 1; c < col; c++)
    {
        int one = ones[c];
        
        for (int even = 0; even <= row; even++)
        {
            if (dp[c][even] == 0)
                continue;

            for (int k = 0; k <= one; k++)
            {
                if (even < k)
                    continue;

                int be_even = even + one - (2 * k);

                if (be_even > row)
                    continue;

                long long result = (nCr[even][k] * nCr[row - even][one - k]) % MOD;
                dp[c + 1][be_even] = (dp[c + 1][be_even] + dp[c][even] * result);
                dp[c + 1][be_even] %= MOD;
            }
        }
    }

    return dp[col][row];
}

int main()
{
    vector<vector<int>> a = {
        {0, 1, 0},
        {1, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };


    cout << solution(a) << "\n";

    return 0;
}