-- Author(s): Mohammed Atef & George Malak.
-- Date: March 6, 2025.
-- Lab: 2.
-- Course: Introduction to Database Systems - IS211.

CREATE DATABASE University;
USE University;

-- DEPARTMENT Table
CREATE TABLE Department(
    DeptCode VARCHAR(5) NOT NULL PRIMARY KEY ,
    Name VARCHAR(50) NOT NULL,
);

-- Course Table
CREATE TABLE Course(
    CrsCode SMALLINT NOT NULL,
    Name VARCHAR(45) UNIQUE,
    PRIMARY KEY (CrsCode)
);

-- Student Table
CREATE TABLE Student(
    SSN INT NOT NULL,
    Name VARCHAR(45),
    Age INT CHECK (AGE >= 18),
    City VARCHAR(15) DEFAULT 'CAIRO',
    Major VARCHAR(5)
);

--Add PK to Student table
ALTER TABLE STUDENT
ADD CONSTRAINT PK1 PRIMARY KEY (SSN); -- Constraint name is unique across database

-- Add FK Constraint to Student table
ALTER TABLE STUDENT
ADD CONSTRAINT FK_1 FOREIGN KEY (Major) REFERENCES Department (DeptCode);

-- Registered Table
CREATE TABLE Registered(
    SSN INT NOT NULL,
    CrsCode SMALLINT NOT NULL REFERENCES COURSE(Crscode),
    Semester VARCHAR (45) NOT NULL,
    [Year] VARCHAR (45)
);

-- Add pk and fk constraints to Registered Table
ALTER TABLE Registered
ADD PRIMARY KEY (SSN, CrsCode);
ALTER TABLE Registered
ADD FOREIGN KEY (SSN) REFERENCES Student (SSN);
ALTER TABLE Registered
ADD FOREIGN KEY (CrsCode) REFERENCES Course (CrsCode);

-- Insert Students and Set Department
INSERT INTO Student(SSN, Name, Age, City) VALUES (1, 'Ali', 19, 'Cairo');
INSERT INTO Student VALUES (2, 'Wafaa', 19, 'Cairo', null);

INSERT INTO Department VALUES('IS', 'Information System');
INSERT INTO Student VALUES (3, 'Wafaa', 19, 'Cairo', 'IS');

INSERT INTO Department VALUES('CS', 'Computer Science');
INSERT INTO Student VALUES (4, 'Atef', 19, 'Alexandria' , 'CS');

-- Updata Student's Data
UPDATE Student
SET Name = 'Ahmed'
Where SSN = 1;

UPDATE Student
SET Name = 'Ali', Age = 18
Where SSN = 2;

-- Delete Student
DELETE from Student
Where SSN = 4;