select Dept_Name, Departments.Dept_ID, count(*) as 'num_emplyees'
from Departments
left join Employees
on Employees.Dept_ID = Departments.Dept_ID
group by Departments.Dept_ID, Dept_Name