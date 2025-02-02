/* Write your T-SQL query statement below */
SELECT
    project_id,
    ROUND(AVG(experience_years*1.0), 2) "average_years"
FROM
    Project P
LEFT JOIN 
    Employee E ON P.employee_id = E.employee_id  
GROUP BY
    project_id