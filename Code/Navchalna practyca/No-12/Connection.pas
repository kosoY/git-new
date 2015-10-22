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
        vartist:integer;
        Procedure Read_dani;
        Procedure Connection_.Copy(b:Connection_);
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
     writeln('Vartist za misatz:');
     readln(vartist);
   end;


   Procedure Connection_.Write_dani;
   begin
     write('Nazva meregi : ');
     writeln(name);
     write(' Data pidcluchenya(month): ');
     writeln(month);
     write(' Data pidcluchenya(year): ');
     writeln(year);
     write(' Nayavnust pilgi: ');
     writeln(is_pilga);
     write(' Rozmir pilgi: ');
     writeln(rozmir_pilgi);
     writeln('Vartist za misatz:');
     writeln(vartist);
   end;
 Procedure Connection_.Copy(b:Connection_);
  begin
    name:=b.name;
    month:=b.month;
    year:=b.year;
    is_pilga:=b.is_pilga;
    rozmir_pilgi:=b.rozmir_pilgi;
    vartist:=b.vartist;
  end; 

 end.
          