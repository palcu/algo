program p52e7;
uses crt;
var n,x,a,m,i:integer;
begin
clrscr;
{De la tastatura se introduce un sir de numere intregi. Se cere sa se afiseze
valoarea maxima depistata din lista. Dimensiunea listei este precizata inainte
de a fi introduse elementele ce o compun.}
write ('Numarul de termeni = '); readln (x);
m:=0; i:=1;
while i<=x do
begin
write ('Introduceti numarul '); readln (n);
if n>m then
m:=n;
i:=i+1;
end;
writeln ('Numarul cel mai mare este ',n);
end.