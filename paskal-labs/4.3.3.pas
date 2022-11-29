Program zadanie;
type
	dim = array[1..100,1..100] of real;
	
//Входные данные
var 
	columnOfMatrix,lineOfMatrix:integer;
	matrix:dim;
	
//Выходные данные
var 
	SrArFirst, SrArSecond: real;	
//Промежуточные данные
var
	i,j,trueColumn:integer;
	


function SrAr(TempMatrix:dim; column,line:integer):real;
	var SummOfElements:real;
	begin
		SummOfElements:=0;
		for i:=1 to line do
			for j:=1 to column do
					SummOfElements:=SummOfElements + TempMatrix[i,j];
		SrAr:=SummOfElements/(column * line);

	end;

function FindColumnOfMatrix(TempMatrix:dim; column,line:integer):integer;
	var
		columnNumber, NegativNumbers, count: integer;

	begin
		columnNumber:=1;
		NegativNumbers:=0;
		for i:=1 to column do
			begin
				count:=0;
				for j:=1 to line do
					begin
						if TempMatrix[j,i] < 0 then
							count:= count + 1;
					end;
				if count > NegativNumbers then
					begin
						columnNumber:=i;
						NegativNumbers:=count;
					end;
			end;

		FindColumnOfMatrix:= columnNumber;
	end;
	
function PrintMatrix(TempMatrix:dim;column,line:integer):integer;
	begin
		for i:=1 to line do
		begin
			for j:=1 to column do
				write(TempMatrix[i,j]:4:2, ' ');
			writeln;
		end;
		PrintMatrix:=0;
	end;
	
procedure ReplaceMatrixColumn(column,line,localTrueColumn:integer;var TempMatrix:dim);
	begin
		for i:= (localTrueColumn + 1) to column do
			for j:=1 to line do
				if TempMatrix[j,i] < 0 then
					TempMatrix[j,i]:=abs(TempMatrix[j,i]);
	end;

begin


	writeln('Type number of array column: ');
	readln(columnOfMatrix);
	writeln(columnOfMatrix);
	writeln('Type number of array line: ');
	readln(lineOfMatrix);
	writeln(lineOfMatrix);

	writeln;
	writeln('Type matrix:');
        for i:=1 to lineOfMatrix do
                begin
                        writeln('Type line ',i , ' with ', columnOfMatrix,' elements:');
                        for j:=1 to columnOfMatrix  do
	                       read(matrix[i,j]);
                        for j:=1 to columnOfMatrix  do
	                       write(matrix[i,j]:4:2, ' ');
						writeln;
                end;
				
	writeln('Matrix:');
	PrintMatrix(matrix, columnOfMatrix, lineOfMatrix);

	SrArFirst:= SrAr(matrix, columnOfMatrix, lineOfMatrix);

	trueColumn:= FindColumnOfMatrix(matrix, columnOfMatrix, lineOfMatrix);
	writeln('Column with the most negative elements: ', trueColumn);

	ReplaceMatrixColumn(columnOfMatrix, lineOfMatrix, trueColumn, matrix);
	
	SrArSecond:= SrAr(matrix, columnOfMatrix, lineOfMatrix);

	writeln('Matrix after changes:');
	PrintMatrix(matrix, columnOfMatrix, lineOfMatrix);
	
	writeln('Old average ', SrArFirst:4:2);
	writeln('New average ', SrArSecond:4:2);

	readln;
	
end.
