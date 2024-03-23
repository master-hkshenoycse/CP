
select id,visit_date,people
from (
    select id,
    visit_date,
    people,
    lead(people,1) over (order by id) nxt1,
    lead(people,2) over (order by id) nxt2,
    lag(people,1) over (order by id) prev1,
    lag(people,2) over (order by id) prev2
    from Stadium
) a
where (a.people>=100 and a.nxt1>=100 and a.nxt2>=100)
or (a.people>=100 and a.nxt1>=100 and a.prev1>=100)
or (a.people>=100 and a.prev1>=100 and a.prev2>=100);