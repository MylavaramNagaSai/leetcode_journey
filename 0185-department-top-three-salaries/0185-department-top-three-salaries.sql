SELECT Department, Name AS Employee, Salary
FROM (
    SELECT 
        d.Name AS Department,
        e.Name,
        e.Salary,
        DENSE_RANK() OVER (PARTITION BY e.DepartmentId ORDER BY e.Salary DESC) AS `rank`
    FROM Employee e
    JOIN Department d ON e.DepartmentId = d.Id
) ranked
WHERE `rank` <= 3;
