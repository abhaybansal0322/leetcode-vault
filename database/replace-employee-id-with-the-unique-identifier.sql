# Replace Employee ID With The Unique Identifier
# https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/

# Write your MySQL query statement below
select eu.unique_id,e.name
from Employees e
LEFT JOIN EmployeeUNI eu
ON e.id = eu.id