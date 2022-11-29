program zadanie_5_2_1;

type
    student = record
        group: string;
        fullName: string;
        year: word;
        gender: char;
        physics, math, info: byte;
        scholarship: real;
    end;

    arrayOfStudents = array[1..30] of student;
	
//Входные данные
var 
	N: Integer;
	A: arrayOfStudents;
//Выходные данные
var 
	counter: Integer;
//Промежуточные данные
var
	
	i: Integer;
	currentGroup:string;


begin
	counter:=0;
	currentGroup:='C5-97';

    write('Type number of students: ');
    readln(N);
    writeln();

    for i := 1 to N do
        with A[i] do
            begin
				//Такой избыток операторов ввода вывода связан с очень кривой их работой с record записями.
				//Возможно только на моем FreePascal
                writeln('Stundent ', i,':');

				writeln('Type group:');
				readln;
                read(group);
				writeln(group);

                writeln('Type name: ');
				readln;
                read(fullName);
				writeln(fullName);

				writeln('Type year of brith: ');
			    readln;
                read(year);
				writeln(year);

                write('Type gender: ');
				readln;
                read(gender);
				writeln(gender);

                write('Type physics mark: ');
				readln;
                read(physics);
				writeln();

                write('Type math mark: ');
				readln;
                read(math);
				writeln();

                write('Type computer science mark: ');
				readln;
                read(info);
				writeln();

                write('Type scholarship: ');
				readln;
                read(scholarship);
                writeln();
            end;
    writeln();


    writeln('Students in group C5-97 and all five marks: ');
    for i := 1 to N do
        with A[i] do
            if (group = currentGroup) and (((physics + math + info) / 3) = 5) then
                    begin
						counter:= counter + 1;
                        writeln('Name: ', fullName);
                        writeln('Scholarship: ', scholarship:6:2);
                        writeln;
                    end;

         
    writeln('The number of such students: ', counter);
    readln;
end.
