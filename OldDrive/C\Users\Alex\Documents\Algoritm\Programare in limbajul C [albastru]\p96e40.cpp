#include <iostream>
using namespace std;
int main() {
    int n,x,i,exista,nr;
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x; nr=0;
        while (x!=0) {
              if (x%10==0) nr++;
              x/=10;
        }
        if (nr==3) exista=1;
    }
    if (exista) cout<<"exista";
    else cout<<"nu exista";
}
