/* Write your T-SQL query statement below */
SELECT
    query_name,
    ROUND(AVG(rating*1.0 / position), 2) "quality",
    ROUND(AVG((CASE WHEN rating  < 3 THEN 1.0 ELSE 0.0 END) *100), 2) "poor_query_percentage"
FROM
    Queries
GROUP BY
    query_name