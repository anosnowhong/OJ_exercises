#include <string>
#include <iostream>
#include <vector>
using namespace std;

class TrieNode{
public:
  TrieNode(){};
  bool wdend=false;
  TrieNode* children[26]{};
};

class Trie{
public:
  Trie(){
    root = new TrieNode();
  }
  ~Trie(){
    //delete pointers and array
  }
  bool insert(string word){
    if(word.size()==0) return false;//try to add invalid word.
    //if(word.size()>=15) return false;//I think no word would larger than this.
    TrieNode* cproot = root;
    int index;
    for(int i=0;i<word.size();i++){
      index = word[i]-'a';
      if(cproot->children[index]==NULL)
        cproot->children[index]=new TrieNode();//need add check if failed.
      cproot = cproot->children[index];
    }
    cproot->wdend=true;
    return true;//successfully add a word.
  }
  //a normal search method
  bool search(string word){
    TrieNode* tmp = find(word);
    if(tmp == nullptr||!(tmp->wdend)) return false;
    return true;
  }
  bool startsWith(string prefix){
    TrieNode* tmp = find(prefix);
    if(tmp == nullptr) return false;
    return true;
  }
  bool regularSearch(string word){
    if(word.size()==0) return false;
    TrieNode* cproot = root;
    int index;
    if(word[0] == '.'){
      for(int i=0;i<26;i++){//treverse 26 possibilities
        if(cproot->children[i]!=nullptr&&word.size()>1){
          auto re = findRegular(word.substr(1,word.size()), cproot->children[i]);
          if(re!=nullptr&&re->wdend==true) return true;
        }else if(cproot->children[i]!=nullptr&&cproot->children[i]->wdend) return true; // case '.'
      }
      return false;
    }
    else{
      index = word[0] - 'a';
      if(cproot->children[index]==nullptr) return false;
      if(word.size()>1){
        auto re = findRegular(word.substr(1,word.size()),cproot->children[index]);
        if(re == nullptr) return false;
        return re->wdend;
      }
      return cproot->children[index]->wdend;
    }
  }
  TrieNode* root;
private:
  TrieNode* find(const string &word){//if word is empty, return root
    auto cproot = root;
    int index;
    for(auto c : word){
      index =  c - 'a';
      if(cproot->children[index] == nullptr) return cproot->children[index];
      cproot = cproot->children[index];
    }
    return cproot;
  }
  TrieNode* findRegular(const string &word, TrieNode* cproot){
    int index;
    if(word[0] == '.'){
      for(int i=0;i<26;i++){//treverse 26 possibilities
        if(cproot->children[i]!=nullptr&&word.size()>1){
          auto re = findRegular(word.substr(1,word.size()),cproot->children[i]);//!!!!!!!!!
          if(re != nullptr&& re->wdend) return re;
        }else if(cproot->children[i]!=nullptr&&cproot->children[i]->wdend) return cproot->children[i];
      }
      return nullptr;
    }
    else{
      index = word[0] - 'a';
      if(cproot->children[index]==nullptr) return cproot->children[index];
      if(word.size()>1){
        return findRegular(word.substr(1,word.size()),cproot->children[index]);
      }else return cproot->children[index];
    }
  }

};




class WordDictionary {
public:
  Trie dict;
  WordDictionary(){}
  // Adds a word into the data structure.
  void addWord(string word) {
    dict.insert(word);
  }

  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    return dict.regularSearch(word);
  }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

