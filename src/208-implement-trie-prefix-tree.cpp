#include <string>
using namespace std;

class Trie
{
private:
    Trie *links[26] = {nullptr};
    bool isEnd = false;

public:
    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *root = this;
        for (const auto &letter : word)
        {
            if (root->links[letter - 'a'] == nullptr)
            {
                root->links[letter - 'a'] = new Trie();
            }
            root = root->links[letter - 'a'];
        }
        root->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *root = this;
        for (const auto &letter : word)
        {
            if (root->links[letter - 'a'] == nullptr)
            {
                return false;
            }
            root = root->links[letter - 'a'];
        }
        return root->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie *root = this;
        for (const auto &letter : prefix)
        {
            if (root->links[letter - 'a'] == nullptr)
            {
                return false;
            }
            root = root->links[letter - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */