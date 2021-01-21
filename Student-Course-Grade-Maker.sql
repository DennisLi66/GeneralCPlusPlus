drop database if exists gradeHandler;
create database gradeHandler;
use gradeHandler;

-- 3 tables at least Student, Grades, Course

-- Create Tables Section
create table course(
cNum int NOT NULL PRIMARY KEY,
title varchar(255) NOT NULL,
profName varchar(255)
);
create table student(
idNum int NOT NULL AUTO_INCREMENT PRIMARY KEY,
fName varchar(255) NOT NULL,
lName varchar(255) Not Null
);
create table grade(
id int NOT NULL auto_increment primary key,
sid int NOT NULL,
cNum int NOT NULL,
grade varchar(20),
gquarter varchar(20) not null,
gyear int not null
);

-- Sample Fill-ins
insert into course (cNum,title,profName) VALUES 
(100101,"Biology 101","Samuel Smith"),
(200101,"Physics 101","Peter Post"),
(100222,"The Study of Plants That Are Not Green","Molly Masters"),
(100223,"The Study of Plants That Are Green","Molly Masters"),
(300701,"Computers From Before 1972","Andrew Applegate"),
(300702,"Computers From The Future","Time Traveler"),
(200202,"Physics Lab",NULL),
(400001,"Prehistoric Art","Carl Caveman"),
(400002,"Blue Period","Vicky Vaughn"),
(300005,"MYSQL For Me","Andrew Applegate");

insert into student(fName,lName) VALUES 
("Carl","Chase"),
("Mason","Miles"),
("Charles","Copperfield"),
("Larry","Li"),
("Larry","Lee"),
("Abraham","Andrews"),
("Kyle","Kyung"),
("Beth","Bates"),
("Dylan","Danger"),
("Edith","Evans");

insert into grade(sid,cNum,grade,gquarter,gyear) VALUES 
(1,100101,"B+","Spring",2012),
(1,200101,"C+","Spring",2012),
(2,100101,"B-","Spring",2012),
(2,200101,"C","Spring",2012),
(3,300701,"A-","Fall",2013),
(3,300702,"B","Fall",2013),
(3,400001,"B+","Fall",2013),
(1,400001,"D","Fall",2013),
(1,400002,"C","Fall",2013),
(4,300701,"A","Fall",2013),
(4,300702,"B-","Winter",2013)
