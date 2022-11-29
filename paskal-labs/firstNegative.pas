Program zadanie;

type
	dim = array[1..100,1..100] of real;

//Входные данные
var
	columnOfMatrix,lineOfMatrix:integer;
	matrix:dim;
//Промежуточные данные
var
	i,j:integer;
	negativeValue:real;
	stage:boolean;
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
	writeln('Type Array:');
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
			for j:=1 to columnOfMatrix do
				if matrix[i,j] = 0 then break else				
					if matrix[i,j] < 0 then
						begin
							negativeValue:= matrix[i,j];
							break;
						end;
			writeln('First negative value - ', negativeValue:4:2);

	readln;
end.
