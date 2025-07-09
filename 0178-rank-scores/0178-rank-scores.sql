SELECT 
    Score AS score,
    (
        SELECT COUNT(DISTINCT s2.Score)
        FROM Scores s2
        WHERE s2.Score >= s1.Score
    ) AS `rank`
FROM Scores s1
ORDER BY score DESC;
