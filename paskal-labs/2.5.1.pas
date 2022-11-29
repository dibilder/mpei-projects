Program zadanie;

const
	pi = 3.14;
type
	dim = array[1..100,1..100] of real;

var
	matrix:dim;
	columnOfMatrix,lineOfMatrix,i,j,counter:integer;
	sideA,sideB,Srectangle,Sring:real;

begin

	writeln('Vvedite storonu A pramougolnika:');
	readln(sideA);
	writeln(sideA:4:2);
	writeln('Vvedite storonu B pramougolnika:');
	readln(sideB);
	writeln(sideB:4:2);
	Srectangle:=sideA*sideB;

	columnOfMatrix:=2;
	lineOfMatrix:=10;
	writeln('Kol-vo stolbcov matrici: ', columnOfMatrix);
	writeln('Kol-vo strok matrici: ', lineOfMatrix);
	writeln('Stolbec 1 - vnutrenniy diametr kolca, stolbec 2 - vneshniy');
	for i:=1 to lineOfMatrix do
		for j:=1 to columnOfMatrix do
                        begin
							if j = columnOfMatrix then
								begin
									repeat
									writeln('Vevdite znachenie v stroke ', i, ' stolbce ', j, ':');
									readln(matrix[i,j]);
									if matrix[i,j] <  matrix[i,j-1] then
										writeln('Vneshniy diametr kolca ne moget bit menshe vnutrennego!');
									until matrix[i,j] > matrix[i,j-1];
								end
							else
								begin
									writeln('Vvedite znachenie v stroke ', i, ' stolbce ', j, ':');
									readln(matrix[i,j]);
								end;
							writeln(matrix[i,j]:4:2);
                        end;
	writeln('Massiv:');
	for i:=1 to lineOfMatrix do
		begin
			for j:=1 to columnOfMatrix do
				write(matrix[i,j]:4:2, ' ');
			writeln;
		end;

	//Можно было сделать все в одном цикле, но я не захотел. Слишком захламленно получается.
	counter:=0;
	for i:=1 to lineOfMatrix do
		begin
			Sring:= pi * (sqr(matrix[i,2]/2) - sqr(matrix[i,1]/2));
			if Sring > Srectangle then
				begin
					writeln('S kolca bolshe. Vneshniy ego diametr = ', matrix[i,2]:4:2);
					counter:= counter + 1;
				end;
		end;
	writeln('Kol-vo kolec, chya ploshyad bolshe: ', counter);
    readln;

end.
