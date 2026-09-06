-- # Write your MySQL query statement below
WITH cte AS
(SELECT *, ROW_NUMBER() OVER(PARTITION BY store_id ORDER BY price DESC) AS maxi ,  ROW_NUMBER() OVER(PARTITION BY store_id ORDER BY price ) AS mini
FROM inventory),

cte2 AS
(SELECT store_id, MAX(CASE WHEN maxi = 1 THEN product_name ELSE NULL END) AS most_exp_product, MAX(CASE WHEN mini = 1 THEN product_name ELSE NULL END) AS cheapest_product,SUM(CASE WHEN maxi = 1 THEN quantity ELSE 0 END) AS exp_qty,SUM(CASE WHEN mini = 1 THEN quantity ELSE 0 END) AS cheap_qty
FROM cte
GROUP BY store_id
HAVING COUNT(DISTINCT product_name) >= 3),

cte4 AS(
SELECT store_id, most_exp_product, cheapest_product, ROUND((cheap_qty / exp_qty),2) AS imbalance_ratio
FROM cte2
WHERE cheap_qty > exp_qty)

SELECT c.store_id,s.store_name,s.location,c.most_exp_product,c.cheapest_product, imbalance_ratio
FROM cte4 c
LEFT JOIN stores s
ON c.store_id = s.store_id
ORDER BY imbalance_ratio DESC, store_name
