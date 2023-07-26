%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%   INCLUDES

:- style_check(-singleton).
:- style_check(-discontiguous).

:- use_module(library(lists)).

:- include('knowledge.pl').
:- include('orders.pl').

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%	DFS

dfs(Orig,Dest,Cam):-
	dfs2(Orig,Dest,[Orig],Cam).

dfs2(Dest,Dest,LA,Cam):-
	reverse(LA,Cam).

dfs2(Act,Dest,LA,Cam):-
	connect(Act,X),
	\+ member(X,LA),
	dfs2(X,Dest,[X|LA],Cam).

%%%%%% GULOSA

bestfs(Orig,Dest,Cam,Custo):-
	bestfs2(Dest,(0,[Orig]),Cam,Custo).

bestfs2(Dest,(Custo,[Dest|T]),Cam,Custo):-
	!,
	reverse([Dest|T],Cam).

bestfs2(Dest,(Ca,LA),Cam,Custo):-
	LA=[Act|_],
	findall((EstX,CaX,[X|LA]),
	(connect(Act,X,CX),\+ member(X,LA),
	estimativa(X,Dest,EstX),
	CaX is Ca+CX),Novos),

	sort(Novos,NovosOrd),
	NovosOrd = [(_,CM,Melhor)|_],
	bestfs2(Dest,(CM,Melhor),Cam,Custo).

%%%%%% A ESTRELA

aStar(Orig,Dest,Cam,Custo):-
	aStar2(Dest,[(_,0,[Orig])],Cam,Custo).

aStar2(Dest,[(_,Custo,[Dest|T])|_],Cam,Custo):-
	reverse([Dest|T],Cam).
	aStar2(Dest,[(_,Ca,LA)|Outros],Cam,Custo):-
	LA=[Act|_],
	findall((CEX,CaX,[X|LA]),
	(Dest\==Act,connect(Act,X,CustoX),\+ member(X,LA),
	CaX is CustoX + Ca, estimativa(X,Dest,EstX),
	CEX is CaX +EstX),Novos),
	append(Outros,Novos,Todos),
	sort(Todos,TodosOrd),
	aStar2(Dest,TodosOrd,Cam,Custo).
	
		estimativa(Nodo1,Nodo2,Estimativa):-
	city(Nodo1,X1,Y1),
	city(Nodo2,X2,Y2),
	Estimativa is sqrt((X1-X2)^2+(Y1-Y2)^2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%% Method 1 - Client registation

method1(ClientID,ClientName,City) :- 
    assertz(client(ClientID,ClientName,City)).

%%%%%%%%%%%%%%%%%% Method 2 - Make an order

method2(OrderID,ClientID,Weight,Volume,Start_location,Destination,Deadline,OrderType) :- 
    add_order(OrderID,ClientID,Weight,Volume,Start_location,Destination,Deadline,OrderType).

%%%%%%%%%%%%%%%%%% Method 3 - Complete Order

method3(OrderID, Classification, Date) :- 
    findall(Driver, driver(Driver,'Unavailable',Lista), ListDrivers),
    [H|T] = ListDrivers,
    retract(driver(H,_,L)),
    asserta(driver(H,'Available',L)),
    retract(order(OrderID,ClientID,Weight,Volume,State,Price,OrderDate,DeliveryDate)),
    asserta(order(OrderID,ClientID,Weight,Volume,"Delivered",Price,OrderDate,DeliveryDate)),
    assertz(delivery(H,Classification,OrderID,Date,car)).
    
%%%%%%%%%%%%%%%%%% Method 4 - Check Order State


method4a(OrderID,State) :-
    order(OrderID,_,_,_,State,_,_,_).

method4b(OrderID,Cost) :-
    order(OrderID,_,_,_,_,Cost,_,_).

method4c(OrderID,ClientID) :-
    order(OrderID,ClientID,_,_,_,_,_,_).

    
%%%%%%%%%%%%%%%%%% Method 5 - Driver who used the most ecologic vehicle (bike)

method5(Driver) :-
    getDriversBike(Drivers),
    sort(Drivers, Uniq),
    findall([Freq,X],(member(X,Uniq),include(=(X),Drivers,Y),length(Y,Freq)),Freqs),
    sort(Freqs,SFreqs),
    last(SFreqs,[Freq, Driver]).

getDriversBike(Drivers) :- 
    findall(DriverName,(delivery(DriverName, _, _, _, bike)),Drivers).

%%%%%%%%%%%%%%%%%% Method 6 - Driver who delivered certain order

method6([],[]).
method6([OrderID|Orders], Drivers) :-
    orderDelivered(Driver,OrderID),
    method6(Orders,Y),
    append([[Driver],Y],Drivers).

orderDelivered(DriverName,OrderID) :-
    delivery(DriverName,_,OrderID,_,_).

%%%%%%%%%%%%%%%%%% Method 7 - Driver who delivered to a list of clients


method7(Driver,OrderedClients) :-
    findall(ClientName,(delivery(Driver, _, OrderID, _, _),order(OrderID, ClientID, _, _, _, _, _, _),client(ClientID,ClientName,_)),Clients),
    removeDupeClients(Clients,UniqClients),
    sort(UniqClients,OrderedClients).

removeDupeClients([],[]).
removeDupeClients([H|T], Clients) :- member(H,T), removeDupeClients(T,Clients).
removeDupeClients([H|T], [H|T1]) :- \+member(H,T), removeDupeClients(T,T1).

%%%%%%%%%%%%%%%%%% Method 8 - Money earned in a day by Eco Delivery (if bike = 0.5, car = 1.25, motorcycle = 1)

method8(Date,Total) :-
    findall(Final,
            ((delivery(_,_,OrderID,Date,Vehicle),order(OrderID,_,_,_,_,Price,_,EstimatedDelivery)),
            parse_time(EstimatedDelivery,Estimate),
            parse_time(Date,DeliveryDate),
            (((Vehicle = bike),DeliveryDate =< Estimate, Final is Price * 0.5);
            ((Vehicle = car),DeliveryDate =< Estimate, Final is Price * 1.25);
            ((Vehicle = motorcycle),DeliveryDate =< Estimate, Final is Price * 1);
            ((Vehicle = bike),DeliveryDate > Estimate, Final is Price * 0.5 * 0.8);
            ((Vehicle = car),DeliveryDate > Estimate, Final is Price * 1.25 * 0.8);
            ((Vehicle = motorcycle),DeliveryDate > Estimate, Final is Price * 1 * 0.8)))
            ,Value),
    sum_list(Value,Total).

%%%%%%%%%%%%%%%%%% Method 9 - City with most deliveries by Eco Delivery

method9(City) :-
    citysDelivered(Citys),
    sort(Citys, Uniq),
    findall([Freq, X], (member(X, Uniq),include( =(X), Citys, Y),length(Y, Freq)),Freqs),
    sort(Freqs, SFreqs),
    last(SFreqs,[Freq,City]).

citysDelivered(Citys) :-
    findall(City,(client(ClientID, _, City),order(OrderID, ClientID, _, _, _, _, _, _),delivery(_, _, OrderID, _, _)),Citys).

%%%%%%%%%%%%%%%%%% Method 10 - Driver with most deliveries by Eco Delivery

method10(Driver) :-
    driverDeliveries(Drivers),
    sort(Drivers, Uniq),
    findall([Freq, X], (member(X, Uniq),include( =(X), Drivers, Y),length(Y, Freq)),Freqs),
    sort(Freqs, SFreqs),
    last(SFreqs,[Freq,Driver]).

driverDeliveries(Drivers) :-
    findall(Driver,(delivery(Driver, _, OrderID, _, _)),Drivers).

%%%%%%%%%%%%%%%%%% Method 11 - Driver analysis

method11(Driver,Media) :-
    driverRatings(Driver,Rating),
    medium(Rating,Media).

driverRatings(Driver,Rating) :-
    findall(Rate,delivery(Driver,Rate,_,_,_),Rating).

medium(Lista,Media) :-
    length(Lista,X), sum(Lista,Soma),
    Media is Soma/X.

%%%%%%%%%%%%%%%%%% Method 12 - Orders delivered

method12(Count) :-
    findall(X, order(_,_,_,_,"Delivered",_,_,_), List), length(List,Count).

%%%%%%%%%%%%%%%%%% Method 13 - Orders to be delivered and not delivered

method13a(TD) :-
    findall(X, order(_,_,_,_,"To be delivered",_,_,_), List), length(List,TD).

method13b(ND) :-
    findall(X, order(_,_,_,_,"Delivering",_,_,_), List), length(List,ND).


%%%%%%%%%%%%%%%%% Method 14 - Number of orders between 2 dates

method14(Init,Final,Number):-
    filterTime(Init,Final,Orders),
    length(Orders,Number).

filterTime(Init,Final,Orders):-
    findall(Delivery,filt(Init,Final,Delivery),Orders).

filt(Init,Final,Delivery):-
    delivery(_,_,_,X,_),
    Delivery = delivery(_,_,_,X,_),
    parse_time(Init,Ini),
    parse_time(Final,Fin),
    parse_time(X,Y),
    Y >= Ini,
    Y =< Fin.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%    Functions   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

leng([], 0).
leng([H|T], X) :- length(T, X1), X is X1 + 1.

sum([],0).
sum([Y|List],Sum) :-
    sum(List,Sum1),
    Sum = Y + Sum1.

sum_list2([], 0).
sum_list2([H|T], Sum) :-
   sum_list2(T, Rest),
   Sum is H + Rest.

%%%%%%%%%   LIGAÇÃO BIDIRECIONAL %%%%%%%%
connect(X,Y,C):-distance(X,Y,C);distance(Y,X,C).	

%%%%%%%%%%%%    ADD ORDER     %%%%%%%%%%%%

add_order(OrderID, ClientID, Weight, Volume, Start_location, Destination, Deadline,OrderType):-
    aStar('Centro',Start_location,Caminho1,Distance1),
    aStar(Start_location,Destination,Caminho2,Distance2),
    Distance is (Distance1 + Distance2),
    choosevehicle(Weight,Distance,Volume,Vehicle),
    calculate_price(Distance, Vehicle, Deadline, Price),
    selectDriver(OrderID),
    assertz(order(OrderID,ClientID,Weight,Volume,'Delivering',Price,"2021-12-10",Deadline)) -> true.

%%%%%%%%%%%%% Choose vehicle %%%%%%%%%%%%%

choosevehicle(Weight,Distance,Volume,Vehicle):-
    vehicle(bike,_,_,MaxWeight),
    Weight =< MaxWeight,Distance =< 20,Volume =< 5, Vehicle=bike;
    vehicle(motorcycle,_,_,MaxWeight),
    Weight =< MaxWeight,Distance =< 50,Volume =< 10, Vehicle=motorcycle;
    vehicle(car,_,_,MaxWeight),
    Weight =< MaxWeight, Vehicle=car.

%%%%%%%%%%%%%  calculate price  %%%%%%%%%%%%%

calculate_price(Distance, Vehicle, Deadline, Price):-
    Price is (Distance*(0.5)).

%%%%%%%%%%%%%%% select driver %%%%%%%%%%%%%%%

selectDriver(OrderID) :- 
    findall(Driver, driver(Driver,'Available',Lista), ListDrivers),
    [H|T] = ListDrivers,
    findall(Orders, driver(H,_,Orders), Lista),
    nth0(0,Lista,Encomendas),
    add_tail(Encomendas,OrderID,L),
    retract(driver(H,_,_)),
    asserta(driver(H,'Unavailable',L)) -> true.

add_tail([],X,[X]).
add_tail([H|T],X,[H|L]):-add_tail(T,X,L).
