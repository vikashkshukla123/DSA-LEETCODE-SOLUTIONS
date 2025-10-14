# Write your MySQL query statement below
WITH cte AS
(SELECT customer_id, COUNT(DISTINCT order_id) AS total_orders ,ROUND(COUNT(DISTINCT CASE WHEN (TIME(order_timeStamp) BETWEEN '11:00:00' AND '14:00:00') OR (TIME(order_timeStamp) BETWEEN '18:00:00' AND '21:00:00') THEN order_id ELSE NULL END) / COUNT(DISTINCT order_id)*100) AS peak_hour_percentage, ROUND(AVG(order_rating),2) AS average_rating, COUNT(DISTINCT CASE WHEN order_rating IS NOT NULL THEN order_id ELSE NULL END)/COUNT(DISTINCT order_id) AS orders_rated
FROM restaurant_orders
GROUP BY customer_id)

SELECT customer_id, total_orders,peak_hour_percentage, average_rating
FROM cte 
WHERE total_orders >= 3
AND peak_hour_percentage >= 60
AND average_rating >= 4.0
AND orders_rated >= 0.5
ORDER BY average_rating DESC , customer_id DESC