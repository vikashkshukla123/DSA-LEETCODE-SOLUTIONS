# Write your MySQL query statement below
WITH cte AS
(SELECT* ,DENSE_RANK() OVER(PARTITION BY player_id ORDER BY event_date) AS rnk
FROM Activity)
SELECT c.player_id, c.event_date AS first_login
FROM cte c
WHERE c.rnk = 1