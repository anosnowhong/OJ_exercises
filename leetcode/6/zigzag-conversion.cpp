class Solution {
public:
  string convert(string s, int R) {
    string output;
    bool sw;
    int k;
    for(int j=0;j<R;j++){
      sw=true;
      k=j;
      for(;k<s.length();){
        if(j==0||j==R-1){
          output += s[k];
          k+=2*(R-1);
        }
        else{
          if(sw){
            output += s[k];
            k+=2*(R-j-1);
            sw=false;
          }
          else{
            output += s[k];
            k+=2*j;
            sw=true;
          }
        }
      }
    }
    return output;
  }
};
