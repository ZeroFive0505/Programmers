#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size();
    set<int> p;

    for (auto i : nums)
    {
        if (p.count(i) == 0)
            p.insert(i);

        if (p.size() >= (size / 2))
            break;
    }

    answer = p.size();

    return answer;
}

int main()
{

    vector<int> n = {3, 3, 3, 2, 2, 4};
    cout << solution(n) << "\n";
    return 0;
}