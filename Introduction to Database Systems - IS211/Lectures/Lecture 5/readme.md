# SQL JOINs - A Complete Guide

## Overview
This document explains different types of **SQL JOINs** using **Microsoft SQL Server**. It provides examples using both the **JOIN keyword** and alternative methods.

## Database Schema
The database consists of four tables:
- **Student (SSN, Name, City, Age, Major)**
- **Course (CrsCode, Name)**
- **Registered (SSN, CrsCode, Semester, Year)** (Associative Table between Student and Course)
- **Department (DeptCode, Name)**

## 1️⃣ Table Creation and Data Insertion
The script follows these steps:
1. Drops existing tables if they exist.
2. Creates tables with appropriate primary and foreign key constraints.
3. Inserts sample data into all tables.

```sql
-- Create Student Table
DROP TABLE IF EXISTS Registered;
DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Course;
DROP TABLE IF EXISTS Department;

CREATE TABLE Student (
    SSN INT PRIMARY KEY,
    Name VARCHAR(100),
    City VARCHAR(50),
    Age INT,
    Major VARCHAR(50)
);

CREATE TABLE Course (
    CrsCode INT PRIMARY KEY,
    Name VARCHAR(100)
);

CREATE TABLE Registered (
    SSN INT,
    CrsCode INT,
    Semester VARCHAR(20),
    Year INT,
    PRIMARY KEY (SSN, CrsCode, Semester, Year),
    FOREIGN KEY (SSN) REFERENCES Student(SSN) ON DELETE CASCADE,
    FOREIGN KEY (CrsCode) REFERENCES Course(CrsCode) ON DELETE CASCADE
);

CREATE TABLE Department (
    DeptCode INT PRIMARY KEY,
    Name VARCHAR(100)
);
```

---

## 2️⃣ INNER JOIN
Retrieves only matching records from both tables.

### ✅ Using `JOIN`
```sql
SELECT Student.SSN, Student.Name, Course.CrsCode, Course.Name AS Course_Name
FROM Student
JOIN Registered ON Student.SSN = Registered.SSN
JOIN Course ON Registered.CrsCode = Course.CrsCode;
```

### ✅ Without `JOIN` (Using `WHERE`)
```sql
SELECT Student.SSN, Student.Name, Course.CrsCode, Course.Name AS Course_Name
FROM Student, Registered, Course
WHERE Student.SSN = Registered.SSN
AND Registered.CrsCode = Course.CrsCode;
```

---

## 3️⃣ LEFT JOIN
Retrieves all records from the left table and only matching records from the right table.

### ✅ Using `LEFT JOIN`
```sql
SELECT Student.SSN, Student.Name, Course.CrsCode, Course.Name AS Course_Name
FROM Student
LEFT JOIN Registered ON Student.SSN = Registered.SSN
LEFT JOIN Course ON Registered.CrsCode = Course.CrsCode;
```

### ✅ Without `JOIN` (Using `UNION` to Simulate)
```sql
SELECT Student.SSN, Student.Name, Registered.CrsCode, Course.Name AS Course_Name
FROM Student, Registered, Course
WHERE Student.SSN = Registered.SSN
AND Registered.CrsCode = Course.CrsCode

UNION

SELECT Student.SSN, Student.Name, NULL AS CrsCode, NULL AS Course_Name
FROM Student
WHERE Student.SSN NOT IN (SELECT SSN FROM Registered);
```

---

## 4️⃣ RIGHT JOIN
Retrieves all records from the right table and only matching records from the left table.

### ✅ Using `RIGHT JOIN`
```sql
SELECT Student.SSN, Student.Name, Course.CrsCode, Course.Name AS Course_Name
FROM Student
RIGHT JOIN Registered ON Student.SSN = Registered.SSN
RIGHT JOIN Course ON Registered.CrsCode = Course.CrsCode;
```

### ✅ Without `JOIN` (Using `UNION` to Simulate)
```sql
SELECT Student.SSN, Student.Name, Registered.CrsCode, Course.Name AS Course_Name
FROM Student, Registered, Course
WHERE Student.SSN = Registered.SSN
AND Registered.CrsCode = Course.CrsCode

UNION

SELECT NULL AS SSN, NULL AS Student_Name, Course.CrsCode, Course.Name AS Course_Name
FROM Course
WHERE Course.CrsCode NOT IN (SELECT CrsCode FROM Registered);
```

---

## 5️⃣ FULL OUTER JOIN
Retrieves all records from both tables, with NULLs where there is no match.

### ✅ Using `FULL OUTER JOIN`
```sql
SELECT Student.SSN, Student.Name, Course.CrsCode, Course.Name AS Course_Name
FROM Student
FULL OUTER JOIN Registered ON Student.SSN = Registered.SSN
FULL OUTER JOIN Course ON Registered.CrsCode = Course.CrsCode;
```

### ✅ Without `JOIN` (Using `UNION` to Simulate)
```sql
SELECT Student.SSN, Student.Name, Registered.CrsCode, Course.Name AS Course_Name
FROM Student, Registered, Course
WHERE Student.SSN = Registered.SSN
AND Registered.CrsCode = Course.CrsCode

UNION

SELECT Student.SSN, Student.Name, NULL AS CrsCode, NULL AS Course_Name
FROM Student
WHERE Student.SSN NOT IN (SELECT SSN FROM Registered)

UNION

SELECT NULL AS SSN, NULL AS Student_Name, Course.CrsCode, Course.Name AS Course_Name
FROM Course
WHERE Course.CrsCode NOT IN (SELECT CrsCode FROM Registered);
```

---

## 6️⃣ CROSS JOIN
Returns a **Cartesian product** (every combination of records from both tables).

### ✅ Using `CROSS JOIN`
```sql
SELECT Student.Name AS Student_Name, Course.Name AS Course_Name
FROM Student
CROSS JOIN Course;
```

### ✅ Without `JOIN` (Using `FROM` with Multiple Tables)
```sql
SELECT Student.Name AS Student_Name, Course.Name AS Course_Name
FROM Student, Course;
```

---

## 🎯 Summary Table

| **JOIN Type**   | **Using `JOIN`** | **Without `JOIN` (Alternative)** |
|---------------|----------------|--------------------------------|
| **INNER JOIN** | ✅ `JOIN` | ✅ `WHERE` condition on multiple tables |
| **LEFT JOIN**  | ✅ `LEFT JOIN` | 🔹 `UNION` to simulate missing values |
| **RIGHT JOIN** | ✅ `RIGHT JOIN` | 🔹 `UNION` to simulate missing values |
| **FULL OUTER JOIN** | ✅ `FULL OUTER JOIN` | 🔹 `UNION` of LEFT + RIGHT alternatives |
| **CROSS JOIN** | ✅ `CROSS JOIN` | ✅ `FROM` with multiple tables |

---

## 📌 Notes
- ✅ Using `JOIN` (SQL-92 standard) is **recommended**.
- 🔹 The **WHERE method** works but is **less readable and harder to maintain**.
- 🚀 If `FULL OUTER JOIN` is not supported, use **`UNION`** to simulate it.

---

## 🎯 Next Steps
- Run these queries on **Microsoft SQL Server**.
- Modify queries based on your database structure.
- Experiment with different conditions to understand `JOIN` behavior better.

---

## 📞 Need Help?
For more SQL topics and guides, feel free to ask! 🚀

