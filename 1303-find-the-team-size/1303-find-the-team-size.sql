# Write your MySQL query statement below
with tab as
(select team_id, count(team_id) as team_size
from employee
group by team_id)

select e.employee_id, t.team_size from
employee e, tab t
where e.team_id = t.team_id;