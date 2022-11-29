program Zadanie_1_2;
//Входные данные
var
	a,b:real;
	n:integer;
//Выходные данные
var
	x,y:real;
//Промежуточные данные
var
	i:integer;
        step: real;

Begin
	writeln('Vvedite kol-vo znacheniy:');
    readln(n);
    writeln(n);
	writeln('Vvedite nachalo otrezka:');
    readln(a);
    writeln(a:4:2);
	writeln('Vvedite konetz otrezka:');
    readln(b);
    writeln(b:4:2);


	step:=(b-a)/n;
    writeln('Shag proscheta znacheniy:', step:4:2);

    x:=a;
    i:=0;

	writeln('n      x         y');
    while x<=b do
        begin
                y:=ln(sqrt(pi + abs(2-x)))/(3-(1/x)) + (exp(ln(sqr(x))/3)*sin((1/4)*x));
				writeln(i, '    ', x:6:2, '    ',y:6:2);
                x:=x+step;
                i:=i+1;
        end;
    readln;
End.
