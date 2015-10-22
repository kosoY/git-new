Unit For_carta;
 interface
  uses Connection;
  type For_carta_=class(Connection_)
       public
        zalychok:real;
        nomer_rachynky :integer;
        year:integer;
        month:integer;
        Procedure Read_dani;
        Procedure Write_dani;
       end;
 implementation
  Procedure For_carta_.Read_dani;
  begin       
    writeln(' Nomer rachynky:');
    readln(nomer_rachynky);
    writeln(' Data zakinchenya(month): ');
    readln(month);
    writeln(' Data zakinchenya(year): ');
    readln(year);
    writeln(' Zalychok:');
    readln(zalychok);
  end;

  Procedure For_carta_.Write_dani;
  begin
     inherited Write_dani;
    write(' Nomer rachynky:');
    writeln(nomer_rachynky);
    write(' Data zakinchenya(month): ');
    writeln(month);
    write(' Data zakinchenya(year): ');
    writeln(year);
    write(' Zalychok:');
    writeln(zalychok);
   end;
  end.
        