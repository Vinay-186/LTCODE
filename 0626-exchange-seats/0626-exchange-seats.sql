# Write your MySQL query statement below
select s1.id, s2.student from seat s1 INNER JOIN seat s2
on s2.id = s1.id + 1 and s1.id % 2 = 1

UNION 
select s2.id, s1.student from seat s1 INNER JOIN seat s2
on s2.id = s1.id + 1 and s2.id % 2 = 0

UNION 
select id, student from seat where id = (select max(id) from seat) and id % 2 = 1

order by id;