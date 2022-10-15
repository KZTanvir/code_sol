#include <iostream>
using namespace std;
int main(void) {
   int x,y,t,i;
   cin>> t;
   while(t>0){
        cin>> x;
        if(x>100){
            cout<<x-10<<endl;
        }else{
            cout<<x<<endl;
        }
        t--;
   }
   return 0;
}