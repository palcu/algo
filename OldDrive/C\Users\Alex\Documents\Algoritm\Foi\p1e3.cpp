#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int a,b;
    float ma,mg,sp,sc;
    cin>>a>>b;
    ma=(float)(a+b)/2;
    mg=sqrt(a*b);
    sp=a*a+b*b;
    sc=a*a*a+b*b*b;
    cout<<"ma="<<ma<<endl;
    cout<<"mg="<<mg<<endl;
    cout<<"sp="<<sp<<endl;
    cout<<"sc="<<sc<<endl;
    return 0;
}
