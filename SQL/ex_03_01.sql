# a
select title
from course
where dept_name = 'Comp. Sci.'
  and credits = 3;

# b
select distinct takes.ID
from takes,
     instructor,
     teaches
where instructor.name = 'Einstein'
  and instructor.ID = teaches.ID
  and teaches.course_id = takes.course_id;

# c
select max(salary) as max_salary
from instructor;

# d
with max_salary(value) as (
  select max(salary)
  from instructor
)
select id, name, dept_name, salary
from instructor,
     # 需要加上这个
     max_salary
where salary = max_salary.value;

select id, name, dept_name, salary
from instructor
where salary = (
  select max(salary)
  from instructor
);

# e sec_id 指课程段
select course_id, sec_id, count(ID)
from section
       natural join takes
where semester = 'Fall'
  and year = 2009
group by course_id, sec_id;

# f
select max(num)
from (select count(ID)
      from section
             natural join takes
      where semester = 'Fall'
        and year = 2009
      group by course_id, sec_id)
       as query(num);

# g
with query as (
  select course_id, sec_id, count(ID) as value
  from section
         natural join takes
  where semester = 'Fall'
    and year = 2009
  group by course_id, sec_id)
select course_id, sec_id
from query
where value = (
  select max(value)
  from query
)