#include "../headers/solver.h"
#include "../headers/trie.h"

using namespace std;

vector<string> Solver::findWords(const string& letters) {
    vector<string> words;
    unordered_map<char, int> lettercount;

    for (char c : letters)
    {
        lettercount[c]++;
    }

    string currWurr = "";
    search(trie.root, lettercount, currWurr, words);
    
    return words;
}


void Solver::search(TrieNode* node, unordered_map<char, int>& lettercount, string& currWurr, vector<string>& results) {
    if(node -> endWord == true && currWurr.size() >= 4)
        results.push_back(currWurr);

}