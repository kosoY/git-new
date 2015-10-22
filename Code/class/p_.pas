program p;

uses
  Connection, For_carta, For_contract;

const
  n = 3;

type
  mas = array[1..n]of Connection_;
  mass= array[1..n]of For_carta_;
  masss= array[1..n]of For_contract_;
var
  i: integer;
  temp: Connection_;
  title: string[20];
  k, l, t, sh: integer;
  Connection1, Connection2, Connection3,Connection4: mas;
  For_carta1: mass;
  For_contract1: masss;
  yea:integer;
  mount:integer;
  w:integer;

procedure Sort(var Connection2: mas; k: integer);
var
  i, j: integer;
begin
  for j := 1 to k - 1 do
    for i := 1 to k - j do
      if(Connection1[i].name > Connection1[i + 1].name) then
      begin
        temp := Connection1[i];
        Connection2[i] := Connection2[i + 1];
        Connection2[i + 1] := temp;
      end; 
end;
procedure Sort_zalychok(var For_carta1:mass);
var i,j:integer;max:real;
begin
  max:=0;
  for i:=1 to n do
    for j:=1 to n do
    if (For_carta1[i].zalychok<For_carta1[j].zalychok) and (j>i) then
    begin
      max:=For_carta1[j].zalychok;
      For_carta1[j].zalychok:=For_carta1[i].zalychok;
      For_carta1[i].zalychok:=max;
    end;  
end;
procedure Sort_zalychok1(var For_contract1:masss);
var i,j:integer;max:real;
begin
  max:=0;
  for i:=1 to n do
    for j:=1 to n do
    if (For_contract1[i].zalychok<For_contract1[j].zalychok) and (j>i) then
    begin
      max:=For_contract1[j].zalychok;
      For_contract1[j].zalychok:=For_contract1[i].zalychok;
      For_contract1[i].zalychok:=max;
    end;  
end;

begin
  for i := 1 to n do
  begin
    Connection1[i] := Connection_.Create;
    Connection2[i] := Connection_.Create;
    Connection3[i] := Connection_.Create;
    Connection4[i] := Connection_.Create;
    Connection1[i].Read_dani;
    writeln('---------------------------');
  end;
  Sort(Connection2, k);
  for i := 1 to n do
    write('Pidcluchenya', i, ': ', Connection1[i].name, ' ');
  writeln;
  writeln('*************************************************************');
  for i := 1 to n do
  begin
    For_carta1[i] := For_carta_.Create;
    For_contract1[i] := For_contract_.Create;
  end;
  writeln;
  
  k := 0;
  repeat
    writeln(' Vedit nazvy pidluchen,za contractom, else vedit (stop)');
    readln(title);           
    for i := 1 to n do
      if Connection1[i].name = title then
      begin
        k := k + 1;
        writeln(' Vedit dani dlya contracty');
        Connection2[k].Copy(Connection1[i]);                           
        For_contract1[k].Read_dani; 
        Connection1[i] := Connection_.Create;
      end;      
  until (title = 'stop') or (k = n);
  writeln('===========================================================');
  L := k;
  Sort(Connection2, L);
  for k := 1 to L do
    For_contract1[k].Copy(Connection2[k]); 
  k := 0;      
  repeat
    writeln(' Vedit nazvy pidluchen,za cartoy, else vedit (stop)');
    readln(title);              
    for i := 1 to n do
      if Connection1[i].name = title then 
      begin
        k := k + 1;
        writeln(' Vedit dani dlya carty');
        Connection3[k].Copy(Connection1[i]);                           
        For_carta1[k].Read_dani; 
        Connection1[i] := Connection_.Create;
      end;      
  until(title = 'stop') or (k = n) or (k + L = n); 
  writeln('===========================================================');
  Sh := k;
  Sort(Connection3, Sh);   
  for k := 1 to Sh do
    For_carta1[k].Copy(Connection3[k]); 
  k := 1;
  for i := 1 to n do
    if Connection1[i].name = '' then
    begin
      Connection1[i] := Connection2[k];
      k := k + 1;
    end;
  k := 1;
  for i := 1 to n do
    if Connection1[i].name = '' then
    begin
      Connection1[i] := Connection3[k];
      k := k + 1;
    end;
  writeln(' Вiдсортований масив:');
  writeln('--------------------');
  for i := 1 to n do
    Connection1[i].Write_dani;
  writeln('=======================================================');  
  readln;
  writeln(' Pidkluchenya za contractom:');
  writeln('--------------------');
  for i := 1 to L do
    For_contract1[i].Write_dani; 
  writeln('=======================================================');  
  writeln(' Pidkluchenya za cartoy:');
  writeln('------------------');
  for i := 1 to Sh do
    For_carta1[i].Write_dani;
  writeln('==========================================================='); 
  Sort_zalychok(For_carta1);
  Sort_zalychok1(For_contract1);
  writeln('Sort za zalychkom');
  readln;
  writeln(' Pidkluchenya za contractom:');
  writeln('--------------------');
  for i := 1 to L do
    For_contract1[i].Write_dani; 
  writeln('=======================================================');  
  writeln(' Pidkluchenya za cartoy:');
  writeln('------------------');
  for i := 1 to Sh do
    For_carta1[i].Write_dani;
  writeln('==========================================================='); 
  writeln('Vedit rik(na danuy chas)');
  read(yea);
  writeln('vedit misatz(na danuy chas');
  read(mount);
    writeln('Naskilki zbilchyty pilgy');
  read(w);
    for i:=1 to n do
  
  if ((yea-Connection1[i].year)>5) and (mount>Connection1[i].month) then
  Connection1[i].rozmir_pilgi:=Connection1[i].rozmir_pilgi+w;
  
  
  
  for i:=1 to n do 
  begin
    if For_carta1[i].zalychok>=(For_carta1[i].vartist)*3 then
    begin
      writeln('Mozna oplatyty 3 misatza takomy pidkluchenuy');
     For_carta1[i].write_dani;
     end;
         if For_contract1[i].zalychok>=(For_contract1[i].vartist)*3 then
    begin
      writeln('Mozna oplatyty 3 misatza takomy pidkluchenuy');
     For_contract1[i].write_dani;
     end;
     if For_carta1[i].zalychok>=(For_carta1[i].vartist) then begin if ((yea-For_carta1[i].year)<=0) 
     then begin if (mount-For_carta1[i].month<=-2) then
     begin
     writeln('Kartka ne diysna 2 misatsya ale syma do oplaty e');
     For_carta1[i].Write_dani;
     end;
     end;
     end;
     end;
      
end.