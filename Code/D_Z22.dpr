program D_Z22;
{$APPTYPE CONSOLE}
uses
  SysUtils;

type
list=^lanka;
lanka=record
x:char;
y:char;
q:char;
next:list;
end;
list1=^lanka1;
lanka1=record
x:integer;
y:integer;
q:char;
next1:list1;
end;
var
h:text;
d:list1;
m,s:list;
f:string;
i:integer;
procedure Create_list_1(var p:list;var h:text);
var temp:list;
begin
    assign(h,'1.txt');
    reset(h);
    read(h,f);
    write(f);
    new(p);
    new(temp);
    temp:=p;
    temp^.next:=nil;
    i:=1;
     while f[i]<>'.' do
     begin
        new(temp^.next);
        temp:=temp^.next;
        temp^.next:=nil;
        temp^.q:= f[i] ;
        i:=i+1 ;
        temp^.x:= f[i] ;
        i:=i+1 ;
        i:=i+1 ;
        i:=i+1 ;
        temp^.y:= f[i] ;
        i:=i+1 ;
     end;
     close(h);
      end;
procedure Create_list_2(var p:list1;var h:text; var l:list);
var temp:list1;
begin
    new(p);
    new(temp);
    temp:=p;
    temp^.next1:=nil;
     while l^.next<>nil do
     begin
          l:=l^.next;
        new(temp^.next1);
        temp:=temp^.next1;
        temp^.next1:=nil;
        temp^.q:=l^.q;
        temp^.x:=(ord(l^.y)-48)*(ord(l^.x)-48) ;
        temp^.y:=Ord(l^.y)-48-1;
     end;
      end;
procedure Znach(var p:list);
  var temp:list; var h,dob,dod, x:Integer;
begin
h:=1;
temp:=p^.next;
writeln('vedit x');
read(x);
begin
  dod:=0;
  dob:=1;
  while temp<>nil do
  begin
  h:=1;
    for i:=1 to Ord(temp^.y)-48 do
      begin
        h:=x*h;
      end;
      dob:= h*(Ord(temp^.x)-48);

    if temp^.q='-' then
      dod:=(-dob)+dod;
    if temp^.q='+' then
      begin
        dod:=dob+dod;
      end;
  temp:=temp^.next;
  end;
writeln(dod);
end;
end;
procedure Znach1(var p:list1);
  var temp:list1; var h,dob,dod, x:Integer;
begin
h:=1;
temp:=p^.next1;
writeln('vedit x');
read(x);
begin
  dod:=0;
  dob:=1;
  while temp<>nil do
  begin
  h:=1;
  for i:=1 to temp^.y do
   begin
     h:=x*h;
   end;
  dob:= h*temp^.x;
  if temp^.q='-' then
    dod:=(-dob)+dod;
  if temp^.q='+' then
  begin
    dod:=dob+dod;
  end;
  temp:=temp^.next1;
  end;
writeln(dod);
end;
end;

procedure Print_list_1( var p:list);
  var temp:list;
begin
  temp:=p^.next;
  while temp<>nil do
    begin
      write(temp^.q, temp^.x,'x^',temp^.y);
      temp:=temp^.next;
    end;
  writeln('.');
end;
procedure Print_list_2( var p:list);
  var temp:list;
begin
  temp:=p^.next;
  while temp<>nil do
    begin
      write(temp^.q, (ord(temp^.x)-48)*(ord(temp^.y)-48),'x^',Ord(temp^.y)-48-1);
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
procedure Delete_element_1(var p:list);
var temp:list;
begin
    New(temp);
    temp:=p^.next;
    p^.next:=p^.next^.next;
    Dispose(temp);
end;
 function Find_element_1(var p:list; vvv:char):boolean;
var temp:list;
begin
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
begin
Create_list_1(s,h);
new(m);
m:=s;
Create_list_2(d,h,s);
while Find_element_1(s,'0') do
  Delete_element_1(s);
Writeln;
write('p(x)=');
Print_list_1(m);
write('p(x*)=');
Print_list_2(m);
Znach(m);
Znach1(d);
dispose(m);
Readln;
readln;
end.
