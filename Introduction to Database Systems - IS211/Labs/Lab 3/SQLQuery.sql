/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 13, 2025.
 * Lab: 3.
 * Course: Introduction to Database Systems - IS211.
*/

-- After executing the Northwind.sql file, we can start writing SQL queries:
-- But first, you should select Northwind database:
USE Northwind;

-- We select all columns in Products table:
SELECT * FROM Products;

-- We select ProductID and ProductName columns in Products table:
SELECT ProductID, ProductName
FROM Products;

-- We select all columns in Products table where ProductName contains 'h' character in it:
SELECT *
FROM Products
WHERE ProductName LIKE '%h%';

-- Here, We select distinct CategoryID values in Products table:
SELECT DISTINCT CategoryID
FROM Products;

-- Get all Products where their Category is either 1 or 2:
SELECT *
FROM Products
WHERE CategoryID IN (1,2);

-------------------------------------------- JOINS --------------------------------------------
-- Get the names of products categories and the name of the company that supply these categories:
SELECT Categories.CategoryName, Suppliers.CompanyName
FROM Categories INNER JOIN Products
ON Categories.CategoryID = Products.CategoryID
INNER JOIN Suppliers
ON Products.SupplierID = Suppliers.SupplierID;

-- Get names of all products and all categories ,showing which products belong to which categories if any:
SELECT Products.ProductName, Categories.CategoryName
FROM Products FULL OUTER JOIN Categories
ON Products.CategoryID = Categories.CategoryID

-- We need to insert a new Category and a new product to be able to know the changes at the results:
INSERT INTO Categories(CategoryName) VALUES ('New Category');
INSERT INTO Products(ProductName, Discontinued) VALUES ('New Product', 0);

-- Get all combinations of Products and Suppliers ,Mentioning the names of products and the suppliers:
SELECT Products.ProductName, Suppliers.CompanyName
FROM Products CROSS JOIN Suppliers;

-------------------------------------------- OUR TASK --------------------------------------------
/*
 * Find the CompanyName and ContactName from Suppliers table and its CategoryName from Category Table.
 * Note : there is Foreign key Between Category and Product table , between Suppliers
        and Product table , but No any foreign key between Category and Suppliers Table.
*/

SELECT Suppliers.CompanyName, Suppliers.ContactName, Categories.CategoryName
FROM Products INNER JOIN Categories
ON Products.CategoryID = Categories.CategoryID
INNER JOIN Suppliers
ON Products.SupplierID = Suppliers.SupplierID;