# Write your MySQL query statement below
WITH cte AS
(SELECT p1.*, p2.category
FROM ProductPurchases AS p1
LEFT JOIN ProductInfo AS p2
ON p1.product_id = p2.product_id)


SELECT c1.category AS category1, c2.category AS category2, COUNT(DISTINCT c1.user_id) AS customer_count
FROM cte AS c1
LEFT JOIN cte AS c2
ON c1.user_id = c2.user_id
AND c1.category < c2.category
WHERE c2.category IS NOT NULL
GROUP BY c1.category ,c2.category
HAVING COUNT(DISTINCT c1.user_id) >= 3
ORDER BY customer_count DESC ,category1,category2
