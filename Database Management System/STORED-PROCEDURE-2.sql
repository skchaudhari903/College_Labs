CREATE TABLE STUDENT_MARKS(ROLL INT, NAME VARCHAR(20), TOTAL_MARKS INT);

CREATE TABLE RESULT(ROLL INT, NAME VARCHAR(20), CLASS VARCHAR(20));

DELIMITER //

CREATE PROCEDURE GRADE(IN ROLL INT, IN NAME VARCHAR(20), IN MARKS INT)
BEGIN
DECLARE CLASS VARCHAR(20);
IF MARKS>=990 AND MARKS<=1500 THEN
SET CLASS='DISTINCTION';
ELSEIF MARKS>=900 AND MARKS<=989 THEN
SET CLASS="FIRST CLASS";
ELSEIF MARKS>=825 AND MARKS<=899 THEN
SET CLASS="HIGHER SECOND CLASS";
END IF;
INSERT INTO STUDENT_MARKS VALUES(ROLL,NAME,MARKS);
INSERT INTO RESULT VALUES(ROLL,NAME,CLASS);
END//

DELIMITER ;

CALL GRADE(11,'Cameron',1500);
CALL GRADE(12,'Justine',900);
CALL GRADE(31,'Rigel',825);

SELECT * FROM STUDENT_MARKS;
SELECT * FROM RESULT;