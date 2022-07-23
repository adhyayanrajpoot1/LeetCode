# Write your MySQL query statement below
SELECT author_id as id 
FROM Views 
GROUP BY author_id 
HAVING SUM(CASE WHEN author_id=viewer_id THEN 1 ELSE 0 END)>0 
ORDER BY id