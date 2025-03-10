-- =================================================================================
-- File: SQL_Constraints.sql
-- Description: This file explains all SQL constraints with examples.
-- Constraints are rules applied to columns or tables to enforce data integrity.
-- =================================================================================

-- 1. PRIMARY KEY
-- Ensures a column (or set of columns) uniquely identifies each row in a table.
-- A table can have only one PRIMARY KEY.
CREATE TABLE Students (
    StudentID INT PRIMARY KEY, -- StudentID is the primary key
    Name VARCHAR(50) NOT NULL
);

-- 2. FOREIGN KEY
-- Ensures referential integrity by linking two tables.
-- It references the PRIMARY KEY of another table.
CREATE TABLE Courses (
    CourseID INT PRIMARY KEY, -- CourseID is the primary key
    CourseName VARCHAR(50) NOT NULL
);

CREATE TABLE Enrollments (
    EnrollmentID INT PRIMARY KEY,
    StudentID INT,
    CourseID INT,
    FOREIGN KEY (StudentID) REFERENCES Students(StudentID), -- Links to Students table
    FOREIGN KEY (CourseID) REFERENCES Courses(CourseID) -- Links to Courses table
);

-- 3. NOT NULL
-- Ensures a column cannot have NULL values.
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL, -- Name cannot be NULL
    Age INT
);

-- 4. UNIQUE
-- Ensures all values in a column are unique.
CREATE TABLE Products (
    ProductID INT PRIMARY KEY,
    ProductCode VARCHAR(10) UNIQUE, -- ProductCode must be unique
    ProductName VARCHAR(50)
);

-- 5. DEFAULT
-- Provides a default value for a column if no value is specified.
CREATE TABLE Orders (
    OrderID INT PRIMARY KEY,
    OrderDate DATE DEFAULT GETDATE(), -- Defaults to the current date
    CustomerName VARCHAR(50)
);

-- 6. CHECK
-- Ensures that all values in a column satisfy a specific condition.
CREATE TABLE Persons (
    PersonID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT CHECK (Age >= 18) -- Ensures age is 18 or older
);

-- 7. ON DELETE CASCADE
-- Automatically deletes related rows in child tables when a row in the parent table is deleted.
CREATE TABLE Departments (
    DeptID INT PRIMARY KEY,
    DeptName VARCHAR(50)
);

CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Departments(DeptID) ON DELETE CASCADE
    -- If a department is deleted, all employees in that department are also deleted
);

-- 8. ON DELETE SET NULL
-- Sets the foreign key value to NULL when the referenced row is deleted.
CREATE TABLE Employees (
    EmployeeID INT PRIMARY KEY,
    Name VARCHAR(50),
    DeptID INT,
    FOREIGN KEY (DeptID) REFERENCES Departments(DeptID) ON DELETE SET NULL
    -- If a department is deleted, the DeptID for employees is set to NULL
);

-- =================================================================================
-- End of File: SQL_Constraints.sql
-- =================================================================================
