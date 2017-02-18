class Solution {
public:
  bool isPalindrome(int x) {
    if(x<0) return false;
    int re=0;
    int backup = x;

    while(x){
      int tmp = re;
      re = re*10 + x%10;
      if(re/10 != tmp) return false; //palindrome number won't overflow
      x=x/10;
    }

    if(re==backup) return true;
    else return false;
  }
};
