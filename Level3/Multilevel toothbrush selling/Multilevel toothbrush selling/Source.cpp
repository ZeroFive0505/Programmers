#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

const int PROFIT = 100;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) 
{
    vector<int> answer;
    unordered_map<string, string> hashRef;
    unordered_map<string, int> hashProfit;
   

    for (int i = 0; i < enroll.size(); i++)
    {
        hashRef[enroll[i]] = referral[i];
        hashProfit[enroll[i]] = 0;
    }


    for (int i = 0; i < seller.size(); i++)
    {
        string name = seller[i];
        int amt = amount[i];

        int money = PROFIT * amt;

        hashProfit[name] += money;

      
            string ref = hashRef[name];
            while (1)
            {
                double p = (int)(money * 0.1);

                if (ref == "-")
                {
                    if (p >= 1)
                        hashProfit[name] -= (int)p;

                    break;
                }

                if (p >= 1)
                {
                    hashProfit[name] -= (int)p;
                    hashProfit[ref] += (int)p;
                }

                money = p;
                name = ref;
                ref = hashRef[name];
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