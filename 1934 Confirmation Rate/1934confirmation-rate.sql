/* Write your T-SQL query statement below */
SELECT
    s.user_id,
    confirmation_rate = (
        ROUND(COUNT(CASE WHEN action = 'Confirmed' THEN 1 END) * 1.0 
        / COUNT(*), 2)
    )
FROM
    Signups s
LEFT OUTER JOIN
    Confirmations c ON s.user_id = c.user_id
GROUP BY
    s.user_id;