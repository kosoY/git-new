program Project2;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type list=^lanka;
lanka=record
x:integer;
next:list;
end;
var  h:text;  s:list;
{function Perevirka_list_1(p:list):boolean;
begin
  if p=nil then
  Perevirka_list_1:=true
  else
  Perevirka_list_1:=false; 
end; }
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
procedure Create_list_1(var p:list;var h:text);
var temp:list;   
begin
    assign(h,'1.txt');
    reset(h);
    new(p);
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
function Find_element_1(var p:list; vvv:integer):boolean;
{ p-������� ������. vvv-������ ��������}
var temp:list;
begin
  //if Perevirka_list_1(s)=false then
  if (p=nil) or (p^.next=nil) then
  begin
    Find_element_1:=false;
    Exit;
  end;
  temp:=p;
  while (temp^.next<>nil) and (temp^.next^.x<>vvv) do
  temp:=temp^.next;
  if temp^.next=nil then
  Find_element_1:=false
  else
  begin
    p:=temp;
    Find_element_1:=true;
  end;
end;
procedure Insert_element_1(var p:list; vvv:integer);
var temp:list;
begin
  //if Perevirka_list_1(s)=false then
  new(temp);
  temp^.x:=vvv;
  temp^.next:=p^.next;
  p^.next:=temp;
end; 
  
begin
Create_list_1(s,h);
Find_element_1(s,2); 
Insert_element_1(s,33);
Print_list_1(s);
Delete_list_1(s); 
end.    