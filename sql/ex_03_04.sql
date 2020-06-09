# a
select count(distinct driver_id)
from (accident natural join partocopate)
       natural join car
where year = 2009

# b
insert into accident
values (10001, 20160303, "aaaaa");

insert into partocopate
select 10001, c.license, p.driver_id, 10000
from car as c,
     owns as o,
     person as p
where p.name = 'kaiser'
  and address = 'bbbbb'
  and p.driver_id = o.driver_id
  and o.license = c.license;

# c
delete
from car
where model = 'Mazda'
  and license = (
  select license
  from person,
       owns
  where name = 'John Smith'
    and owns.driver_id = person.driver_id
);