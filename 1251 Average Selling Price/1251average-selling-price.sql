/* Write your T-SQL query statement below */
SELECT
    P.product_id,
    ISNULL(ROUND(SUM(P.price * US.units) * 1.0 / SUM(US.units), 2), 0) "average_price"
FROM
    Prices P
LEFT JOIN   
    UnitsSold US ON
        P.product_id = US.product_id AND 
        US.purchase_date <= P.end_date AND 
        DATEDIFF(day, US.purchase_date, P.end_date) <= DATEDIFF(day, P.start_date, P.end_date)
GROUP BY 
    P.product_id