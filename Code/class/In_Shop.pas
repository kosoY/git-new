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
    writeln(' �����i��� � �������i:');
    readln(is_or_not);
    writeln(' �i��:');
    readln(price);
    writeln(' �-��� ����i����i�:');
    readln(amount);
  end;
  Procedure book_in_shop.Change_price;
  begin
    if is_or_not='�' then
    begin
      writeln(' ���i���� ������ "',name,'" � � ��������i, �� ��i�i�� �-��� ����i����i�:');     
      readln(amount);
    end;
  end;  
  Procedure Book_In_Shop.Write_dani;
  begin
     inherited Write_dani;
     writeln(' �����i��� � �������i:');
     writeln(is_or_not);     
     writeln(' �i��:');
     writeln(price);
     writeln(' �-��� ����i����i�:');
     writeln(amount);
   end;
  end.
        