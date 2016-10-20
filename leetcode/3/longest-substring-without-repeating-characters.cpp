class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int i,j=0,maxlen=0;
			unordered_map<char,int> alpha_table;
			for(i=0; i<s.length(); i++){
				auto it = alpha_table.find(s[i]);
				if(it != alpha_table.end()&&it->second>=j){
					if((i-j)>maxlen)
						maxlen =(i-j);
					j = it->second+1;
					alpha_table[s[i]]=i;
				}
				else{
					alpha_table[s[i]]=i;
				}
			}
			if((i-j)>maxlen)
				maxlen=i-j;
			return maxlen;
		}
};