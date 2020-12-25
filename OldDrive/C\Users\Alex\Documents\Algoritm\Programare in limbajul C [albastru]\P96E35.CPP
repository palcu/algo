#include <iostream.h>
#include <math.h>
//using namespace std;
int main() {
    int a=1,b=2,sa=0,sb=0,i,j,v=0;
    while (v!=3){
          if (a<b) {
    sa=0; sb=0;
    for (i=1;i<=a/2;i++) 
        if (a%i==0) sa+=i;
    for (j=1;j<=b/2;j++)
        if (b%j==0) sb+=j;
    if ((a==sb)&&(b==sa)) {
                          cout<<a<<" "<<b<<endl;;
                          v++;
                          }    
           a++;}
           else {b++; a=1;}
           }    
    return 0;
}
