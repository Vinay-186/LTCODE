# Write your MySQL query statement below
select c1.name as Customers from customers c1 where c1.id not in (select c.id from customers c, orders o where c.id = o.customerId);