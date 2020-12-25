#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int d,a,b;
    float x;
    cin>>a>>b>>d;
    x=(float)(d*1000)/(((a*7)+b)*24*60*60);
    cout<<x;
}
