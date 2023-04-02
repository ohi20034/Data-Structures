#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *next[27];
    bool completedWord;
    TrieNode()
    {
        completedWord = false;
        for (int i = 0; i < 26; ++i)
        {
            next[i] = NULL;
        }
    }
} *root;

void trieinsert(string s)
{
    TrieNode *curr = root;
    for (int i = 0; i < s.size(); ++i)
    {
        int x = s[i] - 'a';
        if (curr->next[x] == NULL)
            curr->next[x] = new TrieNode();

        curr = curr->next[x];
    }
    curr->completedWord = true;
}
bool triesearch(string s)
{
    TrieNode *curr = root;

    for (int i = 0; i < s.size(); ++i)
    {
        int x = s[i] - 'a';

        if (curr->next[x] == NULL)
        {
            return false;
        }
        curr = curr->next[x];
    }
    return curr->completedWord;
}
int main()
{
    root = new TrieNode();

}
