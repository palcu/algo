#include <iostream>
using namespace std;
int main(){
    int n,s=0,p=1,x,i;
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>x;
        if (x%2==0) s+=x;
        if (x!=0) p*=x;
        }
    cout<<"suma "<<s<<endl;
    cout<<"produs "<<p<<endl;
}
