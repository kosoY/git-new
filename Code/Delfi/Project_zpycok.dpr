program Project_zpycok;
{$APPTYPE CONSOLE}
uses
  SysUtils;

type list=^lanka;
lanka=record
x:integer;
next:list;
end;
var  h:text;  m,s:list; 
function Find_element_1(var p:list; vvv:integer):boolean;
var temp:list;
begin
  temp:=p;
  while (temp^.next<>nil) and (temp^.next^.x<>vvv) do
  temp:=temp^.next;
  if temp^.next=nil then
      Find_element_1:=false
  else
    begin
      p:=temp^.next;
      Find_element_1:=true;
    end;
end;
procedure Create_list_1(var p:list;var h:text);
var temp:list;
begin
    assign(h,'1.txt');
    reset(h);
    new(p);
    new(temp);
    temp:=p;
    temp^.next:=nil;
  while not eof(h) do
    begin
      new(temp^.next);
      temp:=temp^.next;
      readln(h,temp^.x);
      temp^.next:=nil;
    end;
  close(h);
end;
procedure Print_list_1( var p:list);
  var temp:list;
begin
  temp:=p^.next;
  write(']');
  while temp<>nil do
    begin
      write('>>',temp^.x);
      temp:=temp^.next;
    end;
  writeln('.');
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
procedure Insert_element_1(var p:list; vvv:integer);
var temp:list;
begin
  new(temp);
  temp^.x:=vvv;
  temp^.next:=p^.next;
  p^.next:=temp;
end;

begin
Create_list_1(s,h);
new(m);
m:=s;
  while Find_element_1(s,2) do
  begin
  Writeln(s^.x);
  Insert_element_1(s,33);
  end;
  Print_list_1(m);
  Delete_list_1(m);
  dispose(m);
  Readln;
  readln;
end.
