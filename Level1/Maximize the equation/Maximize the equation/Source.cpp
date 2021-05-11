#include <iostream>
#include <algorithm>
#include <stack>
#include <ctype.h>
#include <string>
#include <vector>

using namespace std;

int GetPriority(string& ops, char op)
{
    if (ops[0] == op)
        return 3;
    else if (ops[1] == op)
        return 2;
    else if (ops[2] == op)
        return 1;
}

long long solution(string expression) 
{
    long long answer = 0;
    bool minus = false;
    bool plus = false;
    bool mul = false;
    string ops;
    for (int i = 0; i < expression.size(); i++)
    {
        if (!minus && expression[i] == '-')
        {
            ops.push_back('-');
            minus = true;
        }
        else if (expression[i] == '+')
        {
            ops.push_back('+');
            plus = true;
        }
        else if (expression[i] == '*')
        {
            ops.push_back('*');
            mul = true;
        }
    }

    sort(ops.begin(), ops.end());

    do
    {
        string eq;
        string temp;
        stack<char> op_st;
        for (int i = 0; i < expression.size(); i++)
        {
            if (isdigit(expression[i]))
                temp.push_back(expression[i]);
            else if (expression[i] == '-' || expression[i] == '*' || expression[i] == '+')
            {
                eq += temp;
                eq += " ";
                temp.clear();
                if (op_st.empty())
                    op_st.push(expression[i]);
                else
                {
                    while (!op_st.empty() && GetPriority(ops, op_st.top()) <= GetPriority(ops, expression[i]))
                    {
                        char op = op_st.top();
                        op_st.pop();
                        temp.push_back(op);
                        temp.push_back(' ');
                    }
                    op_st.push(expression[i]);
                    eq += temp;

                    temp.clear();
                }
            }
        }
        
        eq += temp;
        eq += " ";
        temp.clear();

        while (!op_st.empty())
        {
            char op = op_st.top();
            op_st.pop();
            temp.push_back(op);
            temp.push_back(' ');
        }

        eq += temp;

        long long result = 0;

        size_t pos;

        stack<long long> num_st;

        while ((pos = eq.find(" ")) != string::npos)
        {
            string token = eq.substr(0, pos);

            if (isdigit(token[0]))
                num_st.push(stoi(token));
            else
            {
                long long a = num_st.top();
                num_st.pop();

                long long b = num_st.top();
                num_st.pop();

                switch (token[0])
                {
                case '+':
                    num_st.push(b + a);
                    break;
                case '-':
                    num_st.push(b - a);
                    break;
                case '*':
                    num_st.push(b * a);
                    break;
                }
            }

            eq.erase(0, pos + 1);
        }


        result = abs(num_st.top());

        answer = max(answer, result);

    } while (next_permutation(ops.begin(), ops.end()));



    return answer;
}

int main()
{
    string s = "50*6-3*2";

    cout << solution(s) << "\n";

    return 0;
}