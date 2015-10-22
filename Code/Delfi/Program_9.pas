program Project_Practychna_9;


type
list=^lanka;
lanka=record
x:integer;
y:integer;
next:list;
end;

var
h:text;

m,s:list;

i:integer;
procedure Create_list_1(var p:list; h:text);
var temp:list;   x:integer;
begin
    assign(h,'1.txt');
    reset(h);
    new(p);
    new(temp);
    temp:=p;
    temp^.next:=nil;

    while not eof(h) do
    begin
      x:=0;
      read(h,x);
      temp^.x:=x;
      x:=0;
      readln(h,x);
      temp^.y:=x;
      new(temp^.next);
      temp:=temp^.next;
      temp^.next:=nil;
    end;
     close(h);
      end;
procedure Create_list_2(var p:list; h:text);
var temp:list;   y,x:integer;
begin
    assign(h,'1.txt');
    reset(h);
    new(p);
    new(temp);
    temp:=p;
    temp^.next:=nil;
    while not eof(h) do
    begin
      x:=0;
      read(h,x);
      y:=0;
      readln(h,y);
      temp^.x:=x*y;
      temp^.y:=y-1;
      new(temp^.next);
      temp:=temp^.next;
      temp^.next:=nil;
    end;
    close(h);
end;

procedure Print_list_1( var p:list);
  var temp:list;
begin
  temp:=p;
  while temp^.next<>nil do
    begin
      write(temp^.x,'x^',temp^.y);
      writeln;
      temp:=temp^.next;
    end;
  writeln('.');
end;
function Calc(var p:list):integer;
var temp:list;   i, x,f,g,h:integer;
begin
temp:=p;
f:=1;
writeln('vedit x');
read(x);
h:=0;
while  temp^.next<>nil do
begin
for i:=1 to (temp^.y) do
begin
f:=x*f;
end;
g:=(temp^.x)*f;
h:=h+g;
f:=1;
g:=0;
temp:=temp^.next;
end;
calc:=h;
end;

procedure Delete_list_1(var p:list);
var temp:list;
begin
  temp:=p;
  while p<>nil do
  begin
    p:=temp^.next;
    dispose(temp);
    temp:=p;
  end;
end;

begin
Create_list_1(s,h);
Create_list_2(m,h);
writeln('Znachenya polinoma');
writeln(Calc(s));
writeln('Znachenya pohidnoi');
writeln(Calc(m));
//Print_list_1(s);
//Print_list_1(m);
Delete_list_1(s);
Delete_list_1(m);
end.