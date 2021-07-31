#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int PROFIT = 100;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    vector<int> answer;
    map<string, string> hashRef;
    map<string, int> hashProfit;

    for (int i = 0; i < enroll.size(); i++)
    {
        hashRef[enroll[i]] = referral[i];
        hashProfit[enroll[i]] = 0;
    }



    for (int i = 0; i < seller.size(); i++)
    {
        string name = seller[i];
        int profit = amount[i] * PROFIT;
        hashProfit[name] += profit;
        string ref = hashRef[name];

        while (1)
        {
            double percent = (int)(profit * 0.1f);

            if (percent <= 0.0f)
                break;

            if (ref == "-")
            {
                if(percent >= 1.0)
                    hashProfit[name] -= (int)percent;
                break;
            }
			else if (percent >= 1.0)
			{
				hashProfit[name] -= (int)percent;
				hashProfit[ref] += (int)percent;
			}
   
            name = ref;
            ref = hashRef[name];
            profit = percent;
        }
    }

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(hashProfit[enroll[i]]);

    return answer;
}

int main()
{
    vector<string> enroll = {
        "john",
        "mary",
        "edward",
        "sam",
        "emily",
        "jaimie",
        "tod",
        "young"
    };

    vector<string> referral = {
        "-",
        "-",
        "mary",
        "edward",
        "mary",
        "mary",
        "jaimie",
        "edward"
    };

    vector<string> seller = {
        "young",
        "john",
        "tod",
        "emily",
        "mary"
    };

    vector<int> amount = { 12, 4, 2, 5, 10 };


    vector<int> ans = solution(enroll, referral, seller, amount);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}