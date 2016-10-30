//similar to 67
class Solution {
public:
  string addStrings(string num1, string num2) {
    string re;
    int i=num1.length()-1, j =num2.length()-1;
    int sum=0;
    while(i>=0||j>=0||sum>0){
      sum += i>=0?num1[i--]-'0':0;
      sum += j>=0?num2[j--]-'0':0;
      sum>=10?re+=to_string(sum%10):re+=to_string(sum);
      sum=(sum-sum%10)/10;
    }
    reverse(re.begin(),re.end());
    return re;
  }
};
