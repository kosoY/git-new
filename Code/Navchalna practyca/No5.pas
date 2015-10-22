program p2;

var
  i, j, k, l, f, g: integer;

begin
  writeln('Vvedit rik:');
  read(k);
  l := k - 2000;
  f := l;
  g := l div 4;
  f := f + g;
  while f >= 7 do
    f := f - 7;
  j := 8 - f;
  writeln('Den vchutelya vypade na  ', j, '   chyslo zovtnya');
end.