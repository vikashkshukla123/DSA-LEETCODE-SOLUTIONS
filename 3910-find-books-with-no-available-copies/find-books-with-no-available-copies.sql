# Write your MySQL query statement below
WITH cte AS
(SELECT book_id, COUNT(DISTINCT record_id) AS num_b
FROM borrowing_records 
WHERE return_date IS NULL
GROUP BY book_id
)

SELECT b.book_id, b.title, b.author, b.genre, b.publication_year, c.num_b AS current_borrowers
FROM library_books AS b
LEFT JOIN cte AS c
ON b.book_id = c.book_id
WHERE b.total_copies - c.num_b = 0
ORDER BY current_borrowers DESC, b.title