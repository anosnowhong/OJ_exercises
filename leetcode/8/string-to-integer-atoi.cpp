/*
  This atoi function is designed to accepted all kinds of irregular input.
  Be aware that your task is processing the abnormal input can try to give an
  reasonable answer.
*/
class Solution {
public:
  int myAtoi(string str) {
    long result=0;
    int indicator=1;
    for(int i=0; i<str.size();){
      i = str.find_first_not_of(' ');
      if(str[i] == '-'||str[i] == '+'){
        indicator = str[i++] == '-' ? -1 : 1;
      }
      //don't need to count how many symbols
      //if the next character is not a valid number just stop and return
      while(str[i] >= '0' && str[i] <= '9'){
        result = result*10 + str[i++] - '0';
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;
      }
      return result*indicator;
    }
    return 0;
  }
};



class Solution {
public:
  int myAtoi(string str) {
    int indicator=1;
    int result=0;
    for(auto itr = str.begin(); itr!=str.end();){
      while(*itr == ' ') itr++;

      if(*itr == '-') {indicator = -1; itr++;}
      else if(*itr == '+') {indicator = 1; itr++;}

      int tmp=0;

      while(*itr - '0'>=0 && *itr-'0'<=9){
        result = result*10 + *itr - '0';
        //check overflow
        if(result/10 != tmp)
          return indicator>0?INT_MAX:INT_MIN;

        tmp = result;
        itr++;
      }
      return indicator*result;
    }
    return 0;
  }
};
