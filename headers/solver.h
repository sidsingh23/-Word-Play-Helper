#ifndef SOLVER_H
#define SOLVER_H

#include "trie.h"

#include <unordered_map>
#include <string>
#include <vector>

class Solver {

public:
    Solver(Trie& Trie);
    std::vector<std::string> findWords(const std::string& letters);

private:
    Trie& Trie;
    void search(TrieNode* node, std::unordered_map<char, int>& freq, std::string& curr, std::vector<std::string>& results);

};

#endif