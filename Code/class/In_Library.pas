Unit In_Library;
 interface  
  uses Books; 
  type 
       book_in_library=class(book)
       public          
        is_or_not:string[5];
        edition:string[10];
        Procedure Read_dani;
        Procedure Vydacha;       
        Procedure Write_dani;       
       end;
 implementation
  Procedure book_in_library.Read_dani;
  begin    
    writeln(' Наявнiсть у бiблiотецi:');
    readln(is_or_not);
    if is_or_not='немає' then 
    begin
      writeln(' Кому видана:');
      readln(edition);
    end;
  end;
  Procedure book_in_library.Vydacha;
  begin
    if is_or_not='є' then 
    begin
      is_or_not:='немає';
      writeln(' Оскiльки ознаку наявностi книжки "',name,'" змiнено,то видайте комусь книжку:');      
      readln(edition);
   end;
  end;  
  Procedure Book_In_Library.Write_dani;
  begin
     inherited Write_dani;
     writeln(' Наявнiсть у бiблiотецi:');     
     if is_or_not='є' then
      writeln(is_or_not)
      else
          if is_or_not='немає' then
           begin
             writeln(is_or_not);
             writeln(' Кому видана:');
             writeln(edition);
           end;
  end; 
 end.
 

            