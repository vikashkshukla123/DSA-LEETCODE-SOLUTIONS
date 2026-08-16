# Write your MySQL query statement below
WITH cte AS
(SELECT r1.requester_id, r1.accepter_id, accept_date
FROM RequestAccepted r1
UNION 
SELECT r2.accepter_id, r2.requester_id,accept_date
FROM RequestAccepted r2),

cte2 AS
(SELECT requester_id, COUNT(*) AS friends
FROM cte
GROUP BY requester_id)

SELECT cte2.requester_id AS id , cte2.friends AS num
FROM cte2
ORDER BY friends DESC
LIMIT 1









