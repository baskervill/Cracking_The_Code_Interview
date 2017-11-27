select StudentName, GPA
from(
    select top 10 percent Avg(CourseEnrollment.Grade) AS GPA,
   CourseEnrollment.StudentID
    from CourseEnrollment
    group by CourseEnrollment.StudentID
    order by Avg(CourseEnrollment.Grade)) Honors
inner join Students on Honors.StudentID = Students.StudentID