#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n,x,i,j,prim,x2,x3,pal,radx,exista=0;
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        x2=x; pal=0;
        while (x2!=0) {
              pal=pal*10+x2%10;
              x2/=10;
              }
        if (pal==x) {
              radx=sqrt(x); prim=1;
              for (j=2;j<=radx;j++) {
                  if (x%j==0) {
                              prim=0;
                              break;
                              }
              }
              if (prim==1) exista=1;
        }
    }
    if (exista) cout<<"exista";
    else cout<<"nu exista";
}                
