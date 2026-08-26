# Write your MySQL query statement below



# Write your MySQL query statement below
WITH cte AS
(SELECT user_id, COUNT(*) AS totalPrompts , ROUND(SUM(tokens) / COUNT(*),2) AS avg_tokens, MAX(tokens) AS maxi_token
FROM prompts
GROUP BY user_id)

SELECT user_id, totalPrompts AS prompt_count, avg_tokens
FROM cte 
WHERE totalPrompts >= 3 AND avg_tokens < maxi_token
ORDER BY avg_tokens DESC, user_id








