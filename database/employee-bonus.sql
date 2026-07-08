# Employee Bonus
# https://leetcode.com/problems/employee-bonus/

# Write your MySQL query statement below
select E.name , B.bonus
from Employee E
LEFT JOIN Bonus B
ON E.empId = B.empId
WHERE B.bonus is NULL OR B.bonus < 1000
