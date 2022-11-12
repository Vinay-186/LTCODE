# Write your MySQL query statement below
select w.id 
from
weather w, weather w1
where datediff(w.recorddate, w1.recorddate) = 1 and w.temperature > w1.temperature;