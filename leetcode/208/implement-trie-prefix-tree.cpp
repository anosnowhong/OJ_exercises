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
};
