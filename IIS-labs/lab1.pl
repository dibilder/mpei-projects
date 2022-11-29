parent('Памелла','Джон').
parent('Памелла','Элизабет').
parent('Том','Джон').
parent('Том','Элизабет').
parent('Джон','Анна').
parent('Джон','Пат').
parent('Элизабет','Эд').
parent('Пат','Джим').
person('Памелла',f,72).
person('Том',m,78).
person('Джон',m,42).
person('Элизабет',f,35).
person('Эд',m,14).
person('Анна',f,20).
person('Пат',f,25).
person('Джим',m,3).
father(X, Y) :- parent(X, Y), person(X, m, _).
grandmother(X, Y) :- parent(X, Z), parent(Z, Y), person(X, f, _).
sister(X, Y) :- parent(Z, X), parent(Z, Y), person(X, f, _), X \= Y.
nephew(X, Y) :- person(X, 'm', _), parent(Z, X), parent(A, Z), parent(A, Y).
niece(X, Y) :- person(X, 'm', _), parent(Z, X), parent(A, Z), parent(A, Y).
parentofparent(X, Y) :- parent(X, Z), parent(Z, Y).
greatgrandfather(X, Y) :- parent(X, A), parent(A, Z), parent(Z, Y), person(X, 'm', _).
cousin(X, Y) :- person(X, 'm', _), parent(A, Z), parent(Z, X), parent(A, B), parent(B, Y), X \= Y.

