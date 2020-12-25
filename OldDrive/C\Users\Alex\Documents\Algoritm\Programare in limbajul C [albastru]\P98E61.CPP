#include <iostream.h>
void main()
{
int s,x,nr,p,i,s2,j;
cin>>s>>x;
p=1;
while (p*x<=s) p=p*x;
while (s!=0)
    {
    nr= s/p;
    if (nr!=0)
	   cout<<nr<<" bancnote cu valoarea de "<<p<<endl;
     s=s%p;
    p=p/x;
     }

/*
if (s==x) cout<<"1 bancnota cu valoare de "<<x<<endl;
else
{
while (s!=0)
{
	p=1; i=0; s2=0; j=0;
	while (p<s)
	{
		i++;
		p*=x;
	}
	if (p!=1) p/=x;

	while (s2<=s)
	{
		j++;
		s2+=p;
	}
	j--;
	s2-=p;
	s-=s2;
	cout<<j<<" bancnote cu valoarea de "<<p<<endl;
}
cout<<endl;
}
*/
}