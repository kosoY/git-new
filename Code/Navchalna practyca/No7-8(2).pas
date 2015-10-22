program gdsg;

var
  t: text;
  sum, kil, x: integer;

begin
  assign(t, 'sim2.txt');
  reset(t);
  kil := 0;
  sum := 0;
  while not eof(t) do
  begin
    read(t, x);
    sum := sum + x;
    inc(kil);
  end;
  write('Suma elementiv= ');
  writeln(sum);
  write('Kilkist elementiv= ');
  writeln(kil);
end.