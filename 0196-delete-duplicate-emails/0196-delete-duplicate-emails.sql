# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
delete from Person p
where p.id 
IN ( select pid from(
    select p1.id as pid from person p1 , person p2 where p1.email = p2.email and p1.id > p2.id) as id);