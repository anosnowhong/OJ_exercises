class Solution {
public:
    string addBinary(string a, string b) {
        int len;
        string result;
        //**not changing original input
        int diff = a.length()-b.length();
        diff<0?len=b.length():len=a.length();
        if(diff==0&&a.length()==0)
            return result;
            
        int sum,promote=0;
        for(int i=len-1;i>=0;i--){
            if(diff==0){
                sum = (a[i]-'0')+(b[i]-'0')+promote;
            }
            else if(diff<0){
                if(i+diff>=0)//diff is negative so i--diff
                    sum = (a[i+diff]-'0')+(b[i]-'0')+promote;//diff is negative so a[i--diff]
                else
                    sum = (b[i]-'0')+promote;
            }
            else{
                if(i-diff>=0)
                    sum = (a[i]-'0')+(b[i-diff]-'0')+promote;
                else
                    sum = (a[i]-'0')+promote;
            }
            
            cout<<sum<<endl;    
            
            if(sum==2){
                result+='0';
                promote=1;
            }
                
            else if(sum==3){
                result+='1';
                promote=1;
            }
            else if(sum==1){
                result+='1';
                promote=0;
            }
                
            else{
                result+='0';
                promote=0;
            }
                
        }
        if(promote==1)
            result+='1';
        reverse(result.begin(), result.end());
        return result;
    }
};
