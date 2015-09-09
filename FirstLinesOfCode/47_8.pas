program p47e8;
uses crt;
var a:integer;
begin
clrscr;
{Sa se scrie un program care sa citeasca un numar intreg, iar daca acest numar este
1 sa se afiseze luni, daca este 2 sa afiseze marti, ... 7 - duminica, iar daca nu este cuprins
intre 1 - 7 sa afiseze cuvantul eroare}
write ('a='); readln (a);
if a=1 then
writeln ('luni')
else
if a=2 then
writeln ('marti')
else
if a=3 then
writeln ('miercuri')
else
if a=4 then
writeln ('joi')
else
if a=5 then
writeln ('vineri')
else
if a=6 then
writeln ('sambata')
else
if a=7 then
writeln ('duminica')
else
writeln ('eroare')
end.