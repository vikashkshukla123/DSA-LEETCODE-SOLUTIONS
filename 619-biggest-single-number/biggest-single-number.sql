# Write your MySQL query statement below


SELECT MAX(num) AS num FROM MyNumbers WHERE num IN(
SELECT num 
FROM myNumbers
GROUP BY num
HAVING COUNT(*) = 1
)

