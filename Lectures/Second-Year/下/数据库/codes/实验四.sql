--实验四 数据查询、试图操作

--查询‘1’系的全体学生的学号、姓名和宿舍情况，结果按宿舍号升序排列。
SELECT	sno,sname,dormno
FROM student
WHERE dno = '1'
ORDER BY dormno ASC;

--查询‘1’系的全体学生的详细记录，结果按性别升序、年龄降序排列。
SELECT *
FROM student
WHERE dno = '1'
ORDER BY sex ,sage DESC;

--查询‘2’系的姓名和其出生年月(以2003年为标准)，并用“BIRTHDAY”改变结果标题。
SELECT sname,2003-sage BIRTHDAY 
FROM student;

--查询GRADE表中所有被学生选修课程号。
SELECT DISTINCT cno --注意消除重复元素
FROM grade;

--查询年龄在21-23之间（包括21和23）的学生姓名，宿舍号。
SELECT sname,dormno
FROM student
WHERE sage BETWEEN 21 AND 23;

--查询‘2’系、‘3’系和‘4’系的学生姓名。
SELECT sname
FROM student
WHERE dno in ('2','4','5');

--查询所有姓‘张’的学生情况。
SELECT *
FROM student
WHERE sname LIKE '张%' --张%表示以张开头 任意长度的字符串

--查询姓名中第二个字为“明”的学生情况
SELECT *
FROM student
WHERE sname LIKE '_明%' -- -符号表示任意单字符

--查询COURSE表中没有先修课程的课程名和教师情况
SELECT cname,teacher
FROM course
WHERE cpno IS NULL --NULL不能用'='


--查询‘1’系的所有男学生的信息
SELECT *
FROM student
WHERE sex = '男' AND dno = '1';

--查询所有‘1’系的学生人数。
SELECT COUNT(sno)
FROM student
WHERE dno = '1';

--查询‘1’系选修‘01’号课程的最高分、最低分和平均分。（聚集函数、嵌套查询）
--最高分 MAX函数
SELECT MAX(score)
FROM grade
WHERE cno='01'AND sno IN (SELECT sno FROM student WHERE dno = '1');

--最低分 MIN函数
SELECT MIN(score) 
FROM grade
WHERE cno = '01' AND sno IN (SELECT sno FROM student WHERE dno = '1');

--平均分
SELECT AVG(score)
FROM grade
WHERE cno = '01' AND sno IN (SELECT sno FROM student WHERE dno = '1');

--查询选修了4门以上课程的学生学号、姓名。(嵌套查询、分组)
SELECT sno,sname
FROM student
WHERE sno IN 
		(	SELECT sno
			FROM grade
			GROUP BY sno
			HAVING COUNT(*)>3);

--给出所有院系领导检查学生宿舍的所有可能。
SELECT DORMNO,TEACHER  FROM  DORM,COURSE  

--查询所有学生及其宿舍情况。(等值连接)
SELECT student.*,dorm.* --为*
FROM student,dorm
WHERE student.dormno = dorm.dormno; 

--查询所有课程的间接先修课。(自身连接)
SELECT FIRST.cno,SECOND.cpno
FROM course FIRST,course SECOND
WHERE FIRST.cpno=SECOND.cno; --将两张表通过cpno和cno连接起来

--查询所有学生及其选修课程情况。（外连接）
SELECT student.sno,sname,sex,sage,cno,score
FROM student LEFT OUTER JOIN grade ON(student.sno = grade.sno);

--查询所有已选修课程的学生的学号、姓名、选修的课程名和授课教师信息。(多表连接)
SELECT student.sno,sname,cname,teacher
FROM student,grade,course
WHERE student.sno = grade.sno AND grade.cno = course.cno;

--查询是系主任‘秦峰’的学生的姓名和宿舍联系电话。
SELECT student.sname,dorm.tele
FROM student,dorm
WHERE student.dormno = dorm.dormno 
		AND student.dno IN 
				(
					SELECT dno 
					FROM department
					WHERE head = '秦峰'
				);

--查询其他系比‘计算机系’所有学生年龄大的学生姓名和年龄。（所有：ALL 带有ANY（SOME）或ALL的子查询）
SELECT sname,sage
FROM student
WHERE sage<ALL(SELECT sage
				FROM student
				WHERE dno = '1');

--查询选修课程库没有不及格分数的学生。
SELECT *
FROM student
WHERE NOT EXISTS
		(
			SELECT *
			FROM grade	
			WHERE student.sno = grade.sno AND score<60); 

--查询至少选修了‘1’号和‘2’号课程的学生号码。
select sno  
from grade  
WHERE cno IN ('01','02')  
GROUP BY sno  
HAVING COUNT(cno)>1  

--查询至少选修了‘990102’学生的全部课程的学生学号。
SELECT DISTINCT SNO  
FROM GRADE X  
WHERE NOT EXISTS  
(SELECT *  
FROM GRADE Y  
WHERE Y.SNO='990102'AND NOT EXISTS   
(SELECT *  
FROM GRADE Z  
WHERE Z.SNO=X.SNO AND Z.CNO=Y.CNO))  

--查询‘1’系的学生与年龄大于20岁的学生的差集。(集合操作)
SELECT *
FROM student
WHERE dno = '1'
EXCEPT --差集
SELECT *
FROM student
WHERE sage>20;

--查询选修“数据库原理”的学生与选修“高等数学”的学生的交集。
SELECT *
FROM student
WHERE sno IN 
		(
			SELECT sno
			FROM grade
			WHERE cno IN (SELECT cno FROM course WHERE cname ='数据库原理' )
		)
UNION
SELECT *
FROM student
WHERE sno IN 
		(
			SELECT sno
			FROM grade
			WHERE cno IN (SELECT cno FROM course WHERE cname ='高等数学' )
		);

--创建“计算机”系的所有男生的视图VIEW_1（要求反映出学生的出生年份）。
CREATE VIEW VIEW_1(sno,sname,sex,sage,sbirh,dno,dormno)
AS 
SELECT sno,sname,sex,sage,2003-sage,dno,dormno
FROM student
WHERE dno = '1';


--在视图VIEW_1中找出名字中有“原”字的学生的学号、姓名、宿舍号。
SELECT sno,sname,dormno
FROM VIEW_1
WHERE sname LIKE '%原%' ; --%表示字符串数量不限

--修改视图VIEW_1中的学生“李军”的年龄为23，宿舍号为“2202”。
UPDATE VIEW_1
SET sage = 23,dormno = '2202'
WHERE sname='李军';
--检查是否修改成功
SELECT *
FROM VIEW_1;