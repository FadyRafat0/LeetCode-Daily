/* Write your T-SQL query statement below */
SELECT 
    V.customer_id, 
    count(*) AS count_no_trans
FROM 
    Visits AS V
LEFT JOIN
    Transactions T
ON 
    V.visit_id = T.visit_id
WHERE
    t.transaction_id IS NULL
GROUP BY 
    V.customer_id