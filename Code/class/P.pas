Program p; 
 uses crt,Books,In_Library,In_Shop;
 const n=4;
 type mas=array[1..n]of book;
 var i,k,L,Sh:integer;
     book1, book2, book3:mas;
     bookL:array[1..n]of book_in_library;
     bookSh:array[1..n]of book_in_shop;
     temp:book;
     title:string;
 Procedure Sort(var book2:mas;k:integer); 
 var i,j:integer;
 begin
   for j:=1 to k-1 do
     for i:=1 to k-j do
      if(book2[i].name>book2[i+1].name) then
       begin
         temp:=book2[i];
         book2[i]:=book2[i+1];
         book2[i+1]:=temp;
       end; 
 end; 
 Procedure SortNil(var book1:mas);
 var i,j:integer;
 begin
    for j:=1 to n-1 do
     for i:=1 to n-j do
      if(book1[i].name='') then
       begin
         temp:=book1[i];
         book1[i]:=book1[i+1];
         book1[i+1]:=temp;
       end; 
 end;
 begin
   for i:=1 to n do
   begin
     book1[i]:=book.Create;
     book2[i]:=book.Create;
     book3[i]:=book.Create;
     book1[i].Read_dani;
     writeln('---------------------------');
   end;
   for i:=1 to n do
    write('Книжка №',i,': ',book1[i].name,' '); 
   writeln;
   writeln('*************************************************************');
   for i:=1 to n do
   begin
    bookL[i]:=book_in_library.Create;
    bookSh[i]:=book_in_shop.Create;
   end;
   writeln;
   
   k:=0;      
   repeat 
     writeln(' Введiть назву книжок, якi ви хочете записати в бiблiотеку iнакше введiть"досить"');
     readln(title);           
      for i:=1 to n do
        if book1[i].name=title then 
        begin  
          k:=k+1;
          writeln(' Запишiть данi для бiблiотеки');
          book2[k].Copy(book1[i]);                           
          bookL[k].Read_dani; 
          book1[i]:=book.Create;
        end;      
   until (title='досить')or(k=n);    
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
   writeln('===========================================================');  
 end.