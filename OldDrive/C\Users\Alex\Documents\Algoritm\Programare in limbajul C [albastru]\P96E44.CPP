#include <iostream.h>
#include <math.h>
void main() {
int n,rad,i;
cin>>n;
rad=int(sqrt(n));
if (rad==sqrt(n)) rad--;
for (i=1;i<=rad;i++) cout<<i*i<<endl;
}