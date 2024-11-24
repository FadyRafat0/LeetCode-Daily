/* Write your T-SQL query statement below */
SELECT name
FROM Customer
where referee_id is null or referee_id <> 2
