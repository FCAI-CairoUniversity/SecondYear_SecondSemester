-- Create Student Table
DROP TABLE IF EXISTS Registered;

-- Drop Student and Course Tables
DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Course;
DROP TABLE IF EXISTS Department;
USE university;

CREATE TABLE Student (
    SSN INT PRIMARY KEY,
    Name VARCHAR(100),
    City VARCHAR(50),
    Age INT,
    Major VARCHAR(50)
);

-- Create Course Table
CREATE TABLE Course (
    CrsCode INT PRIMARY KEY,
    Name VARCHAR(100)
);

-- Create Registered Table (Relationship between Student & Course)
CREATE TABLE Registered (
    SSN INT,
    CrsCode INT,
    Semester VARCHAR(20),
    Year INT,
    PRIMARY KEY (SSN, CrsCode, Semester, Year),
    FOREIGN KEY (SSN) REFERENCES Student(SSN) ON DELETE CASCADE,
    FOREIGN KEY (CrsCode) REFERENCES Course(CrsCode) ON DELETE CASCADE
);

-- Create Department Table
CREATE TABLE Department (
    DeptCode INT PRIMARY KEY,
    Name VARCHAR(100)
);

-- Insert into Student Table
INSERT INTO Student (SSN, Name, City, Age, Major) VALUES
(1, 'Alice Johnson', 'New York', 22, 'Computer Science'),
(2, 'Bob Smith', 'Los Angeles', 21, 'Engineering'),
(3, 'Charlie Brown', 'Chicago', 23, 'Mathematics'),
(4, 'David Williams', 'Houston', 22, 'Physics');

-- Insert into Course Table
INSERT INTO Course (CrsCode, Name) VALUES
(101, 'Database Systems'),
(102, 'Operating Systems'),
(103, 'Computer Networks'),
(104, 'Machine Learning');

-- Insert into Registered Table (Students enrolling in Courses)
INSERT INTO Registered (SSN, CrsCode, Semester, Year) VALUES
(1, 101, 'Fall', 2024),
(2, 102, 'Spring', 2024),
(3, 103, 'Fall', 2024),
(4, 104, 'Spring', 2024),
(1, 102, 'Fall', 2024);

-- Insert into Department Table
INSERT INTO Department (DeptCode, Name) VALUES
(10, 'Computer Science'),
(20, 'Engineering'),
(30, 'Mathematics'),
(40, 'Physics');

SELECT COUNT(SSN) AS count FROM Student;
SELECT * FROM Student;
SELECT * FROM Course;
SELECT * FROM Registered;
SELECT * FROM Department;

-------- INNER JOIN (Three Methods)
-- First Method (Explicit INNER JOIN)
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student
INNER JOIN Registered ON Student.SSN = Registered.SSN
INNER JOIN Course ON Registered.CrsCode = Course.CrsCode;

-- Second Method (Using JOIN keyword without INNER)
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student
JOIN Registered ON Student.SSN = Registered.SSN
JOIN Course ON Registered.CrsCode = Course.CrsCode;

-- Third Method (Without JOIN keyword, Using WHERE Clause)
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student, Registered, Course
WHERE Student.SSN = Registered.SSN 
AND Registered.CrsCode = Course.CrsCode;

-------- RIGHT OUTER JOIN (Three Methods)
-- First Method (Explicit RIGHT OUTER JOIN)
SELECT * FROM Student
RIGHT OUTER JOIN Registered ON Student.SSN = Registered.SSN;

-- Second Method (Using RIGHT JOIN without OUTER)
SELECT * FROM Student
RIGHT JOIN Registered ON Student.SSN = Registered.SSN;

-- Third Method (Using WHERE Clause, Not Recommended)
SELECT * FROM Student, Registered
WHERE Student.SSN *= Registered.SSN;

-------- LEFT OUTER JOIN (Three Methods)
-- First Method (Explicit LEFT OUTER JOIN)
SELECT * FROM Student
LEFT OUTER JOIN Registered ON Student.SSN = Registered.SSN;

-- Second Method (Using LEFT JOIN without OUTER)
SELECT * FROM Student
LEFT JOIN Registered ON Student.SSN = Registered.SSN;

-- Third Method (Using WHERE Clause, Not Recommended)
SELECT * FROM Student, Registered
WHERE Student.SSN =* Registered.SSN;

-------- FULL OUTER JOIN (Two Methods)
-- First Method (Explicit FULL OUTER JOIN)
SELECT * FROM Student
FULL OUTER JOIN Registered ON Student.SSN = Registered.SSN;

-- Second Method (Using FULL JOIN without OUTER)
SELECT * FROM Student
FULL JOIN Registered ON Student.SSN = Registered.SSN;

-------- CROSS JOIN
-- First Method (Explicit CROSS JOIN)
SELECT * FROM Student
CROSS JOIN Course;

-- Second Method (Without CROSS JOIN, Using Cartesian Product)
SELECT * FROM Student, Course;
