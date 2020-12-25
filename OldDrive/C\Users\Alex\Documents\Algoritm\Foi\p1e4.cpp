#include <iostream>
using namespace std;
int main(void) {
    int n1,n2,n,m,d,h;
    cin>>n1>>n2;
    n=n2-n1;
    m=n*12;
    d=n*365;
    h=d*24;
    cout<<n<<" ani"<<'\n';
    cout<<m<<" luni"<<'\n';
    cout<<d<<" zile"<<'\n';
    cout<<h<<" ore";
    return 0;
}
