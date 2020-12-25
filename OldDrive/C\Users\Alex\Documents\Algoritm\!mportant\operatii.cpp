#include<stdio.h>
#include<string>

#define LG_MAX 500 + 1
typedef int BigNumber[LG_MAX];

void citire(BigNumber x);
void afisare(BigNumber x);
void suma(BigNumber a,BigNumber b,BigNumber s);
void diferenta(BigNumber a,BigNumber b,BigNumber d);
void produs(BigNumber a,BigNumber b,BigNumber p);
int compara(BigNumber a,BigNumber b);
void p10(BigNumber x,int nr);
void div(BigNumber a,BigNumber b,BigNumber c,BigNumber r);

int main()
{
    freopen("operatii.in","r",stdin);
    freopen("operatii.out","w",stdout);
   
    BigNumber nr1,nr2,s,r;
   
    citire(nr1);  //citim primul numar
    citire(nr2);  //citim al doilea numar
    
    
    div(nr1,nr2,s,r); //calculam produsul celor 2 numere in s
    afisare(s);  //afisam
   
    
    fclose(stdin); fclose(stdout);
    return 0;
}

/*return
    -1 a < b
     0 a == b
     1 a > b
*/
int compara(BigNumber a,BigNumber b)
{
   int i;
   
   if(a[0] < b[0]) return -1;
   if(a[0] > b[0]) return  1;
    for(i = a[0]; i >= 1 && a[i] == b[i]; i--)
      ;
     
    if(i < 1) return 0;
    if(a[i] < b[i]) return -1;
    return 1;
}

// c = a/b; nr = a%b;
void div(BigNumber a,BigNumber b,BigNumber c,BigNumber r)
{
     int i;
     r[0] = 0; c[0] = a[0];
     for(i = a[0]; i >= 1; i--)
     {
        p10(r,1); r[1] = a[i];
        c[i] = 0;
       
        while(compara(b,r) != 1)
        { 
           c[i]++;
           diferenta(r,b,r);    
        }
     } 
     while(!c[c[0]] && c[0] > 1) c[0]--;
     while(!r[r[0]] && r[0] > 1) r[0]--;
}

// x = 10^nr
void p10(BigNumber x,int nr)
{
     int i;
     for(i = x[0]; i >= 1; i--) x[i+nr] = x[i];
     for(i = 1; i <= nr; i++) x[i] = 0;
     x[0] += nr;
}

//p = a*b;
void produs(BigNumber a,BigNumber b,BigNumber p)
{
   int i,j,t,cifra;
   for(i = 0; i < LG_MAX; i++) p[i] = 0;     
   
   for(i = 1; i <= b[0]; i++)
   {
     for(t = 0,j = 1; j <= a[0]; j++)
     {
        cifra = p[i+j-1] + a[j] * b[i] + t;  //produs partial
        p[i+j-1] = cifra % 10;
        t = cifra/10;                       //cifra transport
     }
     if(t) p[i+j-1] = t;  
   }
   p[0] = a[0] + b[0];
   if(p[p[0]+1]) p[0]++;
}

//d = a-b( a > b )
void diferenta(BigNumber a,BigNumber b,BigNumber d)
{   
     int i,t = 0;
     if(a[0] < b[0])
     { 
         diferenta(b,a,d);
     }
     else
     {
       for(i = 1; i <= a[0]; i++)
       {         
           d[i] = a[i]-b[i]+t;                //diferenta
           if(d[i] < 0) d[i]+= 10,t = -1;  //calculam cifra de transport
           else t = 0; 
        }
        i--;
        while(i >= 1 && !d[i]) i--;
        d[0] = i;
     }
} 

//s = a+b;
void suma(BigNumber a,BigNumber b,BigNumber s)
{   
    int i,cifra,t = 0,max;
   
    //completam numarul cel mai mic cu zeroouri nesemnificative
    if(a[0] < b[0]) { max = b[0]; for(i = a[0]+1; i <= b[0]; i++) a[i] = 0; }
    else            { max = a[0]; for(i = b[0]+1; i <= a[0]; i++) b[i] = 0; }
   
    for(i = 1; i <= max; i++)
    {
      cifra = a[i] + b[i] + t; //calculam noua cifra
      s[i] = cifra % 10;     
      t = cifra/10;            //calculam cifra de transport
    }
    if(t) s[i] = t; else i--;
    s[0] = i;
}

void citire(BigNumber x)
{
     int i;
     char s[LG_MAX];
     scanf("%s",s);                                     //citim sirul de cifre
     x[0] = strlen(s);                                  //calculam lungimea numarului
     
     for(i = x[0]-1; i >= 0; i--) x[x[0]-i] = s[i]-'0';       //inversam numarul
     for(i = x[0]+1; i < LG_MAX; i++) x[i] = 0;
}

void afisare(BigNumber x)
{
     for(int i = x[0]; i >= 1; i--)
        printf("%d",x[i]);
     
}
