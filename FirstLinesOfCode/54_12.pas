program p54e12;
uses crt;
var n,c,r,z:integer;
begin
clrscr;
{Sa se transforme un numar din baza 10 in baza 2}
write ('n='); readln (n);
while n<2 do
begin
r:=n mod 2;
z:=z*10+r;
n:=n div 2;
end;
writeln ('Numarul este ',z,' in baza 2.');
end.
