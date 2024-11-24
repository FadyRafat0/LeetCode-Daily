/* Write your T-SQL query statement below */
SELECT uniemp.unique_id, emp.name AS name
FROM Employees AS emp
LEFT JOIN EmployeeUNI AS uniemp ON emp.id = uniemp.id