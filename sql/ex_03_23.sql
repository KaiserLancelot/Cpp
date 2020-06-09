select course_id, semester, sec_id, avg(tot_cred)
from takes
       natural join student
where year = 2009
group by course_id, semester, year, sec_id
having count(ID) >= 2