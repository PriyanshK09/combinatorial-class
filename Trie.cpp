#include <iostream>
#include <string>
#include <cstring> // for memset

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    
    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children)); // Initialize all children to null
    }
};

class Trie {
private:
    TrieNode* root;
    
    // Helper method to delete all nodes in the trie
    void deleteNode(TrieNode* node) {
        if (node == nullptr) return;
        
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                deleteNode(node->children[i]);
            }
        }
        delete node;
    }
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        deleteNode(root);
    }
    
    void insert(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isWord = true;
    }
    
    bool search(std::string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->isWord;
    }
    
    bool startsWith(std::string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};

// Example usage
int main() {
    Trie trie;
    
    // Insert words
    trie.insert("apple");
    trie.insert("application");
    trie.insert("banana");
    
    // Search for words
    std::cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not found") << std::endl;
    std::cout << "Search 'orange': " << (trie.search("orange") ? "Found" : "Not found") << std::endl;
    
    // Check prefixes
    std::cout << "Prefix 'app': " << (trie.startsWith("app") ? "Exists" : "Doesn't exist") << std::endl;
    std::cout << "Prefix 'ban': " << (trie.startsWith("ban") ? "Exists" : "Doesn't exist") << std::endl;
    std::cout << "Prefix 'cat': " << (trie.startsWith("cat") ? "Exists" : "Doesn't exist") << std::endl;
    
    return 0;
}