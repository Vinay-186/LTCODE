# Write your MySQL query statement below
select q1.person_name from queue q1, queue q2
where q1.turn >= q2.turn group by q1.person_id 
having sum(q2.weight) <= 1000
order by q1.turn desc limit 1