int cifra(int n)
{
   int s;
   s=n%9;
   s=(!s)?(!n)?0:9:s;
   return s;
}