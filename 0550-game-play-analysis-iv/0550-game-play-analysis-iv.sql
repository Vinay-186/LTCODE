# Write your MySQL query statement below
select ROUND(count(*)/(select count(distinct player_id) from activity),2) as fraction from (select player_id, event_date from activity a1 where
(player_id, DATE_SUB(event_date, INTERVAL 1 DAY)) in 
(select player_id, min(event_date) from activity group by player_id)) as t1;