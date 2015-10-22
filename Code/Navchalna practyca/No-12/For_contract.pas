Unit For_contract;
 interface
  uses Connection;
  type 
       For_contract_=class(Connection_)
       public
        zalychok:real;
        nomer_rachynky :integer;
        year:integer;
        month:integer;
        Procedure Read_dani;
        Procedure Write_dani;       
       end;
 implementation
  Procedure For_contract_.Read_dani;
  begin    
    writeln(' Nomer rachynky:');
    readln(nomer_rachynky);
    writeln(' Data vidkrutya(month): ');
    readln(month);
    writeln(' Data vidkrutya(year): ');
    readln(year);
    writeln(' Zalychok:');
    readln(zalychok);
  end;
  
  Procedure For_contract_.Write_dani;
  begin
     inherited Write_dani;
    write(' Nomer rachynky:');
    writeln(nomer_rachynky);
    write(' Data vidkrutya(month): ');
    writeln(month);
    write(' Data vidkrutya(year): ');
    writeln(year);
    write(' Zalychok:');
    writeln(zalychok);
 end;
 end.
 

            