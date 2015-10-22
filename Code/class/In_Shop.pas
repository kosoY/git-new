Unit In_Shop;
 interface
  uses Books;
  type book_in_shop=class(book)
       public
        price:integer;
        amount:integer;
        is_or_not:string[5];
        Procedure Read_dani;
        Procedure Change_price;
        Procedure Write_dani;
       end;
 implementation
  Procedure book_in_shop.Read_dani;
  begin       
    writeln(' Наявнiсть у магазинi:');
    readln(is_or_not);
    writeln(' Цiна:');
    readln(price);
    writeln(' К-сть примiрникiв:');
    readln(amount);
  end;
  Procedure book_in_shop.Change_price;
  begin
    if is_or_not='є' then
    begin
      writeln(' Оскiльки книжка "',name,'" є в наявностi, то змiнiть к-сть примiрникiв:');     
      readln(amount);
    end;
  end;  
  Procedure Book_In_Shop.Write_dani;
  begin
     inherited Write_dani;
     writeln(' Наявнiсть у магазинi:');
     writeln(is_or_not);     
     writeln(' Цiна:');
     writeln(price);
     writeln(' К-сть примiрникiв:');
     writeln(amount);
   end;
  end.
        