CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
    WITH cte AS
    (SELECT*, DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee)
    
    SELECT DISTINCT IFNULL(salary,null)
    FROM cte 
    WHERE rnk = N


      # Write your MySQL query statement below.

  );
END