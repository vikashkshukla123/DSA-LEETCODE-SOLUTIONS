# Write your MySQL query statement below
WITH cte AS
(SELECT*,DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as rnk
FROM Employee)


SELECT d.name AS Department, c.name AS Employee , c.salary 
FROM cte c
LEFT JOIN
Department d
ON c.departmentId = d.id
WHERE rnk = 1;



