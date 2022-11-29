Program zadanie;

type
	dim = array[1..100,1..100] of real;
	
var
	lengthOfMatrix:integer;
	matrix:dim;
	i,j:integer;
	checkMainDiagonal, checkSideDiagonal:boolean;

begin	
	writeln('Type matrix length:');
	readln(lengthOfMatrix);
	writeln(lengthOfMatrix);
	
	writeln('Type matrix:');
        for i:=1 to lengthOfMatrix do
                begin
                        writeln('Type line ',i, ':');
                        for j:=1 to lengthOfMatrix  do
	                       read(matrix[i,j]);
						writeln;
                end;
												
	writeln('matrix:');
	for i:=1 to lengthOfMatrix do
		begin
			for j:=1 to lengthOfMatrix do
				write(matrix[i,j]:4:2, ' ');
			writeln;
		end;
		
	for i:=1 to lengthOfMatrix-1 do
		if matrix[i, i] < matrix [i+1,i+1] then 
			checkMainDiagonal:=true 
		else 
			checkMainDiagonal:=false;
			
	for i:=1 to lengthOfMatrix-1 do
		if matrix[i, lengthOfMatrix - i + 1] < matrix [i+1, lengthOfMatrix - i] then 
			checkSideDiagonal:=true 
		else 
			checkSideDiagonal:=false;		
	
	
	if checkMainDiagonal then 
		writeln('Main diagonal is ordered ascending')
	else 
		writeln('Main diagonal is not ordered in ascending order');
		
	if checkSideDiagonal then 
		writeln('Side diagonal is ordered ascending')
	else 
		writeln('Side diagonal is not ordered in ascending order');
		
	readln;
end.
