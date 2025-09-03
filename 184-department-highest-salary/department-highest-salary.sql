# Write your MySQL query statement below
WITH cte AS
(SELECT e.name AS Employee , e.salary , d.name AS Department, MAX(e.salary) OVER(PARTITION BY e.departmentId) AS max_salary
FROM Employee e
LEFT JOIN Department d
ON e.departmentId = d.Id)


SELECT department, employee, salary
FROM cte
WHERE salary = max_salary
