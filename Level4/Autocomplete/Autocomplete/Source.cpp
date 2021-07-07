#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct sTrie
{
    bool terminate;
    int childCount;
    sTrie* next[26];

    sTrie() : terminate(false), childCount(0)
    {
        fill(next, next + 26, nullptr);
    }

    ~sTrie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (next[i])
                delete next[i];
        }
    }

    void Insert(const char* key)
    {
        childCount++;
        if (*key == '\0')
            terminate = true;
        else
        {
            int cur = *key - 'a';

            if (next[cur] == nullptr)
                next[cur] = new sTrie();
            next[cur]->Insert(key + 1);
        }
    }

    int find(const char* key, int cnt)
    {
        if (*key == '\0' || childCount == 1)
            return cnt;

        int cur = *key - 'a';

        return next[cur]->find(key + 1, cnt + 1);
    }
};

int solution(vector<string> words) 
{
    int answer = 0;
    sTrie trie;

    for (int i = 0; i < words.size(); i++)
    {
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
        trie.Insert(words[i].c_str());
    }


    for (int i = 0; i < words.size(); i++)
    {
        answer = answer + trie.find(words[i].c_str(), 0);
    }


    return answer;
}

int main()
{
    vector<string> words = {
        "word","war","warrior","world"
    };

    cout << solution(words) << "\n";

    return 0;
}