# Write your MySQL query statement below
WITH cte as
(SELECT *, SUM(weight) OVER(ORDER BY turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS Total
FROM Queue)

SELECT person_name
FROM cte
WHERE total <= 1000
ORDER BY total DESC
LIMIT 1

