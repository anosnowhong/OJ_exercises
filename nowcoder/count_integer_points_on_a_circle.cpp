#include <iostream>
#include <math.h>
using namespace std;

int main(){
  double radius_square;
  cin>>radius_square;
  double limit = sqrt(radius_square);
  int amount = 0;
  for(int i=1; i<limit; i++){
    for(int j=1; j<limit; j++){
      if(i*i + j*j == radius_square)
        amount++;
    }
  }
  if(limit - floor(limit) > 0)
    cout<<amount*4 <<endl;
  else
    cout<<amount*4 + 4<<endl;
  return 0;
}
