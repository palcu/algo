#include <iostream.h>
void main()
{
float a,b;
cin>>a; cin>>b;
while (b!=0)
{
if ((-b/a>=-1)&&(-b/a<=1)) cout<<"             "<<a<<" "<<b<<endl;
a=b;
cin>>b;
}
}