#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct sNode
{
    int x;
    int y;
    int id;

    sNode(int x = 0, int y = 0, int id = -1)
    {
        this->x = x;
        this->y = y;
        this->id = id;
    }
};

struct sTree
{
    int id;
    int x;
    sTree* left;
    sTree* right;

    sTree(int id, int x, sTree* left, sTree* right)
    {
        this->id = id;
        this->x = x;
        this->left = left;
        this->right = right;
    }
};


vector<int> preOrder;
vector<int> postOrder;
sTree* root;

void PostOrder(sTree* node)
{
    if (node != nullptr)
    {
        PostOrder(node->left);
        PostOrder(node->right);
        postOrder.push_back(node->id);
    }
}

void PreOrder(sTree* node)
{
    if (node != nullptr)
    {
        preOrder.push_back(node->id);
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;

    vector<sNode> v;
    int id = 1;
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        v.push_back(sNode(x, y, id++));
    }

    sort(v.begin(), v.end(), [](const sNode& a, const sNode& b) {
        if (a.y != b.y)
            return a.y > b.y;
        else
            return a.x < b.x;
    });

    root = nullptr;

    root = new sTree(v[0].id, v[0].x, nullptr, nullptr);


    for (int i = 1; i < v.size(); i++)
    {
        sTree* cur = root;
        sTree* parent = nullptr;
        while (cur)
        {
            parent = cur;
            if (cur->x > v[i].x)
                cur = cur->left;
            else
                cur = cur->right;
        }

        if (v[i].x < parent->x)
            parent->left = new sTree(v[i].id, v[i].x, nullptr, nullptr);
        else
            parent->right = new sTree(v[i].id, v[i].x, nullptr, nullptr);
    }

    PreOrder(root);
    PostOrder(root);

    answer.push_back(preOrder);
    answer.push_back(postOrder);
    return answer;
}

int main()
{
    vector<vector<int>> nodeinfo = {
        {5, 3},
        {11, 5},
        {13, 3},
        {3, 5},
        {6, 1},
        {1, 3},
        {8, 6},
        {7, 2},
        {2, 2}
    };

    vector<vector<int>> ans = solution(nodeinfo);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}