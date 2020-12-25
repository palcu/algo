#include <iostream.h>
#include <math.h>
int main() {
int a=2,b,v=0,i,j,sb;
while (v!=3) {
	b=0; sb=0;
	for (i=1;i<=a/2;i++)
			if (a%i==0) b+=i;

			if (b>a) {
	for (j=1;j<=b/2;j++)
			if (b%j==0) sb+=j;

	if (a==sb) {
		cout<<a<<" "<<b<<endl;
		v++; } }
	a++;
}
}