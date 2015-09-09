program p52e1;
uses crt;
var n,f,i:integer;
begin
clrscr;
{Sa se calculeze factorialul unui numar intreg n.}
write ('n='); readln (n);
f:=1; i:=1;
while i<=n do
begin
f:=f*i; i:=i+1;
end;
writeln ('Factorial = ',f);
end.