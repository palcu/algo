#include <stdio.h> 
int main() 
{ 
	freopen ("cartele.in","r",stdin);
	freopen ("cartele.out","w",stdout);
	
    int sablon[51][51], v[51][51]; 
    int n,c,i,j,cartela,ok,i2,j2; 
    scanf("%d%d",&n,&c); 
    for (i=1; i<=n; i++) 
        for (j=1; j<=n; ++j) 
            scanf("%d",&sablon[i][j]); 
    for (cartela=1; cartela<=c; ++cartela) 
    { 
        ok=1; 
        for (i=1; i<=n; i++) 
            for (j=1; j<=n; j++) 
            { 
                scanf("%d",&v[i][j]); 
                if (sablon[i][j]!=v[j][i]) 
                    ok=0; 
            } 
        //cartela invers 
        if (!ok) 
        for (i=1, i2=n, ok=1; i<=n; i++, --i2) 
            for (j=1, j2=n; j<=n; ++j, --j2) 
                if (sablon[i][j]!=v[i2][j2]) 
                { 
                    ok=0; 
                    break; 
                } 
        //cartela de-a latu' 
        if (!ok) 
        for (j=1, j2=n, ok=1; j<=n; ++j, --j2) 
            for (i=1, i2=n; i<=n; ++i, --i2) 
                if (sablon[i][j]!=v[i2][j2]) 
                { 
                    ok=0; 
                    break; 
                } 
        //cartela de-a latu' invers 
        if (!ok) 
        for (j=1, j2=n, ok=1; j<=n; ++j, --j2) 
            for (i=1, i2=1; i<=n; i++, i2--) 
                if (sablon[i][j]!=v[i2][j2]) 
                { 
                    ok=0; 
                    break; 
                } 
        if (ok) 
            printf("1\n"); 
        else 
            printf("0\n"); 
    } 

    return 0; 
}
