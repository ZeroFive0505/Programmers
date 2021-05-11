#include <iostream>
#include <string>

const int SIZE = 11;

int MAP[SIZE][SIZE][SIZE][SIZE];

using namespace std;

int solution(string dirs) 
{
    int answer = 0;

    int curX = 5;
    int curY = 5;

    int size = dirs.size();

    for (int i = 0; i < size; i++)
    {
        switch (dirs[i])
        {
        case 'U':
            if (curY + 1 < SIZE)
            {
                if (MAP[curX][curY][curX][curY + 1] == 0)
                {
                    MAP[curX][curY][curX][curY + 1] = 1;
                    MAP[curX][curY + 1][curX][curY] = 1;
                    answer++;
                }
                curY++;
            }
            break;
        case 'D':
            if (curY - 1 >= 0)
            {
                if (MAP[curX][curY][curX][curY - 1] == 0)
                {
                    MAP[curX][curY][curX][curY - 1] = 1;
                    MAP[curX][curY - 1][curX][curY] = 1;
                    answer++;
                }
                curY--;
            }
            break;
        case 'L':
            if (curX - 1 >= 0)
            {
                if (MAP[curX][curY][curX - 1][curY] == 0)
                {
                    MAP[curX][curY][curX - 1][curY] = 1;
                    MAP[curX - 1][curY][curX][curY] = 1;
                    answer++;
                }
                curX--;
            }
            break;
        case 'R':
            if (curX + 1 < SIZE)
            {
                if (MAP[curX][curY][curX + 1][curY] == 0)
                {
                    MAP[curX][curY][curX + 1][curY] = 1;
                    MAP[curX + 1][curY][curX][curY] = 1;
                    answer++;
                }
                curX++;
            }
            break;

        }
    }


    return answer;
}

int main()
{

    cout << solution("ULURRDLLU") << "\n";

    return 0;
}