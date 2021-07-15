#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <ctype.h>
#include <vector>

using namespace std;

struct DNode
{
    int data;
    DNode* left;
    DNode* right;

    DNode(int data, DNode* left, DNode* right) : data(data), left(left), right(right) {}
};

struct DList
{
    DNode* dummy;
    DNode* head;
    DNode* tail;

    void Init()
    {
        dummy = new DNode(0, nullptr, nullptr);
        head = nullptr;
        tail = nullptr;
    }

    void PushFront(const int data)
    {
        if (head == nullptr)
        {
            head = new DNode(data, nullptr, nullptr);
            tail = head;
            head->left = dummy;
            head->right = dummy;
            dummy->right = head;
            dummy->left = tail;
        }
        else
        {
            DNode* temp = new DNode(data, nullptr, nullptr);
            dummy->right->left = temp;
            dummy->right = temp;
            temp->left = dummy;
            temp->right = head;
            head = temp;
        }
    }

    void PushAt(DNode* at, DNode* restore)
    {
        restore->left = at;
        restore->right = at->right;
        at->right->left = restore;
        at->right = restore;
    }

    DNode* RemoveAt(DNode* at)
    {
        at->left->right = at->right;
        at->right->left = at->left;

        return at;
    }

    void PushBack(const int data)
    {
        if (tail == nullptr)
        {
            tail = new DNode(data, nullptr, nullptr);
            head = tail;
            tail->left = dummy;
            tail->right = dummy;
            dummy->left = tail;
            dummy->right = tail;
        }
        else
        {
            DNode* temp = new DNode(data, nullptr, nullptr);
            tail->right->left = temp;
            temp->left = tail;
            temp->right = dummy;
            tail->right = temp;
            tail = temp;
        }
    }

    void PrintForward() const
    {
        DNode* cur;

        for (cur = dummy->right; cur != dummy; cur = cur->right)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }

    void PrintBackward() const
    {
        DNode* cur;
        for (cur = dummy->left; cur != dummy; cur = cur->left)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }
};


string solution(int n, int k, vector<string> cmd)
{
    string answer;
    for (int i = 0; i < n; i++)
        answer.push_back('X');
    DList rows;
    rows.Init();
    stack<pair<DNode*, DNode*>> rewind;

    for (int i = 0; i < n; i++)
        rows.PushBack(i);

    DNode* it = rows.dummy->right;
    DNode* temp;

    for (int i = 0; i < k; i++)
        it = it->right;

    for (int i = 0; i < cmd.size(); i++)
    {
        string order = cmd[i];

        if (order.size() == 1)
        {
            switch (order[0])
            {
            case 'C':
                rewind.push({ it->left, it });
                temp = it;
                it = it->right;
                rows.RemoveAt(temp);
                if (it == rows.dummy)
                    it = it->left;
                break;
            case 'Z':
                pair<DNode*, DNode*> t = rewind.top();
                rewind.pop();
                rows.PushAt(t.first, t.second);
                break;
            }
        }
        else
        {
            char c = 0;
            int num = 0;

            for (int j = 0; j < order.size(); j++)
            {
                if (isalpha(order[j]))
                    c = order[j];

                if (isdigit(order[j]))
                    num = num * 10 + order[j] - '0';
            }

            switch (c)
            {
            case 'U':
                for (int j = 0; j < num; j++)
                    it = it->left;
                break;
            case 'D':
                for (int j = 0; j < num; j++)
                    it = it->right;
                break;
            }
        }
    }

    for (it = rows.dummy->right; it != rows.dummy; it = it->right)
        answer[it->data] = 'O';

    return answer;
}

int main()
{
  /*  int n = 8;
    int k = 2;
    vector<string> cmd = {
       "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"
    };

    cout << solution(n, k, cmd) << "\n";*/

    DList dlist;

    dlist.Init();

    for (int i = 10; i <= 20; i++)
        dlist.PushBack(i);

    for (int i = 1; i < 10; i++)
        dlist.PushFront(i);

    dlist.PrintForward();
    dlist.PrintBackward();

    return 0;
}