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
	bool primitive_search(string word, TrieNode* &cproot){
	    if(word.size()==0) return false;
		//if(word.size()>=15) return false;
		int index;
		for(int i=0;i<word.size();i++){
			index=word[i]-'a';
			if(cproot->children[index]==NULL) return false;
			cproot = cproot->children[index];
		}
		return true;
	}
	//a normal search method
	bool search(string word){
	    TrieNode* cproot = root;
	    bool result = primitive_search(word, cproot);
	    if(result){
	        if(cproot->wdend==false) return false;
		    return true;
	    }
	    return false;
	}
	bool startsWith(string prefix){
		TrieNode* cproot = root;
		bool result = primitive_search(prefix, cproot);
		return result;
	}
	TrieNode* root;
};
