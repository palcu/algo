#include <iostream.h>
void main()
{
int n,n2,n3,c0=0,nr=0;
cin>>n; n2=n;

while (n2!=0)
{
	nr++;
	n2/=10;
}

n3=n;

while (n3%10==0)
{
	c0++;
	n3/=10;
}

while (n!=0)
{
	n2=n2*10+n%10;
	n/=10;
}

if (nr==4)
{
	switch(n2%10)
	{
		case 1: cout<<"M"; break;
		case 2: cout<<"MM"; break;
		case 3: cout<<"MMM"; break;
		case 4: cout<<"MMMM"; break;
		case 5: cout<<"MMMMM"; break;
	}
	n2/=10;
}

if ((nr>=3)&&(c0<3))
{
	switch(n2%10)
	{
		case 0: break;
		case 1: cout<<"C"; break;
		case 2: cout<<"CC"; break;
		case 3: cout<<"CCC"; break;
		case 4: cout<<"CD"; break;
		case 5: cout<<"D"; break;
		case 6: cout<<"DC"; break;
		case 7: cout<<"DCC"; break;
		case 8: cout<<"DCCC"; break;
		case 9: cout<<"CM"; break;
	}
	n2/=10;
}

if ((nr>=2)&&(c0<2))
{
	switch(n2%10)
	{
		case 0: break;
		case 1: cout<<"X"; break;
		case 2: cout<<"XX"; break;
		case 3: cout<<"XXX"; break;
		case 4: cout<<"XL"; break;
		case 5: cout<<"L"; break;
		case 6: cout<<"LX"; break;
		case 7: cout<<"LXX"; break;
		case 8: cout<<"LXXX"; break;
		case 9: cout<<"XC"; break;
	}
	n2/=10;
}

if ((nr>=1)&&(c0<1))
{
	switch(n2%10)
	{
		case 0: break;
		case 1: cout<<"I"; break;
		case 2: cout<<"II"; break;
		case 3: cout<<"III"; break;
		case 4: cout<<"IV"; break;
		case 5: cout<<"V"; break;
		case 6: cout<<"VI"; break;
		case 7: cout<<"VII"; break;
		case 8: cout<<"VIII"; break;
		case 9: cout<<"IX"; break;
	}
}
cout<<endl;
}