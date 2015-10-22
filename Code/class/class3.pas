Program p; 
 uses Connection, For_carta, For_contract;
 const n=2;
 type mas=array[1..n]of Connection_;
 var i:integer;  temp:Connection_;  title:string[20];
     Connection1, Connection2, Connection3:mas;
     For_carta1:array[1..n]of For_carta_;
     For_contract1:array[1..n]of For_contract_;

 Procedure Sort(var Connection2:mas);
 var i,j:integer;
 begin
   for j:=1 to n-1 do
     for i:=1 to n-j do
      if(Connection1[i].name>Connection1[i+1].name) then
       begin
         temp:=Connection1[i];
         Connection2[i]:=Connection2[i+1];
         Connection2[i+1]:=temp;
       end; 
 end; 

 begin
   for i:=1 to n do
   begin
     Connection1[i]:=Connection_.Create;
     Connection2[i]:=Connection_.Create;
     Connection3[i]:=Connection_.Create;
     Connection1[i].Read_dani;
     writeln('---------------------------');
   end;
 //  Sort (Connection2);
   for i:=1 to n do
    write('Pidcluchenya',i,': ',Connection1[i].name,' ');
   writeln;
   writeln('*************************************************************');
   for i:=1 to n do
   begin
    For_carta1[i]:=For_carta_.Create;
    For_contract1[i]:=For_contract_.Create;
   end;
   writeln;
   
  // k:=0;
   repeat 
     writeln(' Vedit nazvy pidluchen,za contractom, else vedit 'stop');
     readln(title);           
      for i:=1 to n do
        if Connection1[i].name=title then
        begin  
          k:=k+1;
          writeln(' Vedit dani dlya contracty');
          book2[k].Copy(book1[i]);                           
          bookL[k].Read_dani; 
          book1[i]:=book.Create;
        end;      
   until (title='stop')or(k=n);
   writeln('===========================================================');
   L:=k;
   Sort(book2,L);
   for k:=1 to L do
    bookL[k].Copy(book2[k]); 
   writeln('Книжки в бiблiотецi:');
   writeln('--------------------');
   for i:=1 to L do
    bookL[i].Write_dani;    
   for i:=1 to L do
    bookL[i].Vydacha;   
   writeln('==========================================================='); 
   k:=0;      
   repeat 
     writeln(' Введiть назву книжок, якi ви хочете записати в магазин iнакше введiть"досить"');
     readln(title);              
      for i:=1 to n do
        if book1[i].name=title then 
        begin 
          k:=k+1;
          writeln(' Запишiть данi для магазину');
          book3[k].Copy(book1[i]);                           
          bookSh[k].Read_dani; 
          book1[i]:=book.Create;
        end;      
   until(title='досить')or(k=n)or(k+L=n); 
   writeln('===========================================================');
   Sh:=k;
   Sort(book3,Sh);   
   for k:=1 to Sh do
   bookSh[k].Copy(book3[k]);
   writeln('Книжки в магазинi:');
   writeln('------------------');
   for i:=1 to Sh do
    bookSh[i].Write_dani;
   for i:=1 to Sh do
    bookSh[i].Change_price;
   writeln('===========================================================');  
   readln;
   Sort(book1,n);
   SortNil(book1);   
   k:=1;
   for i:=1 to n do
    if book1[i].name='' then
     begin 
       book1[i]:=book2[k];
       k:=k+1;
     end;
   k:=1;
   for i:=1 to n do
    if book1[i].name='' then
     begin 
       book1[i]:=book3[k];
       k:=k+1;
     end;
   writeln(' Вiдсортований масив:');
   writeln('--------------------');
   for i:=1 to n do
    book1[i].Write_dani;
   writeln('=======================================================');  
   book1[1].ComparingUDK(book1[2]);
   readln;
   writeln(' Книжки в бiблiотецi:');
   writeln('--------------------');
   for i:=1 to L do
    bookL[i].Write_dani; 
   writeln('=======================================================');  
   writeln(' Книжки в магазинi:');
   writeln('------------------');
   for i:=1 to Sh do
    bookSh[i].Write_dani;
   writeln('===========================================================');  }
 end.