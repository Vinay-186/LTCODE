# Write your MySQL query statement below
select e.employee_id,
case 
    when e.employee_id % 2 = 1 and e.name not like 'M%' then e.salary
    else 0
end as bonus 
from employees e
order by employee_id;