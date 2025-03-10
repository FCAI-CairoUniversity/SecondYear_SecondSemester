# **Lecture 2 : Creating and Managing Databases and Tables in SQL**

## **1. Creating and Dropping a Database**
- **Creating a Database:**
  ```sql
  CREATE DATABASE <Database_Name>;
  ```
  Example:
  ```sql
  CREATE DATABASE University;
  ```
  This command **creates** a new database named `University`.

- **Dropping (Deleting) a Database:**  
  ```sql
  DROP DATABASE <Database_Name>;
  ```
  Example:  
  ```sql
  DROP DATABASE University;
  ```
  This **removes** the entire database permanently.

---

## **2. Table Creation Process**
Before creating a table, consider the following:
1. Identify **attributes** (columns).
2. Determine **data types** for each column.
3. Specify which columns **cannot be NULL**.
4. Ensure columns that require **unique values**.
5. Define **Primary Key (PK) and Foreign Key (FK)** relationships.
6. Assign **default values** where necessary.
7. Apply **constraints** to maintain data integrity.

---

## **3. Syntax for Creating Tables**
```sql
CREATE TABLE table_name (
    column1 datatype constraint_1 constraint_2,
    column2 datatype,
    column3 datatype constraint_3,
    .....
    columnN datatype,
    constraint_1,
    constraint_2,
    constraint_3
);
```
Each column has a **data type** and can have **constraints** such as NOT NULL, UNIQUE, PRIMARY KEY, etc.

---

## **4. Common Constraints in Table Creation**
| Constraint  | Description |
|-------------|------------|
| **NOT NULL** | Ensures a column **cannot** have NULL values. |
| **DEFAULT** | Provides a **default** value if no value is specified. |
| **UNIQUE** | Ensures **all values** in a column are different. |
| **PRIMARY KEY (PK)** | Uniquely identifies each row in a table (**NOT NULL + UNIQUE**). |
| **FOREIGN KEY (FK)** | Links one table to another, ensuring **referential integrity**. |
| **CHECK** | Ensures values in a column meet a certain condition. |

---

## **5. Examples of Table Creation with Constraints**

### **Example 1: Using UNIQUE Constraint**
```sql
CREATE TABLE Course (
    CrsCode SMALLINT,
    Name VARCHAR(45) UNIQUE,
    PRIMARY KEY (CrsCode)
);
```
OR  
```sql
CREATE TABLE Course (
    CrsCode SMALLINT,
    Name VARCHAR(45),
    PRIMARY KEY (CrsCode),
    CONSTRAINT UC_CrsName UNIQUE (Name)
);
```
- **CrsCode** is the **Primary Key**.
- **Name** must have **unique values**.

---

### **Example 2: Using DEFAULT Constraint**
```sql
CREATE TABLE Student (
    SSN INT PRIMARY KEY,
    Name VARCHAR(45),
    Age INT,
    City VARCHAR(15) DEFAULT 'CAIRO',
    Major VARCHAR(5)
);
```
- If no **City** is provided, it defaults to **'CAIRO'**.

---

### **Example 3: Using CHECK Constraint**
```sql
CREATE TABLE Student (
    SSN INT PRIMARY KEY,
    Name VARCHAR(45),
    Age INT,
    City VARCHAR(15) DEFAULT 'CAIRO',
    Major VARCHAR(5),
    CONSTRAINT CHK_Student CHECK (Age >= 18 AND City = 'Giza')
);
```
- Ensures **Age is at least 18** and **City is 'Giza'**.

---

## **6. Foreign Key Constraint (Referential Integrity)**
A **Foreign Key** links a column in one table to the **Primary Key** in another table.

### **Example 1: Creating a Table with a Foreign Key**
```sql
CREATE TABLE Registered (
    SSN INT FOREIGN KEY REFERENCES Student(SSN),
    CrsCode SMALLINT FOREIGN KEY REFERENCES Course(CrsCode),
    Semester VARCHAR(45) NOT NULL,
    PRIMARY KEY (SSN, CrsCode)
);
```
- `SSN` is a **Foreign Key** referencing `Student(SSN)`.
- `CrsCode` is a **Foreign Key** referencing `Course(CrsCode)`.
- **Primary Key** is `(SSN, CrsCode)`, meaning each student can register for a course only once per record.
