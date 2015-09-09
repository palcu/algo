program p47e10;
uses crt;
var venit,chelt:integer;
const profit_minim=50;
begin
clrscr;
{Venitul unei societati comerciale este de venit milioane lei, iar cheltuielile sunt de
chelt lei. Sa se precizeze daca profitul societatii este mai mare sau nu decat o
valoare constanta profit_minim = 50 (milioane lei).}
write ('Venit = '); readln (venit);
write ('Cheltuieli = '); readln (chelt);
if venit-chelt>profit_minim then
writeln ('Profitul este mai mare')
else
writeln ('Profitul este mai mic sau egal')
end.