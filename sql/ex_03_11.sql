# a
select
  distinct name
from
  (
    takes natural
    join course
  )
  join student using (ID)
where
  course.dept_name = 'Comp. Sci.';
#b
select
  ID,
  name
from
  student
where
  ID not in (
    select
      ID
    from
      student natural
      join takes
    where
      year < 2009
  );
# c
select
  dept_name,
  max(salary)
from
  instructor
group by
  dept_name;
# d
select
  dept,
  min(value)
from
  (
    select
      dept_name,
      max(salary)
    from
      instructor
    group by
      dept_name
  ) as query(dept, value)
