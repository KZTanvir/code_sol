#include <iostream>
using namespace std;
int main(void) {
   int x,y,t;
   cin>> t;
   while(t>0){
        cin>> x >> y;
        if(y>=((int)x/2)){
            cout<< "YES" << endl;
        }
        else{
            cout<< "NO" << endl;
        }
        t--;
   }
   return 0;
}