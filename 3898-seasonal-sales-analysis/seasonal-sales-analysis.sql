# Write your MySQL query statement below
WITH cte AS
(SELECT s.*, p.category, CASE WHEN MONTH(s.sale_date) IN (12,1,2) THEN 'Winter' WHEN MONTH(s.sale_date) IN (3,4,5) THEN 'Spring' WHEN MONTH(s.sale_date) IN (6,7,8) THEN 'Summer'
ELSE 'Fall' END AS season
FROM sales AS s
LEFT JOIN products AS p
ON s.product_id = p.product_id
),
cte2  AS
(SELECT season, category, SUM(quantity) AS total_quantity, SUM(quantity * price) AS total_revenue
FROM cte
GROUP BY season, category),

cte3 AS
(SELECT*, ROW_NUMBER() OVER(PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC) AS rnk
FROM cte2)

SELECT season, category, total_quantity, total_revenue
FROM cte3
WHERE rnk = 1