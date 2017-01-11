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
    long long re = 0;
    while(x!=0){
      re = re*10 + x%10;
      x = x/10;
    }
    if(re>INT_MAX||re<INT_MIN) return 0;
    return re;
  }
};

/*
  Instead of using long long, a more common solution is
  to make the use of calculation relationship.
  Backup the accumulating number do a math calculation, if
  the result is as expected, it's ok. Otherwise, it may overflow.
 */
class Solution2 {
public:
  int reverse(int x) {
    int re = 0;
    while(x!=0){
      int tmp = re*10 + x%10;
      if(tmp/10 != re) return 0;
      re = tmp;
      x = x/10;
    }
    return re;
  }
};
