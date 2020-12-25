#include <iostream>
using namespace std;
int main(){
    int x,c,g,r;
    cin>>x;
    r=x%5;
    if (r==0) cout<<x/5<<" c 0 g";
    else
    if (r==1) cout<<x/5+2<<" c 3 g";
    else
    if (r==2) cout<<x/5+1<<" c 1 g";
    else
    if (r==3) cout<<x/5+3<<" c 4 g";
    else
    if (r==4) cout<<x/5+2<<" c 2 g";              
    return 0;
}
