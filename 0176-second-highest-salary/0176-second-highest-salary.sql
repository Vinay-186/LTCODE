# Write your MySQL query statement below
select max(salary) as secondhighestsalary from employee e1 
where e1.salary < (select max(salary) from employee)