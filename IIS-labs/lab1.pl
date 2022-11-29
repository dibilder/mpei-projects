parent('�������','����').
parent('�������','��������').
parent('���','����').
parent('���','��������').
parent('����','����').
parent('����','���').
parent('��������','��').
parent('���','����').
person('�������',f,72).
person('���',m,78).
person('����',m,42).
person('��������',f,35).
person('��',m,14).
person('����',f,20).
person('���',f,25).
person('����',m,3).
father(X, Y) :- parent(X, Y), person(X, m, _).
grandmother(X, Y) :- parent(X, Z), parent(Z, Y), person(X, f, _).
sister(X, Y) :- parent(Z, X), parent(Z, Y), person(X, f, _), X \= Y.
nephew(X, Y) :- person(X, 'm', _), parent(Z, X), parent(A, Z), parent(A, Y).
niece(X, Y) :- person(X, 'm', _), parent(Z, X), parent(A, Z), parent(A, Y).
parentofparent(X, Y) :- parent(X, Z), parent(Z, Y).
greatgrandfather(X, Y) :- parent(X, A), parent(A, Z), parent(Z, Y), person(X, 'm', _).
cousin(X, Y) :- person(X, 'm', _), parent(A, Z), parent(Z, X), parent(A, B), parent(B, Y), X \= Y.

