SELECT DISTINCT a.Num AS ConsecutiveNums
FROM Logs a
JOIN Logs b ON a.Id = b.Id - 1
JOIN Logs c ON b.Id = c.Id - 1
WHERE a.Num = b.Num AND b.Num = c.Num;
