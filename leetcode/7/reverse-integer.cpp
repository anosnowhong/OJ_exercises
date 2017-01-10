/*
  Method 1:
  Push each number of a Integer from its right side to a string, you can get a inverse integer but stored in the string.
  Then convert string to Integer, check if the original number is negative or positive, get the finnal Integer.

  Method 2:
  A string is not necessary, cause you can form a number just using math.
*/

class Solution {
public:
  int reverse(int x) {
    if(x == 0) return 0;
    long long re = 0;
    while(x!=0){
      re = re*10 + x%10;
      x = x/10;
    }
    if(re>INT_MAX||re<INT_MIN) return 0;
    return re;
  }
};
