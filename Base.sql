#
# TABLE STRUCTURE FOR: Aerolinea
#

create database Vuelos;
use Vuelos;

DROP TABLE IF EXISTS `Aerolinea`;

CREATE TABLE `Aerolinea` (
  `idAereolinea` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `hub` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`idAereolinea`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `Aerolinea` (`idAereolinea`, `nombre`, `hub`) VALUES (1, 'American Airlines', 'Ab eaque nobis magnam harum.');
INSERT INTO `Aerolinea` (`idAereolinea`, `nombre`, `hub`) VALUES (2, ' Qatar Airways', 'Magnam omnis accusamus a aspernatur maiores.');
INSERT INTO `Aerolinea` (`idAereolinea`, `nombre`, `hub`) VALUES (3, 'Spirit', 'Quo blanditiis aut ea quos.');


#
# TABLE STRUCTURE FOR: Asiento
#

DROP TABLE IF EXISTS `Asiento`;

CREATE TABLE `Asiento` (
  `idAsiento` int(11) NOT NULL AUTO_INCREMENT,
  `tipo` varchar(5) ,
  `costo` int(11) DEFAULT NULL,
  `fila` int(11) DEFAULT NULL,
  `columna` int(11) DEFAULT NULL,
  `Vuelo_idVuelo` int(11) NOT NULL,
  `Reserva_idReserva` int(11) NOT NULL,
  PRIMARY KEY (`idAsiento`)
) ;
Insert into Asiento() values(1,'BL',1094,0,0,3,0); 
Insert into Asiento() values(2,'BL',177,0,1,3,0) ;
Insert into Asiento() values(3,'BO',966,0,2,3,5); 
Insert into Asiento() values(4,'BL',1543,0,3,3,0) ;
Insert into Asiento() values(5,'SL',240,1,0,3,0) ;
Insert into Asiento() values(6,'SO',765,1,1,3,1) ;
Insert into Asiento() values(7,'SL',885,1,2,3,0) ;
Insert into Asiento() values(8,'SL',811,1,3,3,0) ;
Insert into Asiento() values(9,'SL',497,2,0,3,0) ;
Insert into Asiento() values(10,'SO',1112,2,1,3,4) ;
Insert into Asiento() values(11,'SO',1572,2,2,3,9) ;
Insert into Asiento() values(12,'SL',1404,2,3,3,0) ;
Insert into Asiento() values(13,'EL',1867,3,0,3,0) ;
Insert into Asiento() values(14,'EO',389,3,1,3,5) ;
Insert into Asiento() values(15,'EL',161,3,2,3,0) ;
Insert into Asiento() values(16,'EO',1983,3,3,3,6) ;
Insert into Asiento() values(17,'EL',1456,4,0,3,0) ;
Insert into Asiento() values(18,'EL',1031,4,1,3,0) ;
Insert into Asiento() values(19,'EO',884,4,2,3,10);
Insert into Asiento() values(20,'EL',1444,4,3,3,0) ;

#
# TABLE STRUCTURE FOR: Avion
#

DROP TABLE IF EXISTS `Avion`;

CREATE TABLE `Avion` (
  `idAvion` int(11) NOT NULL AUTO_INCREMENT,
  `matricula` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `modelo` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `anno` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `Aereolinea_idAereolinea` int(11) NOT NULL,
  PRIMARY KEY (`idAvion`,`Aereolinea_idAereolinea`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (1, '766863', 'Boeing 721', '1995', 3);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (2, '448513', 'Boeing 747', '2011', 3);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (3, '112180', ' MAX 737', '2008', 2);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (4, '452712', 'Boeing 721', '2014', 1);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (5, '444966', 'Boeing 747 ', '2018', 2);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (6, '208974', 'Boeing 721', '1992', 3);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (7, '272140', 'Boeing 747 ', '2012', 2);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (8, '713118', 'Boeing 727', '2006', 1);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (9, '419862', 'Boeing 747', '1996', 3);
INSERT INTO `Avion` (`idAvion`, `matricula`, `modelo`, `anno`, `Aereolinea_idAereolinea`) VALUES (10, '374660', 'Boeing 721', '2003', 1);


#
# TABLE STRUCTURE FOR: Pasajero
#

DROP TABLE IF EXISTS `Pasajero`;

CREATE TABLE `Pasajero` (
  `idPasajero` int(11) NOT NULL AUTO_INCREMENT,
  `pasaporte` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `nombre` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `apellido1` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `apellido2` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `sexo` varchar(2) COLLATE utf8_unicode_ci DEFAULT NULL,
  `nacimiento` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`idPasajero`)
) ENGINE=InnoDB AUTO_INCREMENT=26 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (1, '2385502', 'Arnoldo', 'Greenholt', 'Schuppe', 'M', '1978-10-02');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (2, '1882314', 'Deonte', 'McClure', 'Heller', 'H', '2020-02-24');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (3, '2344905', 'Araceli', 'Weimann', 'Steuber', 'H', '1991-12-21');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (4, '4519276', 'Felicita', 'Miller', 'Schulist', 'M', '1976-08-11');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (5, '1787145', 'Hanna', 'Walter', 'Haley', 'H', '2010-10-12');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (6, '4509190', 'Marcelo', 'Wolff', 'Torphy', 'M', '1997-05-07');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (7, '3648793', 'Percy', 'Ruecker', 'Luettgen', 'H', '1980-07-28');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (8, '4103763', 'Keeley', 'Kemmer', 'Brakus', 'M', '2010-05-22');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (9, '4772253', 'Adella', 'Champlin', 'Fadel', 'M', '2019-04-08');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (10, '1950026', 'Elenora', 'Klocko', 'Nolan', 'M', '1993-12-01');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (11, '3633067', 'Dawn', 'Pacocha', 'Tillman', 'M', '2008-04-14');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (12, '1806979', 'Catharine', 'Raynor', 'Maggio', 'M', '2020-03-03');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (13, '1270257', 'Dave', 'Bins', 'Kuphal', 'M', '2001-09-28');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (14, '1928560', 'Junior', 'Wunsch', 'Haag', 'M', '2019-01-20');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (15, '2830994', 'Rhiannon', 'Cole', 'Cartwright', 'H', '2005-05-24');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (16, '2916149', 'Wyman', 'Kassulke', 'Brown', 'H', '2000-11-08');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (17, '593896', 'Samantha', 'Bahringer', 'Krajcik', 'H', '1994-03-19');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (18, '967140', 'Reece', 'Prosacco', 'Sawayn', 'H', '1981-07-06');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (19, '589194', 'Daphnee', 'Douglas', 'Von', 'M', '2002-07-04');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (20, '1745740', 'Meghan', 'Stoltenberg', 'Crist', 'M', '2005-12-19');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (21, '2843417', 'Athena', 'Schuppe', 'Larson', 'H', '2004-05-14');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (22, '943272', 'Wendy', 'Lowe', 'Torphy', 'H', '2006-01-03');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (23, '4609099', 'Jacinthe', 'Ledner', 'Corkery', 'H', '1970-09-18');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (24, '4561460', 'Adolf', 'Ratke', 'Abernathy', 'M', '2001-06-14');
INSERT INTO `Pasajero` (`idPasajero`, `pasaporte`, `nombre`, `apellido1`, `apellido2`, `sexo`, `nacimiento`) VALUES (25, '1051441', 'Amely', 'Runolfsdottir', 'Kulas', 'H', '2007-12-05');


#
# TABLE STRUCTURE FOR: Reserva
#

DROP TABLE IF EXISTS `Reserva`;

CREATE TABLE `Reserva` (
  `idReserva` int(11) NOT NULL AUTO_INCREMENT,
  `fecha` datetime DEFAULT NULL,
  `Pasajero_idPasajero` int(11) NOT NULL,
  PRIMARY KEY (`idReserva`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
delete from Reserva;
alter table Reserva add column (codigo varchar(45));
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (1, '1985-11-07 20:52:45', 3,'jdsflkaS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (2, '1997-05-12 07:35:55', 9,'1As342aF');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (3, '2017-01-06 09:49:38', 6,'jdsflkaS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (4, '2010-02-15 04:13:14', 3,'jdsflkaS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (5, '1979-05-04 13:48:56', 4,'jdsflkaA');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (6, '1970-10-11 17:52:18', 7,'jds342aA');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (7, '1989-02-28 20:47:47', 5,'jds342aS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (8, '1973-05-02 23:32:47', 1,'jds342aS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (9, '2006-11-13 11:10:03', 8,'jdsflkaS');
INSERT INTO `Reserva` (`idReserva`, `fecha`, `Pasajero_idPasajero`, `codigo`) VALUES (10, '2017-03-03 16:54:58', 10,'ASDSAAW');


#
# TABLE STRUCTURE FOR: Vuelo
#

DROP TABLE IF EXISTS `Vuelo`;

CREATE TABLE `Vuelo` (
  `idVuelo` int(11) NOT NULL AUTO_INCREMENT,
  `codigo` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `origen` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `destino` varchar(45) COLLATE utf8_unicode_ci DEFAULT NULL,
  `salida` datetime DEFAULT NULL,
  `llegada` datetime DEFAULT NULL,
  `Avion_idAvion` int(11) NOT NULL,
  PRIMARY KEY (`idVuelo`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

INSERT INTO `Vuelo` (`idVuelo`, `codigo`, `origen`, `destino`, `salida`, `llegada`, `Avion_idAvion`) VALUES (1, '55507', 'Port Rodolfoberg', 'Towneburgh', '2009-02-28 05:00:34', '1977-03-09 06:55:23', 4);
INSERT INTO `Vuelo` (`idVuelo`, `codigo`, `origen`, `destino`, `salida`, `llegada`, `Avion_idAvion`) VALUES (2, '86695', 'Port Lueland', 'Cummerataborough', '2005-12-08 11:35:24', '2002-04-09 09:50:58', 4);
INSERT INTO `Vuelo` (`idVuelo`, `codigo`, `origen`, `destino`, `salida`, `llegada`, `Avion_idAvion`) VALUES (3, '95475', 'Lake Aliya', 'Medhurstland', '2009-12-06 05:12:06', '1999-10-09 13:32:41', 2);
INSERT INTO `Vuelo` (`idVuelo`, `codigo`, `origen`, `destino`, `salida`, `llegada`, `Avion_idAvion`) VALUES (4, '58391', 'Smithamfurt', 'Lake Braxton', '1997-07-20 09:53:09', '1990-06-13 10:31:40', 1);
INSERT INTO `Vuelo` (`idVuelo`, `codigo`, `origen`, `destino`, `salida`, `llegada`, `Avion_idAvion`) VALUES (5, '33382', 'Bradtkeville', 'New Reynaton', '1993-03-01 02:48:32', '2020-08-28 08:31:56', 6);


