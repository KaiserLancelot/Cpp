# a
insert into
  course
values
  ('CS-101', 'Weekly Seminar', 'Comp. Sci', 0);
# b
insert into
  section
values
  ('CS-101', 1, 'Fall', 2009, null, null, null);
# c
insert into
  takes
select
  ID,
  'CS-101',
  1,
  'Fall',
  2009,
  null
from
  student
where
  dept_name = 'Comp. Sci';
# d
delete from
  takes
where
  ID in (
    select
      ID
    from
      student
    where
      name = 'Chavez'
  )
  and course_id = 'CS-101'
  and sec_id = 1
  and semester = 'Fall'
  and year = 2009;
# e
delete from
  course
where
  course_id = 'CS-101';
delete from
  section
where
  course_id = 'CS-101';
delete from
  takes
where
  course_id = 'CS-101';
# f
delete from
  takes
where
  course_id in (
    select
      course_id
    from
      course
    where
      lower(title) like '%database%'
  );
