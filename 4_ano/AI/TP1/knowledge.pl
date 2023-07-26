%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     BASE CONHECIMENTO     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- dynamic client/3.
:- dynamic driver/3.
:- dynamic vehicle/4.

%%%	    CLIENTS (ClientID,ClientName,City)
client(cli1,'Rui','Fafe').
client(cli2,'Pedro','Braga').
client(cli3,'Hugo','Vila Verde').
client(cli4,'Marco','Barcelos').
client(cli5,'Ana','Esposende').
client(cli6,'Maria','Amares').
client(cli7,'Paulo','Guimaraes').
client(cli8,'David','Vizela').
client(cli9,'Joana','Terras de Bouro').
client(cli10,'Afonso','Fafe').

%%%     DRIVERS (driver,state,[order])
driver('Tiago','Available',[ord1,ord8,ord12,ord19,ord20,ord21,ord34,ord35]).
driver('Filipe','Unavailable',[ord2,ord6,ord7,ord18,ord23,ord29,ord30,ord39]).
driver('Joao','Unavailable',[ord3,ord11,ord15,ord17,ord22,ord28,ord36,ord37]).
driver('Ines','Available',[ord4,ord10,ord14,ord16,ord26,ord27,ord33,ord38]).
driver('Daniel','Available',[ord5,ord9,ord13,ord24,ord25,ord31,ord32,ord40]).

%%%	    MASCULINE
men('Rui').
men('Tiago').
men('Pedro').
men('Hugo').
men('Filipe').
men('Marco').
men('Joao').
men('Paulo').
men('David').
men('Daniel').

%%%	    FEMININE
woman('Ana').
woman('Maria').
woman('Ines').
woman('Joana').

%%% 	CITY(city,x,y)
city('Centro',0,0).
city('Esposende',5,30).
city('Vila Verde',40,50).
city('Barcelos',20,30).
city('Vila Nova Famalicao',25,10).
city('Terras de Bouro',65,60).
city('Amares',58,40).
city('Vieira do Minho',90,40).
city('Povoa de Lanhoso',68,25).
city('Braga',40,20).
city('Guimaraes',58,10).
city('Vizela',58,2).
city('Cabeceiras de Basto',105,20).
city('Fafe',73,10).
city('Celorico de Basto',105,10).


%%% 	DISTANCES
%%% 	distance(city1,city2,cost)
distance('Centro','Esposende',2).
distance('Esposende','Barcelos',15).
distance('Barcelos','Braga',22).
distance('Barcelos','Vila Verde',26).
distance('Barcelos','Vila Nova Famalicao',20).
distance('Vila Nova Famalicao','Braga',22).
distance('Vila Nova Famalicao','Guimaraes',33).
distance('Vila Verde','Braga',16).
distance('Vila Verde','Amares',10).
distance('Vila Verde','Terras de Bouro',18).
distance('Amares','Terras de Bouro',22).
distance('Amares','Povoa de Lanhoso',14).
distance('Braga','Povoa de Lanhoso',19).
distance('Povoa de Lanhoso','Vieira do Minho',18).
distance('Vieira do Minho','Terras de Bouro',32).
distance('Vieira do Minho','Cabeceiras de Basto',29).
distance('Fafe','Povoa de Lanhoso',22).
distance('Fafe','Vieira do Minho',22).
distance('Fafe','Guimaraes',15).
distance('Fafe','Cabeceiras de Basto',30).
distance('Guimaraes','Vizela',11).
distance('Guimaraes','Povoa de Lanhoso',21).
distance('Celorico de Basto','Fafe',25).
distance('Celorico de Basto','Cabeceiras de Basto',22).

%%%		CONNECTED CITYS
conectado(X, Y, V) :- distance(X, Y, V).
conectado(X, Y, V) :- distance(Y, X, V).

%%%     VEHICLE (type,ecologyLevel,avgVelocity,maxWeight)
vehicle(car,1,25,100).
vehicle(bike,3,10,5).
vehicle(motorcycle,2,35,20).
