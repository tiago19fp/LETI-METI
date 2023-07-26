%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%     BASE CONHECIMENTO     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:- dynamic order/8.
:- dynamic delivery/5.

%%%%%%%%    DELIVERYS (driver,classification,orderID,date,vehicle)

delivery('Tiago', 5, ord1, "2021-12-05", bike).
delivery('Filipe', 4, ord2, "2021-12-05", car).
delivery('Joao', 5, ord3, "2021-12-05", car).
delivery('Ines', 4, ord4, "2021-12-05", motorcycle).
delivery('Daniel', 4, ord5, "2021-12-05", bike).
delivery('Filipe', 3, ord6, "2021-12-06", car).
delivery('Filipe', 5, ord7, "2021-12-06", motorcycle).
delivery('Tiago', 5, ord8, "2021-12-06", car).
delivery('Daniel', 5, ord9, "2021-12-06", car).
delivery('Ines', 5, ord10, "2021-12-06", bike).
delivery('Joao', 3, ord11, "2021-12-06", motorcycle).
delivery('Tiago', 4, ord12, "2021-12-07", car).
delivery('Daniel', 4, ord13, "2021-12-07", car).
delivery('Ines', 4, ord14, "2021-12-07", car).
delivery('Joao', 5, ord15, "2021-12-07", bike).
delivery('Ines', 5, ord16, "2021-12-07", car).
delivery('Joao', 3, ord17, "2021-12-07", motorcycle).
delivery('Filipe', 4, ord18, "2021-12-07", car).
delivery('Tiago', 5, ord19, "2021-12-07", bike).
delivery('Tiago', 5, ord20, "2021-12-07", car).


%%%%%%%%    ORDERS (orderID, clientID, weight,volume,state,price,orderDate,deliveryDate)

order(ord1, cli1, 2, 10, "Delivered", 5, "2021-12-02", "2021-12-05").
order(ord2, cli2, 8, 20, "Delivered", 10, "2021-12-02", "2021-12-05").
order(ord3, cli3, 5, 20, "Delivered", 10, "2021-12-02", "2021-12-06").
order(ord4, cli4, 10, 15, "Delivered", 20, "2021-12-02", "2021-12-06").
order(ord5, cli5, 2, 6, "Delivered", 5, "2021-12-02", "2021-12-06").
order(ord6, cli6, 16, 10, "Delivered", 20, "2021-12-03", "2021-12-06").
order(ord7, cli7, 22, 25, "Delivered", 25, "2021-12-03", "2021-12-06").
order(ord8, cli8, 6, 12, "Delivered", 10, "2021-12-03", "2021-12-06").
order(ord9, cli9, 12, 18, "Delivered", 25, "2021-12-03", "2021-12-06").
order(ord10, cli10, 42, 8, "Delivered", 30, "2021-12-03", "2021-12-06").
order(ord11, cli9, 36, 16, "Delivered", 35, "2021-12-03", "2021-12-07").
order(ord12, cli8, 16, 14, "Delivered", 25, "2021-12-04", "2021-12-07").
order(ord13, cli7, 8, 30, "Delivered", 5, "2021-12-04", "2021-12-07").
order(ord14, cli6, 20, 4, "Delivered", 10, "2021-12-04", "2021-12-07").
order(ord15, cli5, 12, 10, "Delivered", 15, "2021-12-04", "2021-12-07").
order(ord16, cli4, 8, 38, "Delivered", 20, "2021-12-04", "2021-12-07").
order(ord17, cli3, 36, 4, "Delivered", 40, "2021-12-04", "2021-12-07").
order(ord18, cli2, 2, 26, "Delivered", 10, "2021-12-04", "2021-12-08").
order(ord19, cli1, 44, 22, "Delivered", 50, "2021-12-04", "2021-12-08").
order(ord20, cli10, 12, 6, "Delivered", 10, "2021-12-04", "2021-12-08").

order(ord21, cli1, 2, 10, "To be delivered", 5, "2021-12-05", "2021-12-08").
order(ord22, cli2, 8, 20, "To be delivered", 10, "2021-12-05", "2021-12-08").
order(ord23, cli3, 5, 20, "To be delivered", 10, "2021-12-05", "2021-12-08").
order(ord24, cli4, 10, 15, "To be delivered", 20, "2021-12-05", "2021-12-09").
order(ord25, cli5, 2, 6, "To be delivered", 5, "2021-12-05", "2021-12-09").
order(ord26, cli6, 16, 10, "To be delivered", 20, "2021-12-05", "2021-12-09").
order(ord27, cli7, 22, 25, "To be delivered", 25, "2021-12-06", "2021-12-09").
order(ord28, cli8, 6, 12, "To be delivered", 10, "2021-12-06", "2021-12-09").
order(ord29, cli9, 12, 18, "To be delivered", 25, "2021-12-06", "2021-12-09").
order(ord30, cli10, 42, 8, "To be delivered", 30, "2021-12-06", "2021-12-09").
order(ord31, cli9, 36, 16, "Delivering", 35, "2021-12-06", "2021-12-09").
order(ord32, cli8, 16, 14, "Delivering", 25, "2021-12-06", "2021-12-10").
order(ord33, cli7, 8, 30, "Delivering", 5, "2021-12-07", "2021-12-10").
order(ord34, cli6, 20, 4, "Delivering", 10, "2021-12-07", "2021-12-10").
order(ord35, cli5, 12, 10, "Delivering", 15, "2021-12-07", "2021-12-10").
order(ord36, cli4, 8, 38, "Delivering", 20, "2021-12-07", "2021-12-10").
order(ord37, cli3, 36, 4, "Delivering", 40, "2021-12-07", "2021-12-10").
order(ord38, cli2, 2, 26, "Delivering", 10, "2021-12-07", "2021-12-10").
order(ord39, cli1, 44, 22, "Delivering", 50, "2021-12-07", "2021-12-10").
order(ord40, cli10, 12, 6, "Delivering", 10, "2021-12-07", "2021-12-10").