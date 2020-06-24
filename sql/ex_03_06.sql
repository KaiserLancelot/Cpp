select
  dept_name
from
  instructor
where
  lower(dept_name) like '%sci%';
