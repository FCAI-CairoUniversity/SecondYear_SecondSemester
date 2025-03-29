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

-------- INNER JOIN -> we use the foreign keys 
-- First way
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

-- Second way 
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

-- Third way
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

-------- RIGHT OUTER JOIN
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student
RIGHT JOIN Registered ON Student.SSN = Registered.SSN
RIGHT JOIN Course ON Registered.CrsCode = Course.CrsCode;

-------- LEFT OUTER JOIN
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student
LEFT JOIN Registered ON Student.SSN = Registered.SSN
LEFT JOIN Course ON Registered.CrsCode = Course.CrsCode;

-------- FULL OUTER JOIN
SELECT 
    Student.SSN, 
    Student.Name AS Student_Name, 
    Course.CrsCode, 
    Course.Name AS Course_Name, 
    Registered.Semester, 
    Registered.Year
FROM Student
FULL OUTER JOIN Registered ON Student.SSN = Registered.SSN
FULL OUTER JOIN Course ON Registered.CrsCode = Course.CrsCode;

-------- CROSS JOIN
SELECT 
    Student.Name AS Student_Name, 
    Course.Name AS Course_Name
FROM Student
CROSS JOIN Course;

-------- UNION Example
SELECT Name FROM Student
UNION
SELECT Name FROM Course;

-------- UNION ALL Example
SELECT Name FROM Student
UNION ALL
SELECT Name FROM Course;

-------- INTERSECT Example (Common Values Between Student and Course Names)
SELECT Name FROM Student
INTERSECT
SELECT Name FROM Course;

-------- EXCEPT Example (Names in Student but NOT in Course)
SELECT Name FROM Student
EXCEPT
SELECT Name FROM Course;

