program Zadanie_1_6;

//Входные данные
var
	N:integer;
	A, x1: real;
//Выходные данные
var
	x,y:real;

//Промежуточные данные
var
	i:integer;
	dX:real;

begin
    writeln('Type N: ');
    readln(N);
	writeln(N);
    writeln('Type A: ');
    readln(A);
	writeln(A:4:2);
    writeln('Type x1: ');
    readln(x1);
	writeln(x1:4:2);
    dX := A / 2;
    x := 0;
    writeln('x1 = ', x1:0:4);
    writeln('dX = A / 2 = ', dX:0:4);
	
	if N <= 0 then
         writeln('Error.')
    else
        begin
            writeln('N       X          Y');
            for i := 1 to N do
                begin
                    x := x1 + (dX * (i - 1));
                    if x < 4*A then
                        y := sqrt(16*sqr(A) - sqr(x - 4*A))
                    else
                        y := (8*(Exp(Ln(A) * 3)))/(sqr(x - 4*A) + 4*sqr(A));
                    writeln(i, '       ', x:0:4, '    ', y:0:4);
                end;
        end;
        readln();
end.
