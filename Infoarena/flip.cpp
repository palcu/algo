#include <fstream>
#include <iostream>
using namespace std;
long a[17][17],mymax=-2147483647,sum=0;
int v[17];
int m,n;
void flip(int k)
{
   int i;
   for(i=1;i<=n;i++)
    a[k][i]=0-a[k][i];
}
int main()
{
  ifstream f("flip.in");
  ofstream g("flip.out");
  int i,j,k=1,ok;
  long s;
  f>>m>>n;
  for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
    f>>a[i][j];
  f.close();
  v[k]=-1;
  while(k>0)
  {
     ok=0;
     while(v[k]<1&&!ok)
     {
    v[k]++;
       if(v[k]) flip(k);
    ok=1;
     }
     if(ok)
      if(m==k)
      {  sum=0;
     for(i=1;i<=n;i++)
     {
       s=0;
       for(j=1;j<=m;j++)
        s+=a[j][i];
       if(s<0) sum=sum-s;
       else sum+=s;
     }
     if(sum>mymax) mymax=sum;
      }
      else
       v[++k]=-1;
     else
     {
       k--;
       if(v[k]) flip(k);
     }
  }
  g<<mymax;
  g.close();
  return 0;
}
