        run :- assertz(xpositive(' ',' ')), assertz(xnegative(' ',' ')), 
        nl,write(' * * * * * * * * * * * * * * * * * * * * *  '),
        nl,write('          ����� ����������!          '),
        nl,write(' ������� ��� ����������� '),
        nl,write(' ������ ����������  '),
        nl,write(' ������������ ������� '),
        nl,write(' �������, ��� � ��� '),
        nl,write(' * * * * * * * * * * * * * * * * * * * * * * '), nl, expertiza.
 expertiza :- car_is(X), !, nl, write('��������, ��������� ���������� � '), write(X), write('.'), 
                             nl,clear_facts.
 expertiza :- nl, write('��������, ���������� ���������� �� ����������!'), clear_facts. 
vopros(X, Y):-write('������ � '),write(X),write(' '),
write(Y),write('? (��/���) '),read(R),remember(X,Y,R).
positive(X,Y):-xpositive(X,Y),!.
positive(X,Y):-not(negative(X,Y)),!,vopros(X,Y).
negative(X,Y):-xnegative(X,Y),!.
remember(X,Y,'��'):-assertz(xpositive(X,Y)).
remember(X,Y,'���'):-assertz(xnegative(X,Y)),fail.
clear_facts:-retract(xpositive(_,_)),fail.
clear_facts:-retract(xnegative(_,_)),fail.
car_is('Lada Vesta') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ����� 2015 ����'),
                             positive('������ ','������������ �� ����������� ���������'),!. 
car_is('Lada Largus') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ����� 2015 ����'),
                             positive('������','������������ �� ��������� Renault'),
							 positive('������','��������������� ��� ��������������'),!. 
car_is('Lada XRay') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ����� 2015 ����'),
                             positive('������','������������ �� ��������� Renault'),
							 negative('������','��������������� ��� ��������������'),!. 
car_is('Lada Granta') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ����� 2011 ����'),
                             positive('������','����� ������� � �������������� �������� �������'),!.  
car_is('Lada Priora') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ������ 2011 ����'),
                             positive('������','����� ������� ������ �������?'),!.
car_is('VAZ 2115') :-positive('���','�������� ���������� '),
                             positive('� ����','�������� ������'),
                             positive('������','��������� ������ 2011 ����'),
                             negative('������','����� ������� ������ �������?'),!.
car_is('GAZ Volga') :-positive('���','�������� ���������� '),
                             positive('� ����','������ ������'),
                             positive('������','����������������� ��� ������� ����������'),!.
car_is('VAZ 2105') :-positive('���','�������� ���������� '),
                             positive('� ����','������ ������'),
                             negative('������','����������������� ��� ������� ����������'),!.
car_is('Lada Niva Classic') :-positive('���','����������� ���������� '),
                             positive('������','����� ����������� �������'),!.
car_is('UAZ Patriot') :-positive('���','����������� ���������� '),
                             positive('������','����� ����������� �������� ������'),!.
car_is('Lada Niva Travel') :-positive('���','����������� ���������� '),
                             negative('������','����� ����������� �������� ������'),!.							 
 
