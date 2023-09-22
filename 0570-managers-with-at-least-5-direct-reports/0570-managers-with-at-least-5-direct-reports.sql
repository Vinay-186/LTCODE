# Write your MySQL query statement below
select e1.name from employee e1
where 5 <= (select count(*) from employee e2 where e2.managerid = e1.id)