class Solution {
public:
  string longestPalindrome(string str) {
    string tmp_str="", llstr="";
    //check each character in the given string
    for(int i=1; i<str.length()-1; i++){
      //the center character(however not all palindromic string's length is odd number)
      tmp_str.push_back(str[i]);
      for(int k=1; i-k>=0 && i+k<=str.length(); k++){
        if(str[i+k] == str[i-k]){
          tmp_str.push_back(str[i+k]);
          tmp_str.insert(0,1,str[i+k]);
        }
        else break;
      }

      if(tmp_str.length()>llstr.length()) llstr = tmp_str;
      tmp_str.clear();
    }
    return llstr;
  }
};
