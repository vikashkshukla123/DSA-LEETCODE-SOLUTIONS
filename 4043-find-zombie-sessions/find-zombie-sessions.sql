# Write your MySQL query statement below
WITH cte AS
(SELECT session_id, user_id, TIMESTAMPDIFF(MINUTE, MIN(event_timestamp), MAX(event_timestamp)) AS ses_dur, SUM(CASE WHEN event_type = 'scroll' THEN 1 ELSE 0 END) AS num_scroll, 
SUM(CASE WHEN event_type = 'click' THEN 1 ELSE 0 END)/SUM(CASE WHEN event_type = 'scroll' THEN 1 ELSE 0 END) AS click_to_scroll,
SUM(CASE WHEN event_type = 'purchase' THEN 1 ELSE 0 END) AS num_p
FROM app_events
GROUP BY user_id, session_id)


SELECT session_id,user_id, ses_dur AS session_duration_minutes, num_scroll AS scroll_count
FROM cte 
WHERE ses_dur > 30
AND num_scroll >= 5
AND click_to_scroll < 0.20
AND num_p = 0
ORDER BY scroll_count DESC, session_id