# Write your MySQL query statement below
WITH cte as
(SELECT product_id, SUM(unit) AS unit_feb
FROM Orders
WHERE YEAR(order_date) = 2020
AND MONTH(order_date) = 2
GROUP BY product_id)

SELECT p.product_name, c.unit_feb AS unit
FROM cte c
LEFT JOIN Products p
ON c.product_id = p.product_id
WHERE c.unit_feb >= 100
