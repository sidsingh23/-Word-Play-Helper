#include "trie.h"
#include <iostream>
#include <fstream>
#include <string>

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


void Trie::loadDict(const string& filepath) {       // loading from filepath for now
    ifstream file(filepath);
    if(!file.is_open())
    {
        cout << "Error: Dictionary didn't load." << endl;
        return;
    }

    string word;
    while(getline(file, word))
    {
        addWord(word);
    }
    file.close();
}


void Trie::deleteTrie(TrieNode* node) {
    for(auto& pack : node -> child)
    {
            deleteTrie(pack.second);
    }
    delete node;
}


Trie::~Trie() {
    deleteTrie(root);
}