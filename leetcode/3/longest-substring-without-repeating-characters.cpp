class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int count=0,maxlen=0;
			unordered_map<char,int> alpha_table;
			for(int i=0; i<s.length(); i++){
				auto it = alpha_table.find(s[i]);
				if(it != alpha_table.end()){
					alpha_table.clear();
					if(count>maxlen)
						maxlen = count;
					//go back 1 offset
					//i--;//this only take the constant repeat into consideration not the repeat between several letters
					i = it->second;
					count=0;
				}
				else{
					alpha_table.insert({s[i], i});
					count++;
				}
			}
			//if there is no repeat untill the end of a string
			if(count>maxlen)
				maxlen = count;

			//cout<<maxlen<<endl;

			return maxlen;
		}
};