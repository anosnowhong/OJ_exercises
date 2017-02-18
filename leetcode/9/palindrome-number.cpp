class Solution {//A BETTER VERSION
public:
  bool isPalindrome(int x) {
    if(x<0||x!=0&&x%10==0) return false;
    int sum = 0;
    while(x>sum){ //if x is a palindrome number, in the progress of building number 'sum', sum won't larger than x.
      //when at the middle of integer, x is equal to sum.
      sum = sum*10 + x%10;
      x = x/10;
    }
    return (x==sum||x==sum/10);
  }
};

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
