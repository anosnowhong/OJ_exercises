/*
http://www.nowcoder.com/test/question/0147cbd790724bc9ae0b779aaf7c5b50?pid=2811407&tid=5417496
如果一个数字序列逆置之后跟原序列是一样的就称这样的数字序列为回文序列。例如：
{1, 2, 1}, {15, 78, 78, 15} , {112} 是回文序列, 
{1, 2, 2}, {15, 78, 87, 51} ,{112, 2, 11} 不是回文序列。
现在给出一个数字序列，允许使用一种转换操作：
选择任意两个相邻的数，然后从序列移除这两个数，并用这两个数字的和插入到这两个数之前的位置(只插入一个和)。
现在对于所给序列要求出最少需要多少次操作可以将其变成回文序列。

输入描述:
输入为两行，第一行为序列长度n ( 1 ≤ n ≤ 50)
第二行为序列中的n个整数item[i]  (1 ≤ iteam[i] ≤ 1000)，以空格分隔。


输出描述:
输出一个数，表示最少需要的转换次数

输入例子:
4
1 1 1 3

输出例子:
2
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void reset_card(vector<int> &card, int times){
    vector<int> new_card;
    
    for(int j=times;j>0;j--){
        
        bool left=false;
        //left and right size of card
        int left_s=card.size()/2;
        int right_s=card.size();

        for(int i=0;i<card.size();i++){

            if(left){
                new_card.push_back(card[left_s-1]);
                left_s--;
                left=false;
            }else{
								new_card.push_back(card[right_s-1]);
                right_s--;
                left=true;
            }
        }
    reverse(new_card.begin(), new_card.end());
    card.clear();
    card.insert(card.begin(),new_card.begin(),new_card.end());
		new_card.clear();
    }
}

int main(int argc, char **argv){
    int times, n, k;
    cin>>times;
    for(int tt=times;tt>0;tt--){
        
        cin>>n;
        cin>>k;
        vector<int> card;
        int current_card;
        for(int i=0;i<2*n;i++){
            cin>>current_card;
            card.push_back(current_card);
        }

        reset_card(card,k);
    	
        for(int p=0;p<card.size();p++){
            cout<<card[p]<<" ";
        }
				cout<<endl;
				card.clear();
    }
    
    return 0;
}