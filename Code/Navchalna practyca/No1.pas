program No1;

const
  n = 10;

type
  mas = array[1..n, 1..n]of integer;

var
  i, j: integer;
  q: mas;

begin
  for i := 1 to n do
    for j := 1 to n do
    begin
      if (j >= i) then
        q[i, j] := j - i + 1
      
    end;
  for i := 1 to n do
    for j := 1 to n do
      if (j < i) then
        q[i, j] := j - i + n + 1;
  for i := 1 to n do
  begin
    writeln;
    for j := 1 to n do
      write(q[i, j]:3);
  end;
end.