# Write your MySQL query statement below 
select t.id,
case 
when p_id is null then 'Root'
when id in (select id from tree where id not in(select distinct t1.p_id from tree t1 where t1.p_id is not null)) then 'Leaf'
else 'Inner'
end as type
from tree t;