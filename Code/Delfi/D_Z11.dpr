program D_Z11;
{$APPTYPE CONSOLE}
uses
  SysUtils;
type
list=^lanka;
lanka=record
  x:Integer;
  y:integer;

next:list;
end;
var
h:text;
m,s:list;
procedure Create_list_1(var p:list);
var temp:list;  x:Integer;
begin
    assign(h,'1.txt');
    reset(h);
    new(p);
    new(temp);
    temp:=p;
    temp^.next:=nil;
     read(h,x);
     write(x);
      read(h,x);
     write(x);
      read(h,x);
     write(x);
   {  while not eof(h) do
     begin
        new(temp^.next);
        temp^.next:=nil;

        //read(h,temp^.y);
     end;   }
     close(h);
      end;




procedure Delete_list(var p:list);
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
procedure Delete_element(var p:list);
var temp:list;
begin
    New(temp);
    temp:=p^.next;
    p^.next:=p^.next^.next;
    Dispose(temp);
end;

begin
Create_list_1(s);
new(m);
m:=s;
Delete_list(s);
dispose(m);
Readln;
readln;
end.
