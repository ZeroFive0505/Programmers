#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> land, int height) 
{
    int answer = 0;
    return answer;
}

int main()
{
    vector<vector<int>> land = {
        {1, 4, 8, 10},
        {5, 5, 5, 5},
        {10, 10, 10, 10},
        {10, 10, 10, 20}
    };

    int height = 3;

    cout << solution(land, height) << "\n";

    return 0;
}