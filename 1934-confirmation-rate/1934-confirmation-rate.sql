# Write your MySQL query statement below

# select t1.user_id,
# (case t1.cnt 
# where t1.cnt = 0 then 0
# else ROUND(t1.cnt / t2.total, 2)
# end) as confirmation_rate

# from 
select user_id, ifNULL(ROUND(cnt / total, 2),0) as confirmation_rate from
((select s.user_id, count(c.action) as cnt from signups s LEFT JOIN (select * from confirmations where action = 'confirmed') as c using (user_id) group by user_id) as t1
INNER JOIN
(select s.user_id, count(c.action) as total from signups s LEFT JOIN confirmations c using (user_id) group by user_id) as t2 using (user_id))
order by total;