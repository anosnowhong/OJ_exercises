#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
  int addDigits(int num) {
    //transform
    ostringstream ss;
    ss<<num;
    string s = ss.str();
    int sum;

    //loop
    while(true){
      sum = 0;
      for(int i=0;i<s.length();i++){
        sum+=s[i]-'0';
      }

      if(sum>=10){
        ostringstream ss;
        ss<<sum;
        s = ss.str();
      }
      else
        break;
    }
    return sum;

  }
};

int main()
{
  Solution ad;
  ad.addDigits(19);
  return 0;
}
