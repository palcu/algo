program p54e11;
uses crt;
var n,r,s:longint;
begin
clrscr;
{Sa se inverseze un numar (care nu se termina in 0). De exemplu 10758 => 85701}
write ('n='); readln (n);
s:=0; r:=0;
while (n div 1) <> 0 do
begin
r:=n mod 10;
s:=s*10+r;
n:=n div 10;
end;
writeln ('Nr este ',s);
end.
