program Zadanie_1_4_2;

//Входные данные
var
	n:integer;
	x:array[1..100] of real;
	
//Выходные данные
var
	SrAr:real;
	PositiveCount:integer;

//Промежуточные данные
var
	CountForSrAr, i: integer;
	SummForSrAr: real;

begin
	writeln('Type array length (n):');
	readln(n);
	writeln(n);
    if n > 100 then
            writeln('Very large value (>100)')
    else
        begin
			SummForSrAr:=0;
			CountForSrAr:=0;
			PositiveCount:=0;
            for i:=1 to n do
		        begin
			        writeln('Type ' ,i, ' element of array X:');
					read(x[i]);
					writeln(x[i]:4:2);
					if x[i] <> 0 then
				        begin
					        SummForSrAr:= SummForSrAr + x[i];
							CountForSrAr:= CountForSrAr + 1;
						end;
					if x[i] >= 0 then
				        PositiveCount:= PositiveCount + 1;
				end;
		end;
	SrAr:= SummForSrAr/CountForSrAr;
    writeln('Average of <> 0 value: ',SrAr:6:2);
	writeln('Number of positive values: ', PositiveCount);
    readln;
end.
