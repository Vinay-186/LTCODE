# Write your MySQL query statement below
select e1.name, b.bonus from employee e1 left join bonus b using(empId) 
where b.bonus is NULL or b.bonus < 1000;