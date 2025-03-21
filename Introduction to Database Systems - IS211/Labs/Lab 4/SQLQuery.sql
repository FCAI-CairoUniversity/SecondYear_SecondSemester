/*
 * Author(s): Mohammed Ahmed & Amr ElDahshan.
 * Date: March 20, 2025.
 * Lab: 4.
 * Course: Introduction to Database Systems - IS211.
*/

-- After executing the Northwind.sql file, we can start writing SQL queries:
-- But first, you should select Northwind database:
USE Northwind;

-- Get the customers IDS who didn’t make any order.
SELECT CustomerID FROM Customers 
EXCEPT SELECT CustomerID FROM Orders;

/*
  Get all names of suppliers who supply products of category named
  ‘Beverages’ and products of category named ‘Condiments’
*/
SELECT Suppliers.CompanyName
FROM Products, Suppliers, Categories
WHERE Suppliers.SupplierID = Products.SupplierID AND Products.CategoryID = Categories.CategoryID AND Categories.CategoryName = 'Beverages'
INTERSECT
SELECT Suppliers.CompanyName
FROM Products, Suppliers, Categories
WHERE Suppliers.SupplierID = Products.SupplierID AND Products.CategoryID = Categories.CategoryID AND Categories.CategoryName = 'Condiments';

/*
  For a mass-mailing purpose, get the list of all names, addresses, cities and
  postal codes known to the database and remove duplicates from the result
  if any (these data are stored in the customers and employees tables).
*/
SELECT ContactName AS Name, Address, City, PostalCode
FROM Customers
UNION
SELECT FirstName + ' ' + LastName AS Name, Address, City, PostalCode
FROM Employees;

/*
  For each product ordered in March 1998, get the product id, number of
  orders for that product and the total quantity ordered. Give suitable
  name(s) for any unnamed displayed column(s). Sort by total quantity
  descendingly.
*/
SELECT ProductID, count(od.orderid) AS numOfOrders, Sum(quantity) AS totalQuantityOrdered
FROM [Order Details] od, orders o
WHERE od.OrderID = o.OrderID AND year(OrderDate) ='1998' AND month(OrderDate) = '3'
GROUP BY ProductID
Order by TotalQuantityOrdered desc;

/*
  Get the supplier names (Contact names) and the total number of
  supplied products for each supplier, for only those suppliers that supplied
  more than 3 products. Give suitable name(s) for any unnamed displayed
  column(s).
*/
SELECT ContactName, Count (ProductID) AS NumberOfSuppliedProducts
FROM Products, Suppliers
where Products.SupplierID = Suppliers.SupplierID
GROUP BY ContactName
HAVING Count (ProductID) > 3;

-------------------------------------------- OUR TASK --------------------------------------------
/*
  For all customers with at least 15 orders after 1996, get the customer id,
  total number of orders, the last order date and the average unit price for
  products in his/her orders . Give suitable name(s) for any unnamed
  displayed column(s). Display the result starting from customers with
  the highest number of orders.
*/
SELECT CustomerID, COUNT (o.OrderID) AS NumberOfOrders, MAX (OrderDate) AS LastOrderDate, Avg(Unitprice) as AveragePrice
FROM Orders o, [order details] od
WHERE o.OrderID = od.orderid AND YEAR(OrderDate) > 1996
GROUP BY CustomerID
HAVING COUNT (o.OrderID) > 15 AND Avg(unitPrice) > 25
ORDER BY COUNT (o.OrderID) DESC;