# Write your MySQL query statement below
WITH cte AS
(SELECT user_id, reaction, COUNT(DISTINCT content_id) AS num
FROM reactions
GROUP BY user_id, reaction),
cte2 AS
(SELECT * , SUM(num) OVER(PARTITION BY user_id) AS content_reactions, ROUND(num /  SUM(num) OVER(PARTITION BY user_id),2) AS reaction_ratio,
ROW_NUMBER() OVER(PARTITION BY user_id ORDER BY num DESC) AS rnk
FROM  cte)

SELECT user_id, reaction AS dominant_reaction, reaction_ratio
FROM cte2
WHERE content_reactions >= 5 AND
reaction_ratio >= 0.6  AND rnk = 1
ORDER BY reaction_ratio DESC , user_id 
