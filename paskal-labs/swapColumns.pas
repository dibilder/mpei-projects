Program zadanie;

type
	dim = array[1..100,1..100] of real;
	
//Входные данные
var
	columnOfMatrix,lineOfMatrix:integer;
	matrix:dim;
	newMatrix:dim;
//Промежуточные данные
var 
	i,j:integer;
	temp:real;
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
	writeln;
	writeln('Type array:');
        for i:=1 to lineOfMatrix do
                begin
                        writeln('Type line ',i, ':');
                        for j:=1 to columnOfMatrix  do
	                       read(matrix[i,j]);
						writeln;
                end;
												
	writeln('Array:');
	for i:=1 to lineOfMatrix do
		begin
			for j:=1 to columnOfMatrix do
				write(matrix[i,j]:4:2, ' ');
			writeln;
		end;
		
	for i:=1 to lineOfMatrix do
		begin
			temp:=matrix[i, 1];
			matrix[i,1]:=matrix[i,lineOfMatrix];
			matrix[i, lineOfMatrix]:= temp;			
		end;
	
	writeln('New Array:');
	for i:=1 to lineOfMatrix do
		begin
			for j:=1 to columnOfMatrix do
				write(matrix[i,j]:4:2, ' ');
			writeln;
		end;
	
	readln;
end.
