------------------- LECTURE 2: CREATE DATABASE, CREATE TABLE, DROP TABLE, DROP DATABASE -------------------

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

-- Drop the University Database:
-- But first, you should select master database:
USE master;
-- Now, You can drop the University database:
DROP DATABASE University;