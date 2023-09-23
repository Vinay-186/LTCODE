# Write your MySQL query statement below
with cte as(
(select requester_id as person, count(distinct accepter_id) as cnt from requestaccepted group by requester_id)
UNION ALL 
(select accepter_id as person, count(distinct requester_id) as cnt from requestaccepted group by accepter_id))

select person as id, sum(cnt) as num from cte group by person order by num desc limit 1;