program p3;

type mas=array[1..100] of string;

var t :text;
l:mas;
g:string;
i:integer;
begin
assign(t,'No7-8');
reset(t);
i:=0;
while not eof(t) do
begin
read(g);
i:=i+1;
l[i]:=g;
end;
end.