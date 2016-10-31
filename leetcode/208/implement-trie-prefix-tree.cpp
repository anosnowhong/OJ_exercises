/*
type* ins[size];
memset(ins, 0x00, sizeof(ins));

vector<type *> ins;
ins(52,NULL);
*/

class TrieNode {
public:
  static const int MAX_BRANCHES;
  // Initialize your data structure here.
  TrieNode() {
    //childNodes = new TrieNode[26];
    //childNodes(26,NULL);
    childNodes.resize(27);
  }
  //TrieNode[] childNodes;
  vector<TrieNode *> childNodes;
  //TrieNode * childNodes[MAX_BRANCHES];
  char nodeChar;
};

class Trie {
public:
  Trie() {
    root = new TrieNode();
    cpoint = root;
  }

  // Inserts a word into the trie.
  void insert(string word) {
    cpoint = root;
    
    if(word.length()==0) return;
    for(int i=0;i<word.length();i++){
      int id = word[i]-'a';
      if(cpoint->childNodes[id] == NULL){
        cpoint->childNodes[id] = new TrieNode();
        cpoint->childNodes[id]->nodeChar=word[i];
      }
      cpoint = cpoint->childNodes[id];
    }
    if(cpoint->childNodes[26] == NULL){
        cpoint->childNodes[26] = new TrieNode();
        cpoint->childNodes[26]->nodeChar='\0';
    }

  }

  // Returns if the word is in the trie.
  bool search(string word) {
    cpoint = root;
    if(word.length()==0) return false;
    for(int i=0;i<word.length();i++){
      int id = word[i]-'a';
      if(cpoint->childNodes[id] == NULL)
        return false;
      cpoint = cpoint->childNodes[id];
    }
    if(cpoint->childNodes[26] == NULL) return false;
    else if(cpoint->childNodes[26]->nodeChar=='\0') return true;
    return false;
  }

  // Returns if there is any word in the trie
  // that starts with the given prefix.
  bool startsWith(string prefix) {
    cpoint = root;
    if(prefix.length()==0) return false;
    for(int i=0;i<prefix.length();i++){
      int id = prefix[i]-'a';
      if(cpoint->childNodes[id] == NULL)
        return false;
      cpoint = cpoint->childNodes[id];
    }
 
    return true;
  }

private:
  TrieNode* root;
  TrieNode* cpoint;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
