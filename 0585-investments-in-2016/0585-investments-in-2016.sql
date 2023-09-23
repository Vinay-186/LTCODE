# Write your MySQL query statement below
select ROUND(sum(tiv_2016),2) as tiv_2016 from insurance where
tiv_2015 IN (
select tiv_2015 from insurance group by tiv_2015 having count(*) > 1) 
and CONCAT(lat, " ",lon) IN (select CONCAT(lat, " ", lon) as coor from insurance group by coor having count(*) = 1);