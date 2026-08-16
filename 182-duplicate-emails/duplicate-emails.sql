# Write your MySQL query statement below
SELECT Person.email
FROM Person
GROUP BY email
HAVING (COUNT(*)) > 1
