#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int index = 0;

    for (int i = 1; i <= n;)
    {
        if (index < stations.size() && i >= stations[index] - w && i <= stations[index] + w)
        {
            i = stations[index] + w;
            index++;
            i++;
        }
        else
        {
            i += (w * 2) + 1;
            answer++;
        }
    }

    return answer;
}

int main()
{
    int n = 11;
    vector<int> stations = { 4, 11 };
    int w = 1;

    cout << solution(n, stations, w) << "\n";

    return 0;
}