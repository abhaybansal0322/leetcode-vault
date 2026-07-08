# Recyclable and Low Fat Products
# https://leetcode.com/problems/recyclable-and-low-fat-products/

# Write your MySQL query statement below

Select p.product_id 
from Products p
where p.low_fats = "Y"
AND
p.recyclable = "Y";