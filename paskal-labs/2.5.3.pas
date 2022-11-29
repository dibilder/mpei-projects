Program zadanie_2_5_3_23;
const
	lengthOfMatrix=5;
type
	dim = array[1..100,1..100] of real;
	
var
	matrixA, matrixB:dim;
	massivC:array[1..100] of real;

var	
	i,j:integer;
	status:boolean;

begin
	writeln;
	//Ввод матрицы A	
	writeln('Type Matrix A 5*5:');
        for i:=1 to lengthOfMatrix do
                begin
                        writeln('Type line ',i, ':');
                        for j:=1 to lengthOfMatrix  do
	                       read(matrixA[i,j]);
                        for j:=1 to lengthOfMatrix  do
	                       write(matrixA[i,j]:4:2, ' ');
						writeln;
                end;
	//Вывод матрицы A				
	writeln('Matrix A:');
	for i:=1 to lengthOfMatrix do
		begin
			for j:=1 to lengthOfMatrix do
				write(matrixA[i,j]:4:2, ' ');
			writeln;
		end;
	//Ввод матрицы B	
	writeln('Type Matrix B 5*5:');
    for i:=1 to lengthOfMatrix do
        begin
            writeln('Type line ',i, ':');
            for j:=1 to lengthOfMatrix  do
	            read(matrixB[i,j]);
            for j:=1 to lengthOfMatrix  do
	            write(matrixB[i,j]:4:2, ' ');
			writeln;
        end;
	//Вывод матрицы B	
	writeln('Matrix B:');
	for i:=1 to lengthOfMatrix do
		begin
			for j:=1 to lengthOfMatrix do
				write(matrixB[i,j]:4:2, ' ');
			writeln;
		end;
	
	//Сравнение матриц
	//Если случается false, досрочный выход из циклов
	status:=true;
	for i:=1 to lengthOfMatrix do
		begin
			if status=false then break;
			for j:=1 to lengthOfMatrix do
				if matrixA[i,j] > matrixB[i,j] then
					status:=true
				else 
					begin
						status:=false;
						break;				
					end;
		end;
	writeln(status);
	
	//Заполнение и вывод массива C
	if status then
		begin 
			writeln('Array C:');
			for i:=1 to lengthOfMatrix do
				begin
					massivC[i]:=0;
					for j:=1 to lengthOfMatrix do
						massivC[i]:= massivC[i] + MatrixA[i,j] + MatrixB[i,j];
					write(massivC[i]:4:2, ' ');
				end;
		end
	else writeln('Check failed. Some elements of matrix B are larger than elements of matrix A.');

    readln;
end.
