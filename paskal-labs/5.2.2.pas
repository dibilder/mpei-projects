program zadanie;

type
    children = record
        Name: string;
        SecondName: string;
        Age: byte;
        Weight: byte;
		Height: byte;
    end;

    arrayOfChildrens = array[1..30] of children;
//Входные данные
var 
	A: arrayOfChildrens;
	N: Integer;
//Промежуточные данные	
var	
	i: Integer;

begin
    write('Type number of childrens: ');
    readln(N);
    writeln();

    for i := 1 to N do
        with A[i] do
            begin
				//Такой избыток операторов ввода вывода связан с очень кривой их работой с record записями.
				//Возможно только на моем FreePascal
                writeln('Children ', i,':');

				writeln('Type name:');
				readln;
                read(Name);
				writeln(Name);

                writeln('Type second name: ');
				readln;
                read(SecondName);
				writeln(SecondName);

				writeln('Enter the childs age: ');
			    readln;
                read(Age);
				writeln(Age);

                writeln('Type height: ');
				readln;
                read(Height);
				writeln(Height);

				writeln('Type weight: ');
				readln;
                read(Weight);
				writeln(Weight);
            end;
    writeln();


    writeln('Children from 10 to 12 years old, whose height is not less than 155, and weight is not more than 45 kg: ');
    for i := 1 to N do
        with A[i] do
            if (((Age >= 10) and (Age <= 12)) and (height >= 155) and (weight <= 45)) then
                    begin
                        writeln(Name, ' ', SecondName);
                        writeln;
                    end;

    readln;
end.
