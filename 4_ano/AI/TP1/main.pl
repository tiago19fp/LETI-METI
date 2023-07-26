%%%					            	%%%
%%%		Trabalho Prático 1 PROLOG	%%%
%%%
%%%		Rui Freitas 	pg47639		%%%
%%%		Tiago Ferreira  pg47692		%%%
%%%		Pedro Sampaio	a79668		%%%
%%%		Hugo Reinolds	a83924		%%%
%%%					            	%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% INCLUDES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:-include('methods.pl'). 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% MENU %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

menu() :- nl,
    write('------------------------------------------------------------------------------------------------------------------------------'), nl, nl,
	write('-------------------------------------------------------  ECO DELIVERY  -------------------------------------------------------'), nl, nl,
	write('------------------------------------------------------------------------------------------------------------------------------'), nl, nl,
	write('-    1 - Registar um cliente.'), nl,
	write('-    2 - Efetuar uma encomenda.'), nl,
	write('-    3 - Completar uma encomenda.'), nl,
	write('-    4 - Ver custo e estado de uma encomenda.'), nl,
	write('-    5 - Estafeta que utilizou mais vezes o meio de transporte mais ecologico(bicicleta).'), nl,
	write('-    6 - Estafeta que entregou determinada encomenda.'), nl,
	write('-    7 - Identificar os Clientes servidos por um determinado Estafeta.'), nl,
	write('-    8 - Calcular o Valor Faturado pela Eco Delivery num determinado dia.'), nl,
	write('-    9 - Identificar qual o concelho do distrito de Braga com maior volume de encomendas por parte da Eco Delivery.'), nl,
    write('-    10 - Identificar qual o estafeta com maior volume de encomendas por parte da Eco Delivery.'), nl,
	write('-    11 - Calcular a Classificacao Media de um determinado estafeta.'), nl,
	write('-    12 - Numero de Encomendas Entregues.'), nl,
	write('-    13 - Numero de Encomendas por entregar e encomendas a ser entregues.'), nl,
	write('-    14 - Numero de entregas por parte da Eco Delivery num determinado periodo.'), nl,
	write('-    15 - Sair.'), nl, nl,
	write('------------------------------------------------------------------------------------------------------------------------------'), nl, nl,
    write('------------------------------------------------------------------------------------------------------------------------------'), nl, nl,
	read(Choice), goto_method(Choice), menu.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% METODOS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	
goto_method(1) :- write('ID: '), read(ClientID), write('Nome : '), read(ClientName), write('Cidade: '), read(City),
	method1(ClientID,ClientName,City), write('Cliente registado '),writeln('.').

goto_method(2) :- write('ID Encomenda : '), read(OrderID), write('ID Cliente : '), read(ClientID), write('Peso : '), read(Weight), write('Volume : '), read(Volume),
	write('Concelho onde se encontra : '), read(Start_location), write('Concelho para onde quer enviar : '), read(Destination), write('Prazo :'), read(Deadline), write('Tipo (0-Food,1-Package)'), read(OrderType), nl,
	method2(OrderID,ClientID,Weight,Volume,Start_location,Destination,Deadline,OrderType), write('Encomenda realizada '),writeln('.').

goto_method(3) :- write('Qual o ID da encomenda que quer completar? '), read(OrderID), write('Classificacao? '), read(Classification), write('Data de entrega? '), read(Date),nl,
	method3(OrderID,Classification,Date), write('Encomenda registada '),writeln('.').

goto_method(4) :- write('Encomenda que deseja analisar: '), read(OrderID),
	method4a(OrderID,State), method4b(OrderID,Cost), method4c(OrderID,ClientID),
	write('O estado da encomenda : '), write(OrderID),write(' realizada pelo cliente :'),write(ClientID), write(' encontra se '), write(State), write(' e o seu custo foi de '), write(Cost), write(' euros').

goto_method(5) :- method5(Driver),
	write('O Estafeta que utilizou mais vezes o meio de transporte mais ecologico foi o '),  write(Driver), writeln('.').

goto_method(6) :- write('Indique qual/quais encomenda/as pretende analisar([ord1,ord2,...]) : '), read(OrderID),
	method6(OrderID, DriverName), write('O Estafeta que entregou a/as encomenda/as '), write(OrderID), write(' foi o/a '), write(DriverName), writeln('.').

goto_method(7) :- write('Indique qual o Estafeta que pretende analisar : '), read(Driver),
	method7(Driver,Clients), write('Os Clientes servidos por este Estafeta foram : '), write(Clients), writeln('.').

goto_method(8) :- write('Indique qual o dia ("YYYY-MM-DD") que pretende analisar: '), read(Date),
	method8(Date,Total), write('O valor faturado no dia '), write(Date), write(' foi de '), write(Total), write(' euros'), writeln('.').

goto_method(9) :- method9(City),
	write('O concelho com maior volume de entregas e : '), write(City), writeln('.').

goto_method(10) :- method10(Driver),
	write('O estafeta com maior volume de entregas e : '), write(Driver), writeln('.').

goto_method(11) :- write('Indique qual o Estafeta que pretende analisar : '), read(Driver),
	method11(Driver,Media), write('A Classificacao do Estafeta '), write(Driver), write(' e '), write(Media), writeln('.').

goto_method(12) :- method12(N),
	write('O numero de encomendas entregues pela Eco Delivery : '), write(N).

goto_method(13) :- method13a(TD), method13b(ND),
	write('O numero de encomendas nao entregues pela Eco Delivery : '), write(TD), nl,
	write('O numero de encomendas a ser entregues pela Eco Delivery : '), write(ND).
	
goto_method(14) :-  write('Data de inicio : '), read(Init), write('Data final : '), read(Fin), 
	method14(Init,Fin,Number), write('O numero de entregas por parte da Eco Delivery entre: '), write(Init),
	write(' e '), write(Fin), write(' foi de :'), write(Number).

goto_method(15) :- nl, halt.

goto_method(_) :- writeln("Escolha uma opcao valida!").