#include "../headers/trie.h"

#include <iostream>
using namespace std;

int main() {
    Trie trie;
    trie.loadDict("Dictionary/dictionary.txt");
    cout << "Dictionary loaded!" << endl;
    cout << trie.isValid("poop") << endl;
    cout << trie.isValid("zzzzz") << endl;
    return 0;
}