#include <iostream>
using namespace std;
int main() {
    int i,n,x,e=0,p=2;
    cin>>n>>x;
    for (i=1;i<=n;i++) {
        p*=(i+1)*(i+2);
        e+=(-1)^i*x^(2*i)/p;
        }
    cout<<e<<endl;
}
