        run :- assertz(xpositive(' ',' ')), assertz(xnegative(' ',' ')), 
        nl,write(' * * * * * * * * * * * * * * * * * * * * *  '),
        nl,write('          ДОБРО ПОЖАЛОВАТЬ!          '),
        nl,write(' Система для определения '),
        nl,write(' модели автомобиля  '),
        nl,write(' производства заводов '),
        nl,write(' АвтоВАЗ, УАЗ и ГАЗ '),
        nl,write(' * * * * * * * * * * * * * * * * * * * * * * '), nl, expertiza.
 expertiza :- car_is(X), !, nl, write('Вероятно, выбранный автомобиль – '), write(X), write('.'), 
                             nl,clear_facts.
 expertiza :- nl, write('Извините, определить автомобиль не получается!'), clear_facts. 
vopros(X, Y):-write('вопрос – '),write(X),write(' '),
write(Y),write('? (да/нет) '),read(R),remember(X,Y,R).
positive(X,Y):-xpositive(X,Y),!.
positive(X,Y):-not(negative(X,Y)),!,vopros(X,Y).
negative(X,Y):-xnegative(X,Y),!.
remember(X,Y,'да'):-assertz(xpositive(X,Y)).
remember(X,Y,'нет'):-assertz(xnegative(X,Y)),fail.
clear_facts:-retract(xpositive(_,_)),fail.
clear_facts:-retract(xnegative(_,_)),fail.
car_is('Lada Vesta') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась позже 2015 года'),
                             positive('Модель ','производится на собственной платформе'),!. 
car_is('Lada Largus') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась позже 2015 года'),
                             positive('модель','производится на платформе Renault'),
							 positive('модель','предназначалась для грузоперевозок'),!. 
car_is('Lada XRay') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась позже 2015 года'),
                             positive('модель','производится на платформе Renault'),
							 negative('модель','предназначалась для грузоперевозок'),!. 
car_is('Lada Granta') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась позже 2011 года'),
                             positive('модель','имела вариант с автоматической коробкой передач'),!.  
car_is('Lada Priora') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась раньше 2011 года'),
                             positive('модель','имела вариант кузова лифтбек?'),!.
car_is('VAZ 2115') :-positive('это','дорожный автомобиль '),
                             positive('у него','передний привод'),
                             positive('модель','появилась раньше 2011 года'),
                             negative('модель','имела вариант кузова лифтбек?'),!.
car_is('GAZ Volga') :-positive('это','дорожный автомобиль '),
                             positive('у него','задний привод'),
                             positive('модель','позиционировалась как премиум автомобиль'),!.
car_is('VAZ 2105') :-positive('это','дорожный автомобиль '),
                             positive('у него','задний привод'),
                             negative('модель','позиционировалась как премиум автомобиль'),!.
car_is('Lada Niva Classic') :-positive('это','внедорожный автомобиль '),
                             positive('модель','имела трехдверный вариант'),!.
car_is('UAZ Patriot') :-positive('это','внедорожный автомобиль '),
                             positive('модель','имела отключаемый передний привод'),!.
car_is('Lada Niva Travel') :-positive('это','внедорожный автомобиль '),
                             negative('модель','имела отключаемый передний привод'),!.							 
 
