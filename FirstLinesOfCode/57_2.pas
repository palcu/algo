program p57e2;
uses crt;
var p:real;
    n,i:integer;
begin
clrscr;
{Sa se calculeze valoarea : p= (1-(1/2*2)(1-1/3*3...n}
write ('n='); readln (n);
p:=1;
for i:=2 to n do
p:=p*(1-1/i*i);
writeln ('Produsul este = ',p);
end.