program Project_Practychna_9;


type
  list = ^lanka;
  lanka = record
    x: integer;
    y: integer;
    next: list;
  end;

var
  h: text;
  m, s, f, g, temp: list;
  i, w: integer;

procedure Create_list_1(var p: list);
var
  temp: list;
  x: integer;
begin
  assign(h, 'dev.txt');
  reset(h);
  new(p);
  new(temp);
  temp := p;
  temp^.next := nil;
  
  while not eof(h) do
  
  begin
    x := 0;
    read(h, x);
    if x = 0 then begin readln(h, x);continue; end;
    temp^.x := x;
    x := 0;
    readln(h, x);
    temp^.y := x;
    new(temp^.next);
    temp := temp^.next;
    temp^.next := nil;
  end;
  close(h);
end;

procedure Create_list_2(var p: list);
var
  temp: list;
  x, y: integer;
begin
  assign(h, 'dev.txt');
  reset(h);
  new(p);
  new(temp);
  temp := p;
  temp^.next := nil;
  
  while not eof(h) do
  begin
    
    read(h, x);
    
    
    readln(h, y);
    if (x = 0)  then begin continue; end;
    temp^.x := x * y;
    temp^.y := y - 1;
    new(temp^.next);
    temp := temp^.next;
    temp^.next := nil;
  end;
  close(h);
end;


procedure Print_list(var p: list);
var
  temp: list;
begin
  temp := p;
  while temp^.next <> nil do
  begin
    write(temp^.x, 'x^', temp^.y);
    writeln;
    temp := temp^.next;
  end;
  writeln('.');
end;




procedure Delete_list(var p: list);
var
  temp: list;
begin
  temp := p;
  while p <> nil do
  begin
    p := temp^.next;
    dispose(temp);
    temp := p;
  end;
end;

function Calc(p: list; a: integer): integer;
var
  i, cal, sum: integer; s: integer;
begin
  s := 1;
  while p <> nil do
  begin
    for i := 1 to p^.y do
      s := s * a; 
    cal := p^.x * s;
    sum := sum + cal;
    p := p^.next;
  end;
  calc := sum;
  
end;

begin
  writeln('Vvedit znachenya x');
  read(w);
  Create_list_1(m); 
  Create_list_2(s);
  f := m;
  g := s;
  write('Znachenya polinomy: ');
  writeln( Calc(f, w));
  write('Znachenya pohidnoi: ');
  writeln( Calc(g, w));
  
  Print_list(f);
  Print_list(g);
  Delete_list(f);
  Delete_list(g);
end.