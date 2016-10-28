class Solution {
public:
    string addBinary(string a, string b) {
      //don't need to handle the different length
      //put string a and b in a while loop, and use
      //seperate index to retrive member.
      int i = a.size()-1;
      int j = b.size()-1;
      string s;
      int c=0;
      while(i>=0||j>=0||c==1){
        c+= i>=0 ? a[i--] - '0':0;
        c+= j>=0 ? b[j--] - '0':0;
        s += char(c%2+'0');
        c /= 2;
      }
      return s;
    }
};
