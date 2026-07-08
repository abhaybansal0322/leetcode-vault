# Big Countries
# https://leetcode.com/problems/big-countries/

# Write your MySQL query statement below
select w.name, w.population, w.area
from World w
where w.area >= 3000000 OR w.population >= 25000000;