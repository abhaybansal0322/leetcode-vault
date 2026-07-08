# Customer Who Visited but Did Not Make Any Transactions
# https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/

# Write your MySQL query statement below
select v.customer_id , COUNT(v.customer_id) AS count_no_trans
from Visits v 
Left Join Transactions t
ON v.visit_id  = t.visit_id
where t.transaction_id is NULL
Group By v.customer_id