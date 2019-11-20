CREATE TABLE LIBRARY_INFO(ID INT NOT NULL,NAME VARCHAR(50),PRIMARY KEY(ID));

INSERT INTO LIBRARY_INFO ( ID,NAME) VALUES('1','Rigel');
INSERT INTO LIBRARY_INFO ( ID,NAME) VALUES('2','Cameron');
INSERT INTO LIBRARY_INFO ( ID,NAME) VALUES('3','Kato');
INSERT INTO LIBRARY_INFO ( ID,NAME) VALUES('4','Brynne');

SELECT * FROM LIBRARY_INFO;

CREATE TABLE LIBRARY_AUDIT(ID INT NOT NULL,NAME VARCHAR(50),CHANGEDATE DATE);

DELIMITER //

CREATE TRIGGER T1 AFTER UPDATE ON LIBRARY_INFO FOR EACH ROW
BEGIN
INSERT INTO LIBRARY_AUDIT SET ID = OLD.ID, NAME= OLD.NAME, CHANGEDATE= NOW() ;
END //

DELIMITER ;

SHOW TRIGGERS;

UPDATE LIBRARY_INFO SET NAME='Yolanda' WHERE ID=3;

SELECT * FROM LIBRARY_INFO;
SELECT * FROM LIBRARY_AUDIT;