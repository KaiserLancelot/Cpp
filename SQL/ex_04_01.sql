# a
select ID,
       name,
       count(course_id)
from instructor
       natural left outer join teaches
group by ID, name;

# b
select ID,
       name,
       (
         select count(course_id)
         from teaches
         where teaches.ID = instructor.ID
       )
from instructor;

# c
select course_id, name
from instructor
       natural join teaches
       natural right outer join section
where section.year = 2010
  and section.semester = 'Spring';

# d
select dept_name, count(ID)
from department
       natural left outer join instructor
group by dept_name