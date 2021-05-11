#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
   
    answer = arr;

    return answer;
}

int main()
{

    vector<int> v = { 1, 1, 3,3,0, 1, 1 };

    vector<int> ans = solution(v);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

	return 0;
}
