# a
select
  id,
  course_id,
  sec_id,
  semester,
  year,
  building,
  room_number,
  time_slot_id
from
  (
    select
      *
    from
      teaches natural
      join section
  ) as q(
    id,
    course_id,
    sec_id,
    semester,
    year,
    building,
    room_number,
    time_slot_id
  )
where
  exists(
    select
      room_number
    from
      teaches natural
      join section
    where
      q.sec_id = sec_id
      and q.semester = semester
      and q.year = year
      and q.time_slot_id = time_slot_id
      and q.room_number <> room_number
  )
order by
  ID
