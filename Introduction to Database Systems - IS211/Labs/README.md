# 🗃️ Introduction to Database Systems - IS211

📌 This folder contains tasks related to **Database Management Systems (DBMS)**, covering **SQL queries, database design, and implementation**.

---

## 🛠️ Technologies Covered

- **Relational Databases.**
- **Query Language.**

---

## 📝 Tasks

   - <details><summary>Lab 1</summary>
   
     Consider the following schema of database “University” :
        - Student (<u>**SSN**</u>, Name, City, Age, Major).
        - Course (<u>**CrsCode**</u>, Name).
        - Registered (<u>**SSN**</u>, <u>**CrsCode**</u>, Semester, Year).
        - Department (<u>**DeptCode**</u>, Name).
        
     Write SQL DDL statement for declaring the University Database and relations. Specify appropriate keys and referential integrity constraints.
        
     **Note that:** you must ensure that the Age of student cannot be below 18 years.
        
     And Do This Operations:
        - Create Databases and Tables.
        - Add PK to Student table.
        - Add FK Constraint to Student table.
        - Add PK and FK constraints to Registered Table.
        
   </details>
   
   - <details><summary>Lab 2</summary>
   
     We are using the section's code and adding the following SQL operations:
        - Insert Students and Set Department.
        - Update Student's Data.
        - Delete Student.
        
   </details>
   
   - <details><summary>Lab 3</summary>
      
      In this lab, we explore various SQL queries using the Northwind database. After executing the `Northwind.sql` file and selecting the database, we perform fundamental SQL operations, including selecting specific columns, filtering data with conditions, and retrieving distinct values.
      
      The lab also covers SQL joins, such as `INNER JOIN`, `FULL OUTER JOIN`, and `CROSS JOIN`, to combine data from multiple tables like `Products`, `Categories`, and `Suppliers`. Additionally, we insert new records into tables and solve a specific task that retrieves supplier information along with corresponding product categories, despite the absence of a direct foreign key relationship between `Suppliers` and `Categories`.

   </details>
   
   - <details><summary>Lab 4</summary>
      
      In this lab, we work with the **Northwind** database by executing SQL queries to extract meaningful insights. After running the `Northwind.sql` file and selecting the database, we perform various operations such as filtering data, using set operations (`EXCEPT`, `INTERSECT`, `UNION`), and applying aggregate functions (`COUNT`, `SUM`, `AVG`, `MAX`).

      We also explore SQL joins to retrieve data from multiple tables like `Orders`, `Products`, and `Suppliers`. Additionally, we complete a specific task that identifies **customers with at least 15 orders after 1996**, retrieving their total orders, last order date, and average unit price, while filtering results and sorting by order count in descending order.

   </details>

---

## 🚀 How to Use
1. Navigate to the specific task or project folder.
2. Follow the instructions provided in the respective README files.

---

## 🤝 Contribution
Contributions are welcome! If you have additional tasks, improvements, or resources, feel free to:
- Open an issue to suggest changes.
- Submit a pull request with your contributions.