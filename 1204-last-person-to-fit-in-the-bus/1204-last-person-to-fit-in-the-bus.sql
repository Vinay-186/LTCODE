# Write your MySQL query statement below
select person_name from queue q1
where 1000 >= (select sum(q2.weight) from queue q2 where q2.turn <= q1.turn order by turn)
order by turn desc limit 1;