/* Write your T-SQL query statement below */
SELECT
    R.contest_id,
    ROUND(COUNT(*)*1.0 * 100 / (SELECT COUNT(*) FROM Users), 2) percentage
FROM
    Register R
GROUP BY
    R.contest_id
ORDER BY 
    percentage DESC, R.contest_id