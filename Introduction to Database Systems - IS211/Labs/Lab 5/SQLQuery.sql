/*
 * Author(s): Mohammed Atef & George Malak.
 * Date: March 27, 2025.
 * Lab: 5.
 * Course: Introduction to Database Systems - IS211.
*/

-- After executing the Northwind.sql file, we can start writing SQL queries:
-- But first, you should select Northwind database:
USE Northwind;

/*
  Display the first name, title of all employees who live in UK and have the
  same job (title) as Janet or Steven. Sort the result by the first name of the
  employees in a descending order.
*/
SELECT FirstName, Title
FROM Employees
WHERE Country = 'UK' AND Title IN (
	SELECT Title FROM Employees
	WHERE FirstName IN ('Janet', 'Steven')
)
ORDER BY FirstName DESC;


-- Return a list of customers who has orders shipped to UK
SELECT CustomerID, CompanyName
FROM Customers
WHERE EXISTS (
	SELECT * FROM Orders 
	WHERE Customers.CustomerID = Orders.CustomerID AND ShipCountry = 'UK'
);

-- Get the distinct names for products that are always ordered with quantity greater than 10.
SELECT DISTINCT ProductName
FROM Products
WHERE NOT EXISTS (
	SELECT * FROM [Order Details] 
	WHERE [Order Details].ProductID = Products.ProductID AND Quantity < 10
);

/*
  Retrieve the last names of employees who were hired before
  all employees with the titles 'Sales Manager' or 'Inside Sales Coordinator'.
*/
SELECT LastName FROM Employees
WHERE HireDate < ALL (
	SELECT HireDate FROM Employees WHERE Title IN ('Sales Manager', 'Inside Sales Coordinator')
);

/*
  Get the supplier name (contact name) and the supplied product name for
  products having unit price less than 7. Fully optimize your query to
  minimize the cost of accessing any unneeded columns and/or rows from
  the relevant tables.
*/
SELECT S.ContactName, P.ProductName
FROM (SELECT ContactName, SupplierID FROM Suppliers) AS S, 
	 (SELECT ProductName, SupplierID, UnitPrice FROM Products WHERE UnitPrice < 7) AS P
WHERE S.SupplierID = P.SupplierID;
