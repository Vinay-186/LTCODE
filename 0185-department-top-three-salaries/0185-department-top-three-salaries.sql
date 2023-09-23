# Write your MySQL query statement below
with cte as (
select d.name, e.name as employee, e.salary 
from employee e INNER JOIN department d on e.departmentId = d.id)

select c1.name as department, c1.employee, c1.salary from cte c1
where 3 > (select count(distinct c2.salary) from cte c2 where c2.salary > c1.salary
          and c1.name = c2.name);