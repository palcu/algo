#include <stdio.h> 
using namespace std;
int main() 
{ 
int b,f,i,s; 
freopen("film.in","r",stdin); 
freopen("film.out","w",stdout); 
scanf ("%d%d",&f,&b); 

if (b==f)
{
	for (i=1;i<=f;i++)
		printf ("bf");
}

else
{
if (b>f) 
{ 
	s=b-f;
    for (i=1;i<=s;i++) 
        printf ("bfb"); 
	for (i=1;i<=f-s;i++)
		printf ("fb"); 
} 

else 
{ 
	s=f-b;
    for (i=1;i<=s;i++) 
        printf ("fbf"); 
	for (i=1;i<=b-s;i++)
		printf ("bf"); 
} 
}

printf("\n");
return 0; 
}
