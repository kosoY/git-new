program p2;

var
  t: string;
  i, j: integer;

begin
  writeln('Vvedit stroky');
  read(t);
  
  for i := 1 to length(t) do
  begin
    if t[i] = ',' then
      t[i] := '.';
  end;
  for i := 1 to length(t) do 
    for j := 1 to length(t) - 1  do
      if (t[j] = '.') and (t[j + 1] = '.') then
      begin
        delete(t, j, 1);
        break; 
      end;
  if t[length(t)] = '.' then delete(t, length(t), 1);
  writeln(t);
end.