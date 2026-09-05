# Write your MySQL query statement below
WITH cte AS
(SELECT machine_id, process_id, MAX(timestamp) - MIN(timestamp) AS time
FROM Activity
GROUP BY machine_id,process_id)

SELECT machine_id, ROUND(AVG(time),3) AS processing_time
FROM cte 
GROUP BY machine_id