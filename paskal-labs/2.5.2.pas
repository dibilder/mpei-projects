Program zadanie_2_5_2;

type
	dim = array[1..100,1..100] of real;
	
//Входные данные
var
	columnOfMatrix,lineOfMatrix:integer;
	matrix:dim;
//Промежуточные данные
var 
	i,j:integer;
	SummOfColumnValue:real;
//Выходные данные
var 
	SrAr:real;
	

begin	
	writeln('Type number of matrix column:');
	readln(columnOfMatrix);
	writeln(columnOfMatrix);
	writeln('Type number of matrix line:');
	readln(lineOfMatrix);
	writeln(lineOfMatrix);
	
	for i:=1 to columnOfMatrix do
		begin
			SummOfColumnValue:=0;
			for j:=1 to lineOfMatrix do
				begin
					writeln('Type element ', i, ' in column ', j, ':');
					readln(matrix[i,j]);
					writeln(matrix[i,j]:4:2);
					
					SummOfColumnValue:= SummOfColumnValue + matrix[i,j];
				
					if matrix[i,j] >=0 then
						matrix[i,j]:=1
					else 
						matrix[i,j]:=0;
						
					writeln('Result after conversion: ', matrix[i,j]:4:2);										
				end;
			SrAr:= SummOfColumnValue/lineOfMatrix;
			writeln('Average of column = ', SrAr:4:2);
		end;
    readln;

end.
