/* Write your T-SQL query statement below */
SELECT
    E.name
FROM
    Employee E
INNER JOIN Employee E2 ON
    E.id = E2.managerId
GROUP BY
     E.id,
     E.name
HAVING
    COUNT(*) >= 5
