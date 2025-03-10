-- =================================================================================
-- File: SQL_DDL_with_DML.sql
-- Description: This file explains Data Definition Language (DDL) and includes DML examples with WHERE.
-- DDL is used to define and modify the structure of database objects like tables.
-- DML is used to manipulate data within those tables.
-- =================================================================================

-- 1. CREATE TABLE
-- Creates a new table in the database.
CREATE TABLE Students (
    StudentID INT PRIMARY KEY, -- Primary key constraint
    Name VARCHAR(50) NOT NULL, -- NOT NULL constraint
    Age INT CHECK (Age >= 18), -- CHECK constraint
    City VARCHAR(50) DEFAULT 'Unknown' -- DEFAULT constraint
);

-- 2. ALTER TABLE
-- Modifies the structure of an existing table.

-- Add a new column
ALTER TABLE Students
ADD Email VARCHAR(100); -- Adds a new column 'Email'

-- Modify an existing column
ALTER TABLE Students
MODIFY COLUMN City VARCHAR(100); -- Changes the data type of 'City' to VARCHAR(100)

-- Drop a column
ALTER TABLE Students
DROP COLUMN Email; -- Removes the 'Email' column

-- Add a constraint
ALTER TABLE Students
ADD CONSTRAINT CHK_Age CHECK (Age >= 16); -- Adds a CHECK constraint

-- Drop a constraint
ALTER TABLE Students
DROP CONSTRAINT CHK_Age; -- Removes the CHECK constraint

-- 3. DROP TABLE
-- Deletes an existing table and all its data.
DROP TABLE Students; -- Deletes the Students table

-- 4. TRUNCATE TABLE
-- Removes all rows from a table but retains the table structure.
TRUNCATE TABLE Students; -- Deletes all rows in the Students table

-- 5. RENAME TABLE
-- Renames an existing table.
ALTER TABLE Students
RENAME TO Learners; -- Renames the Students table to Learners

-- 6. CREATE INDEX
-- Creates an index on a table column to speed up queries.
CREATE INDEX idx_Name
ON Students(Name); -- Creates an index on the 'Name' column

-- 7. DROP INDEX
-- Deletes an existing index.
DROP INDEX idx_Name
ON Students; -- Deletes the index on the 'Name' column

-- =================================================================================
-- Example: Defining a Relational Schema
-- A relational schema defines the structure of a database, including tables, columns, and relationships.
-- =================================================================================

-- Create the Department table
CREATE TABLE Department (
    DeptID INT PRIMARY KEY, -- Primary key
    DeptName VARCHAR(50) NOT NULL -- Department name cannot be NULL
);

-- Create the Employee table
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY, -- Primary key
    Name VARCHAR(50) NOT NULL, -- Employee name cannot be NULL
    DeptID INT, -- Foreign key to Department table
    FOREIGN KEY (DeptID) REFERENCES Department(DeptID) ON DELETE SET NULL
    -- If a department is deleted, the DeptID for employees is set to NULL
);

-- =================================================================================
-- DML: Data Manipulation Language (Inserting, Updating, and Deleting Data)
-- =================================================================================

-- Insert data into the Department table
INSERT INTO Department (DeptID, DeptName) VALUES
    (1, 'Human Resources'),
    (2, 'Information Technology'),
    (3, 'Finance');

-- Insert data into the Employee table
INSERT INTO Employee (EmployeeID, Name, DeptID) VALUES
    (101, 'John Doe', 1),
    (102, 'Jane Smith', 2),
    (103, 'Alice Johnson', 3),
    (104, 'Bob Brown', 1),
    (105, 'Charlie Davis', 2);

-- =================================================================================
-- DML: Using WHERE in SELECT Statements
-- =================================================================================

-- Retrieve all employees in the 'Human Resources' department
SELECT * FROM Employee
WHERE DeptID = 1; -- Filters rows where DeptID is 1

-- Retrieve employees whose names start with 'J'
SELECT * FROM Employee
WHERE Name LIKE 'J%'; -- Filters rows where Name starts with 'J'

-- Retrieve employees older than 30 (assuming an Age column exists)
-- Note: Add the Age column to the Employee table first.
ALTER TABLE Employee
ADD Age INT;

UPDATE Employee
SET Age = 35
WHERE EmployeeID = 101;

UPDATE Employee
SET Age = 28
WHERE EmployeeID = 102;

UPDATE Employee
SET Age = 40
WHERE EmployeeID = 103;

UPDATE Employee
SET Age = 22
WHERE EmployeeID = 104;

UPDATE Employee
SET Age = 30
WHERE EmployeeID = 105;

SELECT * FROM Employee
WHERE Age > 30; -- Filters rows where Age is greater than 30

-- =================================================================================
-- DML: Using WHERE in UPDATE Statements
-- =================================================================================

-- Update the department of employees whose names start with 'J'
UPDATE Employee
SET DeptID = 3 -- Moves employees to the Finance department
WHERE Name LIKE 'J%'; -- Filters rows where Name starts with 'J'

-- Update the age of employees in the 'Information Technology' department
UPDATE Employee
SET Age = Age + 1 -- Increments age by 1
WHERE DeptID = 2; -- Filters rows where DeptID is 2

-- =================================================================================
-- DML: Using WHERE in DELETE Statements
-- =================================================================================

-- Delete employees who are younger than 25
DELETE FROM Employee
WHERE Age < 25; -- Filters rows where Age is less than 25

-- Delete all employees in the 'Finance' department
DELETE FROM Employee
WHERE DeptID = 3; -- Filters rows where DeptID is 3

-- =================================================================================
-- End of File: SQL_DDL_with_DML.sql
-- =================================================================================
