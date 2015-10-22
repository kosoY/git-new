Program Task2;
type
    mas=array[1..100] of integer;
var
    i, n, j, counter:integer;
    a:mas;

Begin
    write('Please enter number of elements of array: ');
    readln(n);
    write('Please enter elements of array: ');
    for i:=1 to n do
    begin
        read(a[i]);
    end;
    
    for i:=1 to n do
    begin
        counter:=0;
        for j:=1 to n do
        begin
            if a[j]=i then
            begin
                inc(counter);
            end;
        end;
        if counter=0 then
        begin
            writeln('Array is NOT a transposition');
            exit;
        end;
    end;
    
    writeln('Array IS a transposition');
end.
        