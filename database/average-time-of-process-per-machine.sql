# Average Time of Process per Machine
# https://leetcode.com/problems/average-time-of-process-per-machine/

# Write your MySQL query statement below
select m1.machine_id , ROUND(AVG(m2.timestamp - m1.timestamp),3) AS processing_time
from Activity m1
inner join Activity m2
ON m1.machine_id = m2.machine_id
    AND m1.process_id = m2.process_id
    AND m1.activity_type = 'start'
    AND m2.activity_type = 'end'
GROUP BY m1.machine_id