#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

struct sKeyPad
{
    int x;
    int y;
};

const int SIZE = 12;

sKeyPad location_info[SIZE] = { 
    {1,1},  {0,4}, {1,4}, {2,4}, {0,3}, {1,3}, {2,3}, {0,2}, {1,2}, {2,2}, {0,1}, {2,1} 
}; // 0      1      2      3      4      5      6      7      8      9      *      #

bool IsLeft(int keypad)
{
    if (keypad == 1 || keypad == 4 || keypad == 7)
        return true;
    else
        return false;
}

bool IsRight(int keypad)
{
    if (keypad == 3 || keypad == 6 || keypad == 9)
        return true;
    else
        return false;
}

string solution(vector<int> numbers, string hand) 
{
    string answer = "";

    int size = numbers.size();
    int currentLeft = 10;
    int currentRight = 11;
    sKeyPad target;
    sKeyPad leftPos;
    sKeyPad rightPos;
    sKeyPad diff;
    for (int i = 0; i < size; i++)
    {
        if (IsLeft(numbers[i]))
        {
            currentLeft = numbers[i];
            answer += "L";
        }
        else if (IsRight(numbers[i]))
        {
            currentRight = numbers[i];
            answer += "R";
        }
        else
        {
            target = location_info[numbers[i]];
            leftPos = location_info[currentLeft];
            rightPos = location_info[currentRight];
            int xDiff;
            int yDiff;
            xDiff = target.x - leftPos.x;
            yDiff = target.y - leftPos.y;

            int ld = abs(xDiff) + abs(yDiff);


            xDiff = target.x - rightPos.x;
            yDiff = target.y - rightPos.y;

            int rd = abs(xDiff) + abs(yDiff);

            if (ld < rd)
            {
                currentLeft = numbers[i];
                answer += "L";
            }
            else if(ld > rd)
            {
                currentRight = numbers[i];
                answer += "R";
            }
            else
            {
                if (hand == "right")
                {
                    currentRight = numbers[i];
                    answer += "R";
                }
                else if(hand == "left")
                {
                    currentLeft = numbers[i];
                    answer += "L";
                }
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };
    string hand = "left";
    string ans = solution(numbers, hand);
    cout << ans << "\n";

    return 0;
}