# a
select
  *
from
  student natural
  left outer join takes;
(
    select
      *
    from
      student natural
      join takes
  )
union
  (
    select
      student.id,
      name,
      dept_name,
      tot_cred,
      null,
      null,
      null,
      null,
      null
    from
      student,
      takes
    where
      student.ID not in (
        select
          takes.ID
        from
          takes
      )
  )
order by
  ID;
# b
  (
    select
      *
    from
      student natural
      left outer join takes
  )
union
  # 要调整顺序
  (
    select
      ID,
      name,
      dept_name,
      tot_cred,
      course_id,
      sec_id,
      semester,
      year,
      grade
    from
      student natural
      right outer join takes
  );
(
    select
      *
    from
      student natural
      join takes
  )
union
  (
    select
      student.id,
      name,
      dept_name,
      tot_cred,
      null,
      null,
      null,
      null,
      null
    from
      student,
      takes
    where
      student.ID not in (
        select
          takes.ID
        from
          takes
      )
  )
union
  (
    select
      null,
      null,
      null,
      null,
      takes.course_id,
      takes.sec_id,
      takes.semester,
      takes.year,
      takes.grade
    from
      student,
      takes
    where
      takes.ID not in (
        select
          student.ID
        from
          student
      )
  )
order by
  ID;
