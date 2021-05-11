#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) 
{
    int answer;

    vector<int>::iterator it1, it2;

    it1 = a.begin();
    it2 = b.begin();
    int sum = 0;

    while (it1 != a.end() && it2 != b.end())
    {
        sum += (*it1) * (*it2);
        it1++;
        it2++;
    }

    answer = sum;

    return answer;
}

int main()
{
    vector<int> a{ -1, 0, 1 };
    vector<int> b{ 1, 0, -1 };

    cout << solution(a, b) << "\n";

	return 0;
}