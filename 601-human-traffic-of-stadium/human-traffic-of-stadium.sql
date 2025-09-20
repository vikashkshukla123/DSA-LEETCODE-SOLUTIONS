# Write your MySQL query statement below
WITH cte AS
(SELECT*, id - ROW_NUMBER() OVER(ORDER BY id) AS diff
FROM Stadium
WHERE people >= 100)


SELECT id,visit_date, people
FROM cte WHERE diff IN
(SELECT diff
FROM cte
GROUP BY diff
HAVING COUNT(*) >= 3)
ORDER BY visit_date