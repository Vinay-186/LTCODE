select s1.gender, s1.day, sum(s2.score_points) as total 
from Scores s1
join (
select gender, day, score_points 
from Scores
group by gender, day
order by gender, day asc) as s2
where s1.gender = s2.gender and s2.day <= s1.day 
group by s1.gender, s1.day
order by s1.gender, s1.day