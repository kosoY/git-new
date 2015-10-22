const n=6;
type mass=array[1..n,1..n]of integer;mas=array[1..n]of integer; 
var x:mass; v,a,b,i,j,kk:integer;h,y:boolean; o,z:mas;
begin
write('Vedit A=');
read(a);   
write('Vedit B=');
read(b); 
for i:=1 to n do
  for j:=1 to n do
  x[i,j]:= random(10);
  for i:=1 to n do
    begin
      writeln;
      for j:=1 to n do
      write(x[i,j]:3);
    end;
h:=false;
y:=false;
begin
for i:=1 to n do  
for j:=1 to n do
       if x[i,j]=a then
           begin
           o[i]:=i;
           h:=true;
           end;
       if h=false then
           o[n]:=n;
       
for i:=1 to n do  
for j:=1 to n do
       if x[i,j]=b then
           begin
           z[j]:=j;
           y:=true;
           end;
       if y=false then
           z[n]:=n; 
       writeln;
   for i:=1 to n do
   begin
    for j:=1 to n do
   begin
   if (z[i]<>0) and (o[j]<>0) then
   begin
   kk:=0;
   for v:=1 to n do
   kk:=kk+x[o[j],v]*x[v,z[i]];
    writeln;
   write('—кал€рний добуток:',kk);
   end;
   end;
   end;
end;
end.
