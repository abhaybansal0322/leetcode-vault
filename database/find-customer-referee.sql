# Find Customer Referee
# https://leetcode.com/problems/find-customer-referee/

# Write your MySQL query statement below
select name
from Customer
where IFNULL(referee_id,0) <> 2;