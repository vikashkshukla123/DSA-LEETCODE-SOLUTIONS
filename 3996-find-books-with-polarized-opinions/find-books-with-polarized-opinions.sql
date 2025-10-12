# Write your MySQL query statement below
WITH cte AS
(SELECT book_id, COUNT(session_id) AS num_sess, (MAX(session_rating) - MIN(session_rating)) AS rating_spread, ROUND(SUM(CASE WHEN session_rating <= 2 OR session_rating >= 4 THEN 1 ELSE 0 END)/COUNT(session_id),2) AS polarization_score, SUM(CASE WHEN session_rating <= 2 THEN 1 ELSE 0 END) AS two_or_lower, SUM(CASE WHEN session_rating >= 4 THEN 1 ELSE 0 END) AS four_or_more
FROM reading_sessions
GROUP BY book_id
)

SELECT b.*, cte.rating_spread, cte.polarization_score
FROM cte 
LEFT JOIN books b
ON cte.book_id = b.book_id
WHERE cte.num_sess >= 5
AND cte.four_or_more >=1 
AND cte.two_or_lower >= 1
AND cte.polarization_score >= 0.6
ORDER BY cte.polarization_score DESC, b.title DESC
