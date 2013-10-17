#include <stdio.h>
#include <fstream>
#include <cstring>
using namespace std;

#define in "aib.in"
#define out "aib.out"
#define dim 100001

inline int Minim(int a, int b) {
       if ( a < b ) return a;
       return b;
}

int N, M, T;
int Arb[dim];
int C, S;

void Update(int,int);
int Query(int);
int Search(int);

int main()
{
    memset(Arb,0,sizeof(Arb));
    int K, X, Y;

    freopen(in,"r",stdin);
    freopen(out,"w",stdout);

    scanf("%d%d", &N, &M);
    for ( int i = 1; i <= N; i++ )
    {
        scanf("%d", &T);
        Update(i,T);
    }

    for ( ; M; M-- )
    {
        scanf("%d", &K);

        if ( K < 2 )
        {
             scanf("%d%d", &X, &Y);
             if ( !K ) Update(X,Y);
             else      printf("%d\n", Query(Y)-Query(X-1));
        }
        else
        {
            scanf("%d", &X);

            printf("%d\n", Search(X));
        }
    }
}

int Search(int val)
{
    int i, step;

    for ( step = 1; step < N; step <<= 1 );

    for( i = 0; step; step >>= 1 )
    {
         if( i + step <= N)
         {
            if( val >= Arb[i+step] )
            {
                i += step, val -= Arb[i];
                if ( !val ) return i;
            }
         }
    }

    return -1;
}

void Update(int poz, int val)
{
     C = 0;
     while ( poz <= N )
     {
           Arb[poz] += val;
           while ( !(poz & (1<<C)) ) C++;
           poz += (1<<C);
           C += 1;
     }
}

int Query(int poz)
{
    C = 0, S = 0;
    while ( poz > 0 )
    {
          S += Arb[poz];
          while ( !(poz & (1<<C)) ) C++;
          poz -= (1<<C);
          C += 1;
    }

    return S;
}
