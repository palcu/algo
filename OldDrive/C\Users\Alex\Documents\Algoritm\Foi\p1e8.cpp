#include <iostream>
using namespace std;
int main() {
    unsigned int nr, nc, no, nh, m;
    cin>>nr>>nc>>no>>nh;
    m=nr*(nc*12+nh+no*16);
    cout<<m;
}
