program Zadanie_1_4_1;

//Входные данные
var 
	n:integer;
	x,y:array[1..100] of real;
//Выходные данные
var 
	t:array[1..100] of real;
//Промежуточные данные
var
	i:integer;
	
begin
	writeln('Type array length (n):');
	readln(n);
	writeln(n);
        if n > 100 then
                writeln('Very large value (>100)')
        else
                begin
                        for i:=1 to n do
							begin
								writeln('Type ' ,i, ' element of array X:');
								read(x[i]);
								writeln(x[i]:4:2);
								writeln('Type ' ,i, ' element of array Y:');
								read(y[i]);
								writeln(y[i]:4:2);
								if i = 1 then
									t[i]:= 1
								else
									t[i]:= (sqrt(sqr(x[i] - y[i])))/t[i-1];
                                writeln('Element' ,i,' of array T = ', t[i]:6:2);
		               end;
                end;
        readln;
end.
