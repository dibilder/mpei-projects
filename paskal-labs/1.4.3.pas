program Zadanie_1_4_3;

//Входные данные
var 
	n:integer;
	a:array[1..10] of real;
	
//Выходные данные
var 
	indexOfMax:integer;
	
//Промежуточные данные
var	
	max:real;
	i:integer;

function formula(value: real): real;
        begin
			formula:=sqrt(exp(value))-sqr(value);
        end;
	
begin
	writeln('Type array lentgh (n):');
	readln(n);
	for i:=1 to n do
		begin
			writeln('Type ' ,i, ' element of array:');
			read(a[i]);
			writeln('A(',i,') = ',a[i]:6:3);
            writeln('According to the formula: ', formula(a[i]):6:2);
		end;

	max:=a[1];
	indexOfMax:=1;
	for i:=1 to n do
		if formula(a[i]) > formula(max) then
			begin
			        max:=a[i];
			        indexOfMax:=i;
                        end;
	writeln('The highest value is numbered ', indexOfMax);
    readln;
end.
