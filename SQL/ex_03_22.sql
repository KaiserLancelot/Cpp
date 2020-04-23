select title
from course
where (select count(title)
       from course) = (select count(distinct title)
                       from course)