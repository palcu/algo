#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int x,max,min,x2,x3,i,j,rx2,rx3,af2=1,af3=1;
    cin>>x;
    x2=x; x3=x;
    
    for (x2;x2>0;x2--) {
        rx2=sqrt(x2); af2=1;
        for (i=2;i<=rx2;i++) {
            if (x2%i==0) { 
                          af2=0;
                          break; 
            }
   
        }
        if (af2==1) break;
    }
    
    for (x3;;x3++) {
        rx3=sqrt(x3); af3=1;
        for (j=2;j<=rx3;j++) {
            if (x3%j==0) { 
                          af3=0;
                          break; 
            }
   
        }
        if (af3==1) break;
    }
    
    
    cout<<x2<<" "<<x3<<endl;
    return 0;
}
            
                   
