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
procedure Create_list_1(var p:list);
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
      read(h,x);
      temp^.y:=x;
      new(temp^.next);
      temp:=temp^.next;
      temp^.next:=nil;
    end;
     close(h);
      end;
procedure Create_list_2(var p:list);
var temp:list;   y,x:integer;
begin
     assign(h,'New Text Document.txt');
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

      read(h,y);
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
procedure Calc(var p:list);
var temp:list;    x,f,g,h:integer;
begin
temp:=p;
f:=0;
writeln('vedit x');
read(x);
h:=0;
while  temp^.next<>nil do
begin
for i:=1 to temp^.y do
f:=x*f;
writeln(f);
g:=(temp^.x)*f;
writeln(g);
h:=h+g;
writeln(h);
f:=0;
g:=0;
temp:=temp^.next;
end;
writeln(h)
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
Create_list_1(s);
//Create_list_2(m,h);
Calc(s);
Print_list_1(s);
Print_list_1(m);
Delete_list_1(s);
Delete_list_1(m);
end.

