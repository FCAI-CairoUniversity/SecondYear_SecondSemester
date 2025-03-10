------------------- LECTURE 3 : ADD, DELETE, ALTER TABLES -------------------

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

-- Add a new table called "NumberOfStudents" that contains the number of students in each department:
ALTER TABLE Department
ADD NumberOfStudents INT;

-- Delete the "City" column from the Student table:
ALTER TABLE Student
DROP COLUMN City;

-- Alter the "Name" column in the Department table to increase its size to 50 characters:
ALTER TABLE Department
ALTER COLUMN Name VARCHAR(50);

-- Add Constraints to the Registered Table:
ALTER TABLE Registered
ADD CONSTRAINT FK_Registered_Student FOREIGN KEY (SSN) REFERENCES Student(SSN);

-- Delete the Foreign Key Constraint from the Registered Table:
ALTER TABLE Registered
DROP CONSTRAINT FK_Registered_Student;

-- Delete the Registered Table:
DROP TABLE Registered;

-- Drop the University Database:
-- But first, you should select master database:
USE master;
-- Now, You can drop the University database:
DROP DATABASE University;