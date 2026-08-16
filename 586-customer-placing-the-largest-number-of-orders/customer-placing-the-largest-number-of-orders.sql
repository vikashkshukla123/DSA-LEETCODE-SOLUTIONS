# Write your MySQL query statement below
WITH cte AS
(SELECT customer_number, COUNT(DISTINCT order_number) AS numOrders
FROM Orders
GROUP BY customer_number)
SELECT customer_number
FROM cte
WHERE numOrders = (SELECT MAX(numOrders) FROM cte)
