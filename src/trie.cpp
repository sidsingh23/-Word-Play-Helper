#include "trie.h"

using namespace std;


Trie::Trie() {
    root = new TrieNode;
}


void Trie::addWord(const string& word) {
    TrieNode* curr = root;
    for(char c : word)
    {
        if(curr -> child.find(c) == curr -> child.end())
        {
            curr -> child[c] = new TrieNode;
        }
        curr = curr -> child[c];
    }
    curr -> endWord = true;
}


bool Trie::isValid(const string& word) {
    TrieNode* curr = root;
    for(char c : word)
    {
        if(curr -> child.find(c) == curr -> child.end())
        {
            return false;
        }
        curr = curr -> child[c];
    }
    return curr -> endWord;
}


void Trie::loadDict(const string& filepath) {
    //ifstream file(*C:///whatever.txt*);
    //file.close()
}


void Trie::deleteTrie(TrieNode* node) {

}


Trie::~Trie() {
    deleteTrie(root);
}