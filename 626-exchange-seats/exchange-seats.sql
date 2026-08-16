# Write your MySQL query statement below
WITH cte AS
(SELECT*, LEAD(id) OVER(ORDER BY id) AS nxt_person, LAG(id) OVER(ORDER BY id) AS prev_person
FROM Seat)

SELECT  CASE WHEN id % 2 = 1 AND nxt_person IS NOT NULL THEN nxt_person WHEN id % 2 = 1 AND nxt_person IS NULL THEN id ELSE prev_person END AS id, student
FROM cte
ORDER BY id
