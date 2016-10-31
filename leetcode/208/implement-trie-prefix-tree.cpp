/*
  1.Actually we don't need to save a char to TrieNode, as the index can
  also be refered to as a letter.
  2.Using a boolean value to represent a node is an end of a word or not.
  3.Remember to initialize pointers `TrieNode * childNodes[26]={NULL}`
 */
#include <iostream>
using namespace std;

class TrieNode {
public:
  // Initialize your data structure here.
  TrieNode() {
    //childNodes = new TrieNode[26];
    //childNodes(26,NULL);
    //childNodes.resize(27);
  }
  //TrieNode[] childNodes;
  //vector<TrieNode *> childNodes;
  TrieNode * childNodes[26]={NULL};
  bool isNode = false;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
  }

  // Inserts a word into the trie.
  void insert(string word) {
    TrieNode *current = root;
    for(int i=0;i<word.length();i++){
      int index = word[i] - 'a';
      if(current->childNodes[index] == NULL)
        current->childNodes[index] = new TrieNode();
      current = current->childNodes[index];
    }
    current->isNode = true;
  }

  // Returns if the word is in the trie.
  bool search(string word) {
    TrieNode *current = root;
    for(int i=0;i<word.length();i++){
      int index = word[i] - 'a';
      if(current->childNodes[index] != NULL)
        current = current->childNodes[index];
      else
        return false;
    }
    if(current->isNode == true) return true;
    else return false;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    TrieNode *current = root;
    for(int i=0;i<prefix.length();i++){
      int index = prefix[i] - 'a';
      if(current->childNodes[index] != NULL)
        current = current->childNodes[index];
      else
        return false;
    }
    return true;
  }

private:
  TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
