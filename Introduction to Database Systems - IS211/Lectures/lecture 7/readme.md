# SQL Operations - UNION, INTERSECT, EXCEPT & Aggregate Functions

## Overview
This document covers essential SQL operations such as **UNION**, **UNION ALL**, **INTERSECT**, and **EXCEPT** along with **aggregate functions** using the `university` database.

## Table Structure
Before using these operations, ensure you have the following tables in your database:

```sql
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

## 🔹 UNION vs. UNION ALL
### 🔹 `UNION` - Removes Duplicates
Combines result sets from multiple queries but **removes duplicates**.
```sql
SELECT Name FROM Student
UNION
SELECT Name FROM Course;
```

### 🔹 `UNION ALL` - Keeps Duplicates
Combines result sets but **keeps duplicates**.
```sql
SELECT Name FROM Student
UNION ALL
SELECT Name FROM Course;
```

---

## 🔹 INTERSECT
Returns only **common values** from both queries.
```sql
SELECT Name FROM Student
INTERSECT
SELECT Name FROM Course;
```

---

## 🔹 EXCEPT
Returns values that are in the first query but **not in the second**.
```sql
SELECT Name FROM Student
EXCEPT
SELECT Name FROM Course;
```

---

## 🔹 Aggregate Functions
Aggregate functions perform calculations on a group of values and return a **single** value.

### ✅ COUNT() - Counting Rows
Counts the number of students in the database.
```sql
SELECT COUNT(SSN) AS Student_Count FROM Student;
```

### ✅ SUM() - Total Sum
Finds the total number of courses registered.
```sql
SELECT SUM(CrsCode) FROM Registered;
```

### ✅ AVG() - Average
Finds the average age of students.
```sql
SELECT AVG(Age) AS Average_Age FROM Student;
```

### ✅ MAX() & MIN() - Maximum and Minimum Values
Finds the oldest and youngest student.
```sql
SELECT MAX(Age) AS Oldest_Student, MIN(Age) AS Youngest_Student FROM Student;
```

---

## 🎯 Summary Table
| **SQL Operation** | **Description** |
|-------------------|----------------|
| `UNION` | Combines results and removes duplicates |
| `UNION ALL` | Combines results and keeps duplicates |
| `INTERSECT` | Returns common records between queries |
| `EXCEPT` | Returns records in first query but not in second |
| `COUNT()` | Counts the number of records |
| `SUM()` | Sums up a column’s values |
| `AVG()` | Calculates the average value |
| `MAX()` | Returns the highest value |
| `MIN()` | Returns the lowest value |

---

## 🎯 Next Steps
- Test these queries in **Microsoft SQL Server**.
- Modify them to fit your database.
- Experiment with different conditions to understand their behavior.

---

## 📞 Need Help?
For more SQL topics and guides, feel free to ask! 🚀

