drop table grade_point;
create table grade_point (
  grade_e varchar(2),
  points real,
  primary key (grade_e)
);
insert into
  grade_point
values
  ('A', 4);
insert into
  grade_point
values
  ('A-', 3.7);
insert into
  grade_point
values
  ('B+', 3.3);
insert into
  grade_point
values
  ('B', 3);
insert into
  grade_point
values
  ('B-', 2.7);
insert into
  grade_point
values
  ('C+', 2.3);
insert into
  grade_point
values
  ('C', 2);
insert into
  grade_point
values
  ('C-', 1.5);
insert into
  grade_point
values
  ('F', 1);
# a
select
  sum(points)
from
  takes,
  grade_point
where
  ID = '12345'
  and grade = grade_e;
# b
select
  sum(points) / (
    select
      sum(credits)
    from
      takes natural
      join course
    where
      ID = '12345'
  )
from
  takes,
  grade_point
where
  ID = '12345'
  and grade = grade_e;
# c
select
  a.ID,
  (
    round(
      (
        select
          sum(points) / (
            select
              sum(credits)
            from
              takes as b natural
              join course
            where
              b.ID = a.ID
          )
        from
          takes as c,
          grade_point
        where
          c.ID = a.ID
          and grade = grade_e
      ),
      3
    )
  )
from
  takes as a
group by
  ID;
