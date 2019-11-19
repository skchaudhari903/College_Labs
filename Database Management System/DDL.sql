CREATE DATABASE student;

USE student;

CREATE TABLE student_info(ID INT(5) NOT NULL PRIMARY KEY AUTO_INCREMENT, NAME VARCHAR(20) NOT NULL, CITY VARCHAR(20) NOT NULL, ADMISSION_DATE DATE NOT NULL);

INSERT INTO student_info VALUES("Alexis", "Mumbai", "2018-05-12"),("Cameron", "Pune", "2017-02-12"),("Brenden", "Delhi", "2015-12-03"),("Olivia", "Banglore", "2018-01-27"),("Brynne", "Hydrabad", "2018-05-12");
 
SELECT * FROM student_info;

SHOW COLUMNS FROM student_info;

ALTER TABLE student_info ADD MARKS INT(5);

UPDATE student_info set MARKS=10 WHERE ID=1;
UPDATE student_info set MARKS=30 WHERE ID=2;
UPDATE student_info set MARKS=50 WHERE ID=3;

ALTER TABLE student_info RENAME TO STUDENT_INFORMATION;

UPDATE STUDENT_INFORMATION SET ADMISSION_DATE=NOW() WHERE ID=5;

SELECT * FROM STUDENT_INFORMATION;

SELECT * FROM STUDENT_INFORMATION WHERE ADMISSION_DATE LIKE '%12';

SELECT * FROM STUDENT_INFORMATION ORDER BY NAME ASC;

SELECT * FROM STUDENT_INFORMATION ORDER BY NAME DESC;

SELECT * FROM STUDENT_INFORMATION WHERE MARKS IS NULL;

SELECT * FROM STUDENT_INFORMATION WHERE MARKS IS NOT NULL;