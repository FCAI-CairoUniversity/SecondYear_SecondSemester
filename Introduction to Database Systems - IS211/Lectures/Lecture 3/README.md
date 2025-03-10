# **Lecture 3 : SQL Reserved Words, and ALTER TABLE Statements**

## **1. Auto-Increment in SQL**
- **Auto-increment** generates a **unique number** automatically when inserting a new record.
- Typically used for the **Primary Key** to ensure **unique identification** for each row.

### **Example:**
```sql
CREATE TABLE Persons (
    PersonID INT IDENTITY(1, 1) PRIMARY KEY,
    FirstName VARCHAR(255) NOT NULL,
    LastName VARCHAR(255),
    Age INT
);
```

---

## **2. Reserved Words in SQL**
- SQL has **reserved words** that cannot be used as **column names**.
- **Solution:** Use **square brackets `[]`** or **double quotes `""`** around them.

### **Example: Handling Reserved Words**
```sql
CREATE TABLE Registered (
    SSN INT FOREIGN KEY REFERENCES Student(SSN),
    CrsCode INT FOREIGN KEY REFERENCES Course(CrsCode),
    Semester VARCHAR(45) NOT NULL,
    [Year] VARCHAR(45),     -- "Year" is a reserved word
    PRIMARY KEY (SSN, CrsCode)
);
```
- `[Year]` is enclosed in brackets because **"Year"** is a reserved SQL keyword.

---

## **3. ALTER TABLE Statement**
The `ALTER TABLE` statement allows **modifications** to existing tables, such as:
- **Adding a column**
- **Deleting a column**
- **Changing a column's data type**
- **Adding and removing constraints**

---

### **3.1 Adding a New Column**
```sql
ALTER TABLE Customers
ADD Email VARCHAR(100);
```
- Adds a new column `Email` to the `Customers` table.

```sql
ALTER TABLE Department
ADD NumberOfStudents INT;
```
- Adds `numberofstudents` column to `Department`.

---

### **3.2 Deleting a Column**
```sql
ALTER TABLE Customers
DROP COLUMN Email;
```
- Removes the `Email` column from `Customers`.

```sql
ALTER TABLE Student
DROP COLUMN Major;
```
- Deletes the `Major` column from `Student`.

---

### **3.3 Modifying a Column's Data Type**
```sql
ALTER TABLE Student
ALTER COLUMN StudentName VARCHAR(100);
```
- Changes `StudentName` data type to `VARCHAR(100)`.

```sql
ALTER TABLE Customer
ALTER COLUMN Address CHAR(100);
```
- Changes `Address` column to `CHAR(100)`.

> **⚠ Can You Change Any Data Type?**  
Not always!  
- You **can** change `VARCHAR(50)` → `VARCHAR(100)`.
- You **cannot** change `VARCHAR` → `INT` if the column has existing string values.

---

## **4. ALTER TABLE: Adding & Dropping Constraints**
You can modify constraints on an existing table.

### **4.1 Adding Constraints**
#### **Primary Key**
```sql
ALTER TABLE Registered
ADD CONSTRAINT PK1 PRIMARY KEY (SSN, CrsCode);
```
- Adds a **Primary Key** constraint.

#### **Unique Constraint**
```sql
ALTER TABLE Student
ADD CONSTRAINT UQ_Std_Name UNIQUE (Name);
```
- Ensures `Name` values are **unique**.

#### **Check Constraint**
```sql
ALTER TABLE Department
ADD CONSTRAINT CK_DeptCode CHECK (DeptCode IN ('IS', 'CS', 'IT', 'DS'));
```
- Ensures `DeptCode` can only be **'IS', 'CS', 'IT', or 'DS'**.

#### **Foreign Key Constraint**
```sql
ALTER TABLE Student
ADD CONSTRAINT FK_1 FOREIGN KEY (Major) REFERENCES Department (DeptCode);
```
- Ensures that `Major` in `Student` must exist in `Department(DeptCode)`.

---

### **4.2 Dropping Constraints**
#### **Drop Unique Constraint**
```sql
ALTER TABLE Student
DROP CONSTRAINT UQ_Std_Name;
```
- Removes the unique constraint on `Name`.

#### **Drop Check Constraint**
```sql
ALTER TABLE Department
DROP CONSTRAINT CK_DeptCode;
```
- Removes the check condition on `DeptCode`.

#### **Drop Default Value**
```sql
ALTER TABLE Persons
ALTER COLUMN City DROP DEFAULT;
```
- Removes the default value from the `City` column.

---

## **5. Deleting a Table**
The `DROP TABLE` statement permanently **removes a table**.
```sql
DROP TABLE Student;
```
- Deletes the entire `Student` table.

---

## **6. Exercises (Practice)**
**Write SQL statements for the following:**
1. **Add** a new column `CustomerAddress` to the `Customer` table.
   ```sql
   ALTER TABLE Customer
   ADD CustomerAddress CHAR(25);
   ```

2. **Modify** the data type of `CustomerAddress` to `VARCHAR(100)`.
   ```sql
   ALTER TABLE Customer
   ALTER COLUMN CustomerAddress VARCHAR(100);
   ```

3. **Delete** the `Customer` table.
   ```sql
   DROP TABLE Customer;
   ```

4. **Add a Foreign Key** in `Orders` referring to `Persons(PersonID)`.
   ```sql
   ALTER TABLE Orders
   ADD CONSTRAINT FK_PersonOrder FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);
   ```
