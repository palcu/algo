#include <iostream>
using namespace std;
int main() {
    int i,n,x,e=0,p=1;
    cin>>n>>x;
    for (i=1;i<=n;i++) {
        p*=(i+1)*(i+2);
        e+=(-1)^i*x^(2*i+1)/p;
        }
    cout<<e<<endl;
}
