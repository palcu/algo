program p54e10;
uses crt;
var n,c,r,x:integer;
begin
clrscr;
{Sa se verifice daca un numar intreg este prim sau nu.}
write ('Introduceti numarul '); readln (n);
x:=2;
while (n div x) < x do
begin
if (n mod x)=0 then
writeln ('Numarul nu este prim');
x:=x+1;
end;
if r<>0 then writeln ('Numarul este prim');
end.
