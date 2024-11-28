/* Write your T-SQL query statement below */
SELECT 
    ST.*, 
    SB.subject_name,
    attended_exams =
    (
        SELECT 
            COUNT(*)
        FROM
            Examinations EX
        WHERE
            EX.student_id = ST.student_id AND
            EX.subject_name = SB.subject_name
    )
FROM
    Students ST
FULL OUTER JOIN Subjects SB ON 1 = 1
WHERE 
    ST.student_id IS NOT NULL AND 
    SB.subject_name IS NOT NULL
ORDER BY ST.student_id , SB.subject_name