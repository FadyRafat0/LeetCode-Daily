/* Write your T-SQL query statement below */
SELECT prod.product_name, sal.year, sal.price
FROM Sales AS sal
INNER JOIN Product AS prod ON sal.product_id = prod.product_id 