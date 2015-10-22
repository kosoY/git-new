Unit Connection;
 interface  
  type 
       Connection_=class
       public

        name:string[20];
        year:integer;
        month:integer;
        is_pilga:integer;
        rozmir_pilgi:integer;
        Procedure Read_dani;

        Procedure Write_dani;

       end;
 implementation
   Procedure Connection_.Read_dani;
   begin
     write('Nazva meregi : ');
     readln(name);
     writeln(' Data pidcluchenya(month): ');
     readln(month);
     writeln(' Data pidcluchenya(year): ');
     readln(year);
     writeln(' Nayavnust pilgi(1-nayavna,2-vidcutnya): ');
     readln(is_pilga);
     writeln(' Rozmir pilgi: ');
     readln(rozmir_pilgi);
   end;


   Procedure Connection_.Write_dani;
   begin
     write('Nazva meregi : ');
     write(name);
     writeln(' Data pidcluchenya(month): ');
     write(month);
     writeln(' Data pidcluchenya(year): ');
     write(year);
     writeln(' Nayavnust pilgi: ');
     write(is_pilga);
     writeln(' Rozmir pilgi: ');
     write(rozmir_pilgi);
   end;

 end.
          