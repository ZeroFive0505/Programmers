#include <iostream>
#include <string>
#include <vector>

using namespace std;

void RotateMat(vector<vector<int>>& key)
{
    int m = key.size();

    vector<vector<int>> temp(m, vector<int>(m, 0));

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key[i].size(); j++)
        {
            temp[i][j] = key[m - j - 1][i];
        }
    }

    key = temp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) 
{
    bool answer = false;

    int keySize = key.size();
    int lockSize = lock.size();

    for (int rot = 0; rot < 4; rot++)
    {
        RotateMat(key);

        for (int i = 0; i < lockSize + keySize - 1; i++)
        {
            for (int j = 0; j < lockSize + keySize - 1; j++)
            {
                vector<vector<int>> padding(lockSize + 2 * keySize - 2, vector<int>(lockSize + 2 * keySize - 2, 0));

                for (int y = 0; y < lockSize; y++)
                {
                    for (int x = 0; x < lockSize; x++)
                    {
                        padding[y + keySize - 1][x + keySize - 1] = lock[y][x];
                    }
                }

                for (int y = 0; y < keySize; y++)
                {
                    for (int x = 0; x < keySize; x++)
                    {
                        padding[y + i][x + j] ^= key[y][x];
                    }
                }

                int cnt = 0;

                for (int y = keySize - 1; y < keySize + lockSize - 1; y++)
                {
                    for (int x = keySize - 1; x < keySize + lockSize - 1; x++)
                    {
                        if (padding[y][x])
                            cnt++;
                    }
                }

                if (cnt == lockSize * lockSize)
                    return true;

            }
        }
    }
  
    return answer;
}

int main()
{
    vector<vector<int>> key = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };

    vector<vector<int>> lock = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };

    cout << solution(key, lock) << "\n";

    return 0;
}