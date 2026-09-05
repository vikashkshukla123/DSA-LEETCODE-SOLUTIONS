# Write your MySQL query statement below
WITH cte AS
(SELECT*, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk
FROM Employee),

cte2 AS
(SELECT id, name, salary,departmentId
FROM cte
WHERE rnk <= 3)

SELECT d.name AS Department, c.name AS Employee ,c.salary AS Salary
FROM cte2 c
LEFT JOIN Department d
ON c.departmentId = d.id


