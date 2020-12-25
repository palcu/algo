#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	freopen("sport1.in","r",stdin);
	freopen("sport1.out","w",stdout);
	unsigned a,b,c,n,i,aux;
	float s=0;
	
	scanf("%u%u%u",&a,&b,&n);
	s=a+b;
	 for (i=2;i<n;++i)
   {
      if ( (a==b) && (a==4) || (a==b) && (a==3) ) 
      {
         a=b;
         b=3;
         s+=b;
      }
       else if ( (a==b) && (a==5) )
      {
         a=b;
         b=2;
         s+=b;
      }
      else if (a!=b)
      {
         aux=a>b?a:b;
         s+=aux;
         a=b;
         b=aux;
      }
   }
	cout<<s/n;
	
	
	return 0;
}
