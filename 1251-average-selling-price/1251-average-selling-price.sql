# Write your MySQL query statement below
select p.product_id, ifNULL(ROUND(sum(p.price * u.units)/ sum(u.units), 2),0) as average_price 
from 
prices p
LEFT JOIN 
unitssold u
using (product_id)
where purchase_date between start_date and end_date or purchase_date is NULL group by product_id;