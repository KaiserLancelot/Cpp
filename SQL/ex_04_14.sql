create view tot_credits(year, num_credits) as (
  select year, count(credits)
  from takes
         natural join course
  group by year
);