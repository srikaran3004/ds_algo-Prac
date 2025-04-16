#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* ref[26];
    bool end = false;
    int prefixLike = 0;

    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            ref[i] = nullptr;
        }
    }

    // Insert a character
    void insertNode(char ch, TrieNode* newNode) {
        ref[ch - 'a'] = newNode;
    }

    // Get the node corresponding to a character
    TrieNode* getNode(char ch) {
        return ref[ch - 'a'];
    }

    // Check if a node for the character exists
    bool ifCharPresent(char ch) {
        return ref[ch - 'a'] != nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Method to add a word to the trie
    void insertWord(string word) {
        TrieNode* copy = root;
        for (char ch : word) { // Traverse each character in the word
            if (!copy->ifCharPresent(ch)) {
                copy->insertNode(ch, new TrieNode());
            }
            copy = copy->getNode(ch);
            copy->prefixLike++;
        }
        copy->end = true;
    }

    // Method to search for a word in the trie
    bool searchWord(string word) {
        TrieNode* copy = root;
        for (char ch : word) { // Traverse each character in the word
            if (!copy->ifCharPresent(ch)) {
                return false;
            }
            copy = copy->getNode(ch);
        }
        return copy->end;
    }

    // Method to delete a word from the trie
    void deleteWord(string word) {
        TrieNode* copy = root;
        for (char ch : word) { // Traverse each character in the word
            if (!copy->ifCharPresent(ch)) {
                return; // Word not found
            }
            copy = copy->getNode(ch);
            copy->prefixLike--;
        }
        copy->end = false;
    }
};

int main() {
    Trie trie;
    trie.insertWord("son");
    trie.insertWord("song");

    cout << (trie.searchWord("son") ? "Found" : "Not Found") << endl; // Output: Found
    cout << (trie.searchWord("sun") ? "Found" : "Not Found") << endl; // Output: Not Found

    trie.deleteWord("son");
    cout << (trie.searchWord("son") ? "Found" : "Not Found") << endl; // Output: Not Found
    cout << (trie.searchWord("song") ? "Found" : "Not Found") << endl; // Output: Found

    return 0;
}