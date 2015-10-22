program p3;


var t,f,a,b :text;
k:integer;
g:string;
i:integer;
begin
assign(t,'sim1.txt');
reset(t);
assign(f,'visim_.txt');
rewrite(f);
writeln('Vvedit chyslo kratnocti');
read(k);
i:=0;
while not eof(t) do
begin
i:=i+1;
readln(t,g);
if (i mod k) =0 then
writeln(f,g);
end;
close(t);
close(f);
assign(a,'sim_.txt');
rewrite(a);
assign(b,'visim_.txt');
reset(b);
while not eof(b) do
begin
readln(b,g);
writeln(a,g);
end;
close(a);
close(b);
erase(b);
end.