:- encoding(utf8).

lector('Михеев', 'Математика', '351', '09.06.2022').
lector('Успенская', 'Информатика', '222', '14.06.2022').
lector('Яшин', 'Механика', '222', '17.06.2022').
lector('Казанцев', 'История', '312', '17.06.2022').
lector('Бобкин', 'Право', '351', '23.06.2022').
student('Ивашин', '351', '53595').
student('Кузнецова', '351', '37115').
student('Драгунова', '351', '30142').
student('Глазачев', '351', '31659').
student('Цыганков', '351', '19969').
student('Шурупов', '222', '36552').
student('Баздрева', '222', '44526').
student('Майснер', '222', '32890').
student('Гусев', '222', '32676').
student('Фомичев', '222', '75633').
student('Мирумиров', '312', '48635').
student('Куркова', '312', '77821').
student('Лойтер', '312', '96984').
student('Гончаров', '312', '33214').
student('Васильков', '312', '68692').


print_students_by_date :-
  write('Введите дату экзамена: '), read(N), nl,
  write('Фамилии студентов:'), nl,
  lector(_, _, X, N), student(Y, X, _),
  write(Y), nl, fail.
print_students_by_date.

print_students_by_lector :-
  write('Введите фамилию преподавателя: '), read(N), nl,
  write('Фамилии студентов:'), nl,
  lector(N, _, X, _), student(Y, X, _),
  write(Y), nl, fail.
print_students_by_lector.

print_subjects_by_student :-
  write('Введите фамилию студента: '), read(N), nl,
  write('Названия дисциплин:'), nl,
  lector(_, Y, X, _), student(N, X, _),
  write(Y), nl, fail.
print_subjects_by_student.

print_lectors_by_group :-
  write('Введите название группы: '), read(N), nl,
  write('Фамилии преподавателей:'), nl,
  lector(Y, _, N, _),
  write(Y), nl, fail.
print_lectors_by_group.

print_students_by_group :-
  write('Введите название группы: '), read(N), nl,
  write('Фамилии студентов:'), nl,
  student(Y, N, _),
  write(Y), nl, fail.
print_students_by_group.

print_subjects_by_lector :-
  write('Введите фамилию преподавателя: '), read(N), nl,
  write('Названия дисциплин:'), nl,
  lector(N, Y, _, _),
  write(Y), nl, fail.
print_subjects_by_lector.
