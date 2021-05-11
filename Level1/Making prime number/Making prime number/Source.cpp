#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 50001;

bool IsPrime[SIZE];

int solution(vector<int> nums) 
{
    int answer = 0;
    fill(IsPrime, IsPrime + SIZE, true);
    IsPrime[0] = IsPrime[1] = false;

    for (int i = 2; i < SIZE / 2; i++)
    {
        int j = 2;
        while (1)
        {
            int mul = i * j;
            if (mul >= SIZE)
                break;
            IsPrime[mul] = false;
            j++;
        }
    }

    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (IsPrime[nums[i] + nums[j] + nums[k]])
                    answer++;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> nums = { 1, 2, 3, 4 };
    
    cout << solution(nums) << "\n";

    return 0;
}