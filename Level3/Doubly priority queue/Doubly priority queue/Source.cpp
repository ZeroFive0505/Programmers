#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class DBPQ
{
private:
    set<int> s;
public:
    inline int GetSize()
    {
        return s.size();
    }

    inline bool IsEmpty()
    {
        return s.size() == 0;
    }

    inline void Insert(int x)
    {
        s.insert(x);
    }

    inline int GetMin()
    {
        return (*s.begin());
    }

    inline int GetMax()
    {
        return (*s.rbegin());
    }

    inline void DeleteMin()
    {
        if(!IsEmpty())
            s.erase(s.begin());
    }

    inline void DeleteMax()
    {
        if (!IsEmpty())
        {
            set<int>::const_iterator it = s.end();
            it--;
            s.erase(it);
        }
    }
};

vector<int> solution(vector<string> operations) 
{
    vector<int> answer;
    DBPQ db_pq;
    for (int i = 0; i < operations.size(); i++)
    {
        stringstream ss(operations[i]);

        char op;

        ss >> op;

        int num;

        ss >> num;

        switch (op)
        {
        case 'I':
            db_pq.Insert(num);
            break;
        case 'D':
            
            if (num == 1)
                db_pq.DeleteMax();
            else if (num == -1)
                db_pq.DeleteMin();

            break;
        }
    }

    if (db_pq.IsEmpty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(db_pq.GetMax());
        answer.push_back(db_pq.GetMin());
    }

    return answer;
}

int main()
{
    vector<string> operations = { "I 7","I 5","I -5","D -1" };

    vector<int> ans = solution(operations);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

    return 0;
}