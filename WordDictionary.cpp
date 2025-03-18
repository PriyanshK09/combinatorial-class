// Solution for LeetCode problem: 211. Add and Search Word - Data structure design
// Problem link: https://leetcode.com/problems/add-and-search-word-data-structure-design/

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};
class WordDictionary {
private:
    TrieNode* root;

    bool searchInNode(const string& word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isEndOfWord;
        }

        char ch = word[index];
        if (ch == '.') {
            for (auto& pair : node->children) {
                if (searchInNode(word, pair.second, index + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            if (node->children.find(ch) != node->children.end()) {
                return searchInNode(word, node->children[ch], index + 1);
            } else {
                return false;
            }
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        return searchInNode(word, root, 0);
    }
};
// Example usage
int main() {
    WordDictionary wordDict;
    wordDict.addWord("bad");
    wordDict.addWord("dad");
    wordDict.addWord("mad");
    cout << wordDict.search("pad") << endl; // return False
    cout << wordDict.search("bad") << endl; // return True
    cout << wordDict.search(".ad") << endl; // return True
    cout << wordDict.search("b..") << endl; // return True
    return 0;
}
// This code implements a WordDictionary class that allows adding words and searching for them.
// It uses a Trie data structure to efficiently store and search for words.
// The search function supports the '.' wildcard character, which can match any letter.
// The addWord function adds a word to the dictionary, and the search function checks if a word exists in the dictionary.
// The search function can also handle patterns with wildcards, making it flexible for various search queries.
// The TrieNode class represents each node in the Trie, with a map of children nodes and a boolean flag to indicate if it's the end of a word.
// The main function demonstrates how to use the WordDictionary class by adding words and performing searches.

