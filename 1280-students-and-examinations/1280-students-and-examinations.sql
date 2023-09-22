# Write your MySQL query statement below
select t1.student_id, t1.student_name,t1.subject_name,
(case e1.subject_name 
    when NULL then 0
    else count(e1.subject_name)
    end) as attended_exams 
from 
(select s.*, sub.* from students s, subjects sub) as t1 
LEFT JOIN
examinations e1 using (student_id, subject_name) 
group by student_id, student_name, subject_name
order by t1.student_id, t1.subject_name;