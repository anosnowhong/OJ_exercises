/*
时间限制：1秒 空间限制：32768K
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
http://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?rp=1&ru=/ta/coding-interviews
*/
#include <iostream>
//#include <>
using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        int result = combination(number);
        return result;
    }
   	int combination(int number){
        int numof2;
        if(number%2==0)
            numof2=number/2;
        else
            numof2=number/2;
        int sum=0;
        for(int i=0;i<=numof2;i++){
            sum+=c_n_k(number-i,i);
        }
        return sum;
    }
    int c_n_k(int n, int k){

        //k=9;n=16;
		if (k==0)
			return 1;

       	long akk=k;
        for(int i=k-1;i>0;i--){
            akk*=i;
        }


        long ank=n;
        for(int i=n-1;i>n-k;i--){
            ank*=i;
            //cout<<ank<<" ";
        } 
        /*
        cout<<"===="<<endl;
        cout<< n<<" "<< k<<endl;
        cout<< ank<<" "<< akk<<endl;
        */
        return ank/akk;
    }
};


int main(){
	Solution mm;
	int input;
	cin>>input;
	int result = mm.jumpFloor(input);
    cout<<result<<endl;

	return 0;
}
