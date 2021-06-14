#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct sPage
{
    int idx;
    int match;
    int link;
    double score;
};

int solution(string word, vector<string> pages) 
{
    int size = word.size();
    map<string, int> pageHash;
    vector<sPage> v;
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (int i = 0; i < pages.size(); i++)
    {
        string& html = pages[i];
        transform(html.begin(), html.end(), html.begin(), ::tolower);

        int mid = 0;
        int left = 0;
        int right;

        while (mid <= left)
        {
            left = html.find("<meta", left + 1);
            right = html.find(">", left);

            mid = html.rfind("https://", right);
        }

        right = html.find("\"", mid);

        string url = html.substr(mid, right - mid);

        left = html.find("<body>", right);

        int matching = 0;

        for (int start = left; ; )
        {
            start = html.find(word, start + 1);

            if (start == string::npos)
                break;

            if (!isalpha(html[start - 1]) && !isalpha(html[start + size]))
            {
                matching++;
                start += size;
            }
        }

        int link = 0;

        for (int start = left; ;)
        {
            start = html.find("<a href", start + 1);

            if (start == string::npos)
                break;
            link++;
        }

        pageHash[url] = i;
        v.push_back({ i, matching, link, (double)matching });
    }

    for (int i = 0; i < pages.size(); i++)
    {
        string& html = pages[i];

        for (int left = 0, right = 0; ;)
        {
            left = html.find("<a href", right);
            
            if (left == string::npos)
                break;

            left = html.find("https://", left);
            right = html.find("\"", left);

            string linkUrl = html.substr(left, right - left);

            map<string, int>::iterator it = pageHash.find(linkUrl);

            if (it != pageHash.end())
            {
                v[it->second].score += (double)v[i].match / v[i].link;
            }
        }
    }

    sort(v.begin(), v.end(), [](const sPage& a, const sPage& b) {
        if (a.score == b.score)
            return a.idx < b.idx;
        else
            return a.score > b.score;
    });

    int answer = v.begin()->idx;
    return answer;
}

int main()
{
    string word = "blind";
    vector<string> pages = {
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", 
        "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
    };

    cout << solution(word, pages) << "\n";

    return 0;
}