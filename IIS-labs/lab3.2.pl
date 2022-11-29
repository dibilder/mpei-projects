run :- write('Type R, T, S'), nl,
  read(R), number(R),
  read(T), number(T),
  read(S), number(S),
  calc_Y(R, T, S, Y), write('Y = '), write(Y), nl.
calc_Y(R, _, S, Y) :- R^2 < S, !, Y is 1 - R^2.
calc_Y(R, T, _, Y) :- T >= R^2, Y is 0.
calc_Y(R, _, _, Y) :- Y is 1 + R^2.

