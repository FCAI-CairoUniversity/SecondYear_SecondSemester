# Lecture 4 : Data Manipulation Language (DML) - Part 1

This lecture covers the basics of SQL's **Data Manipulation Language (DML)**, which is used to interact with data stored in databases. Below is a summary of key concepts, syntax, and examples.

---

## DML Overview
DML commands are used to manipulate data in a database:
- **SELECT**: Retrieve data.
- **INSERT**: Add new rows.
- **UPDATE**: Modify existing rows.
- **DELETE**: Remove rows.

---

## INSERT Statement
Adds new rows to a table.

### Syntax
```sql
-- When inserting values for all columns (in order):
INSERT INTO table_name 
VALUES (value1, value2, ...);

-- When specifying columns (order-independent):
INSERT INTO table_name (column1, column2, ...)
VALUES (value1, value2, ...);
```

### Examples
1. Insert a new course:
   ```sql
   INSERT INTO Course 
   VALUES ('IS221', 'Information Retrieval');
   ```

2. Insert a student with partial data (NULL allowed for missing fields):
   ```sql
   INSERT INTO Student (SSN, Name, Major)
   VALUES (211, 'Neveen', 'IS');
   ```

### Notes
- Primary keys cannot be `NULL` or duplicated.
- Ensure data types match column definitions.
- Use `NULL` explicitly or omit columns where allowed.

---

## UPDATE Statement
Modifies existing rows based on conditions.

### Syntax
```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

### Examples
1. Increase all students' GPA by 5%:
   ```sql
   UPDATE Student
   SET GPA = GPA * 1.05;
   ```

2. Update a student's city and major:
   ```sql
   UPDATE Student
   SET City = 'Giza', Major = 'IT'
   WHERE SSN = 109;
   ```

---

## DELETE Statement
Removes rows from a table.

### Syntax
```sql
-- Delete specific rows:
DELETE FROM table_name 
WHERE condition;

-- Delete all rows (use with caution!):
DELETE FROM table_name;
```

### Examples
1. Delete a student's course registration:
   ```sql
   DELETE FROM Registered
   WHERE SSN = 101 AND CrsCode = 'IS312';
   ```

---

## SELECT Statement
Retrieves data from one or more tables.

### Syntax
```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

### Key Features
- Use `*` to select all columns:
  ```sql
  SELECT * FROM Department;
  ```
- `DISTINCT` keyword removes duplicates:
  ```sql
  SELECT DISTINCT Salary FROM Employees;
  ```
- **WHERE Clause Operators**:  
  `=`, `<>`, `<`, `>`, `<=`, `>=`, `AND`, `OR`.

### Examples
1. Get employees with job title "Sales Rep":
   ```sql
   SELECT lastName, firstName 
   FROM employees 
   WHERE jobTitle = 'Sales Rep';
   ```

2. Combine `AND`/`OR` conditions:
   ```sql
   SELECT lastName, firstName 
   FROM employees 
   WHERE jobTitle = 'Sales Rep' AND officeCode = 1;
   ```

---

## Database Schema (University Example)
Tables used in examples:
- **Student** (`SSN`, `Name`, `City`, `DOB`, `Major`, `GPA`)
- **Course** (`CrsCode`, `Name`)
- **Registered** (`SSN`, `CrsCode`, `Semester`, `Year`)
- **Department** (`DCode`, `Name`)

---

## Exercises
1. Display all departments:
   ```sql
   SELECT * FROM Department;
   ```

2. Retrieve students' names and majors:
   ```sql
   SELECT Name, Major FROM Student;
   ```
