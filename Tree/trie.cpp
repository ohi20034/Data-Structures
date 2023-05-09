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
        int x = s[i]-'a';
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
bool isEmpty(TrieNode * root)
{
    for(int i=0; i<26; ++i)
    {
        if(root->next[i])
            return false;
    }
    return true;
}
TrieNode *Remove(TrieNode *root,string &key,int depth=0)
{
    if(!root)
    {
        return NULL;
    }
    if(depth==key.size())
    {
        if(root->completedWord)
        {
            root->completedWord = false;
        }
        if(isEmpty(root))
        {
            delete (root);
        }
        return root;
    }
    int index = key[depth]-'a';
    root->next[index] = Remove(root->next[index],key,depth+1);
    if(isEmpty(root) && root->completedWord==false)
    {
        delete(root);
        root = NULL;
    }
    return root;
}
int main()
{
    root = new TrieNode();
    trieinsert("ohi") ;
    cout <<triesearch("ohi")<< endl;
    string s="ohi";
    Remove(root,s);
    cout <<triesearch("ohi")<< endl;
}
