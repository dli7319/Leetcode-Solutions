# Write your MySQL query statement below

select class from
(select class, count(*) as cnt from
(select distinct student, class from `courses`)
as tbla group by class)
as tblb where cnt>=5;
