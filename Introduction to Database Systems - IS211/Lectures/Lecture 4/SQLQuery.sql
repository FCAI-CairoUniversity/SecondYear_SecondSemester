------------------- LECTURE 4 : SELECT, INSERT, UPDATE, DELETE DATA -------------------

-- Create a database called University and use it to create the following tables:
CREATE DATABASE University;
-- But first, you should select University database:
USE University;
-- Now, you can create the tables:

-- Create the Department Table with the following columns and constraints:
CREATE TABLE Department(
    DeptCode VARCHAR(5) NOT NULL PRIMARY KEY ,
    [Name] VARCHAR(15) NOT NULL,
);

-- Create the Course Table with the following columns and constraints:
CREATE TABLE Course (
    CrsCode VARCHAR(10),
    Name VARCHAR(45) UNIQUE,
    PRIMARY KEY (CrsCode)
);

-- Create the Student Table with the following columns and constraints:
CREATE TABLE Student (
    SSN INT PRIMARY KEY,
    Name VARCHAR(45),
    Age INT,
    City VARCHAR(15) DEFAULT 'CAIRO',
    Major VARCHAR(5),
    CONSTRAINT CHK_Student CHECK (Age >= 18)
);

-- Create the Registered Table with Foreign Key Constraints:
CREATE TABLE Registered (
    SSN INT,
    CrsCode VARCHAR(10),
    Semester VARCHAR(45) NOT NULL,
    [Year] VARCHAR(4),  -- "Year" is a reserved keyword, so we use brackets []
    PRIMARY KEY (SSN, CrsCode),
    FOREIGN KEY (SSN) REFERENCES Student(SSN),
    FOREIGN KEY (CrsCode) REFERENCES Course(CrsCode)
);

-- Insert into the Course Table:
INSERT INTO Course (CrsCode, Name) VALUES ('IS211', 'Introduction to Database Systems');
INSERT INTO Course (CrsCode, Name) VALUES ('CS214', 'Data Structures');

-- Insert into the Student Table:
INSERT INTO Student(SSN, Name, Age, City) VALUES (1, 'Mariam', 19, 'Cairo');
INSERT INTO Student VALUES (2, 'Wafaa', 19, 'Cairo', null);
INSERT INTO Student VALUES (3, 'George', 20, 'Giza', 'IS211');
INSERT INTO Student(SSN, Name, Age, City) VALUES (4, 'Amr', 19, 'Giza');
INSERT INTO Student VALUES (5, 'Atef', 19, 'Alexandria' , 'CS214');

-- Update the Age of the Student with SSN = 5:
UPDATE Student
SET Age = 20
WHERE SSN = 5;

-- Update the City and Major of the Student with SSN = 1:
UPDATE Student
SET City = 'Giza', Major = 'CS214'
WHERE SSN = 1;

-- Select all the rows from the Student Table:
SELECT * FROM Student;

-- Select the Name of the Student with SSN = 1234:
SELECT [Name]
FROM Student
WHERE SSN = 2;

-- Select distinct Cities from the Student Table:
SELECT DISTINCT City
FROM Student;

-- Select the Name and Age of the Students with Age >= 20:
SELECT [Name], Age
FROM Student
WHERE Age >= 20;

-- Select the Name and Major of the Students with Major not equal to 'CS':
SELECT [Name], Major
FROM Student
WHERE Major <> 'CS214';

-- Delete all the rows from the Student Table:
DELETE FROM Student;

-- Delete the Course with CrsCode = 101:
DELETE FROM Course
WHERE CrsCode = 'CS214';

-- Drop the University Database:
-- But first, you should select master database:
USE master;
-- Now, You can drop the University database:
DROP DATABASE University;