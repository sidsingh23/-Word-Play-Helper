#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>


struct TrieNode {
    std::unordered_map<char, TrieNode*> child;  // in our TrieNode "package", we got a endWord check and a map of its children
    bool endWord = false;
};

class Trie {
    
public:
    Trie();
    void addWord(const std::string& word);       // will append a word to the growing trie being made
    bool isValid(const std::string& word);       // this should check if a word is real / valid
    void loadDict(const std::string& filepath); // this will take dictionary and call addWord() on it all
    ~Trie();

private:
    TrieNode* root;
    void deleteTrie(TrieNode* node);            // will delete the trie (from the bottom up) when no longer needed
};

#endif