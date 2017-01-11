class Solution {
public:
    int myAtoi(string str) {
       //get a valid string
       auto itr = str.begin();
       while(*itr == ' ') itr++;
       auto ss = itr;
       while(*itr != ' ' && itr != str.end()) itr++;
       auto ee = itr-1;
       string new_str = str.substr(ss-str.begin(), ee-ss+1);
       cout<<new_str<<endl;
       //transfer to integer within valid range
       itr = new_str.begin();
       int sym_num=0;
       while(*itr - '0' < 0 && itr != new_str.end()){
           if(*itr == '+'||*itr == '-') sym_num++;
           itr++;
       }
       if(sym_num>1) return 0;
       if(itr == new_str.end()) return 0;

       int result=0,tmp=0;
       while(itr != new_str.end()){
           //handle alpha character 
           if(*itr - '0'<=9 && *itr - '0'>=0) result = result*10 + *itr - '0';
           else break;
           //handle overflow case
           if(result/10 != tmp && *new_str.begin() == '-') return INT_MIN;
           else if(result/10!=tmp) return INT_MAX;

           tmp = result;
           itr++;
       }
       if(*new_str.begin()=='-') return -result;
       else return result;
    }
};
