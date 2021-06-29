#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct sTrie
{
    sTrie* node[26];
    int count;
    bool terminate;

    sTrie() : terminate(false), count(1)
    {
        for (int i = 0; i < 26; i++)
            node[i] = nullptr;
    }

    ~sTrie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (node[i])
                delete node[i];
        }
    }

    void Insert(const char* key)
    {
        if (*key == '\0')
            terminate = true;
        else
        {
            int currIdx = *key - 'a';
            if (node[currIdx] == nullptr)
                node[currIdx] = new sTrie();
            else
                node[currIdx]->count++;
            node[currIdx]->Insert(key + 1);
        }
    }

    int Find(const char* key)
    {
        int currIdx = *key - 'a';

        if (*key == '?')
        {
            int temp = 0;

            for (int i = 0; i < 26; i++)
            {
                if (node[i] != nullptr)
                    temp += node[i]->count;
            }

            return temp;
        }

        if (node[currIdx] == nullptr)
            return 0;

        if (*(key + 1) == '?')
            return node[currIdx]->count;

        return node[currIdx]->Find(key + 1);
    }
};

const int SIZE = 10001;

sTrie* trie[SIZE];
sTrie* reverse_trie[SIZE];

vector<int> solution(vector<string> words, vector<string> queries) 
{
    int wSize = words.size();
    int qSize = queries.size();
    vector<int> answer(qSize, 0);

    for (int i = 0; i < wSize; i++)
    {
        int size = words[i].size();

        const char* key = words[i].c_str();

        if (trie[size] == nullptr)
            trie[size] = new sTrie();

        trie[size]->Insert(key);

        string r_str = words[i];

        reverse(r_str.begin(), r_str.end());

        const char* r_key = r_str.c_str();

        if (reverse_trie[size] == nullptr)
            reverse_trie[size] = new sTrie();

        reverse_trie[size]->Insert(r_key);
    }

    int idx = 0;

    for (auto& s : queries)
    {
        int size = s.size();

        if (s[size - 1] == '?')
        {
            const char* c = s.c_str();

            if (trie[size] == nullptr)
            {
                idx++;
                continue;
            }
            else
                answer[idx] = trie[size]->Find(c);
        }
        else
        {
            string rev = s;
            reverse(rev.begin(), rev.end());

            const char* c = rev.c_str();

            if (reverse_trie[size] == nullptr)
            {
                idx++;
                continue;
            }
            else
                answer[idx] = reverse_trie[size]->Find(c);
        }

        idx++;
    }

    return answer;
}

int main()
{
    vector<string> words = {
        "frodo",
        "front",
        "frost",
        "frozen",
        "frame",
        "kakao"
    };

    vector<string> queris = {
        "fro??",
        "????o",
        "fr???",
        "fro???",
        "pro?"
    };

    vector<int> ans = solution(words, queris);

    for (auto i : ans)
        cout << i << " ";
    cout << "\n";

	return 0;
}