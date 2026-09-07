# Write your MySQL query statement below
select
    firstName,
    lastName,
    city,
    state
FROM
    Person
Left Join
    Address
    on Person.personId = Address.personId;
