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
    writeln(' �����i��� � �i��i����i:');
    readln(is_or_not);
    if is_or_not='����' then 
    begin
      writeln(' ���� ������:');
      readln(edition);
    end;
  end;
  Procedure book_in_library.Vydacha;
  begin
    if is_or_not='�' then 
    begin
      is_or_not:='����';
      writeln(' ���i���� ������ ��������i ������ "',name,'" ��i����,�� ������� ������ ������:');      
      readln(edition);
   end;
  end;  
  Procedure Book_In_Library.Write_dani;
  begin
     inherited Write_dani;
     writeln(' �����i��� � �i��i����i:');     
     if is_or_not='�' then
      writeln(is_or_not)
      else
          if is_or_not='����' then
           begin
             writeln(is_or_not);
             writeln(' ���� ������:');
             writeln(edition);
           end;
  end; 
 end.
 

            