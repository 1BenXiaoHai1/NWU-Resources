--实验五
--以下操作过程中，需要检查是否授权成功。
--1、在Enterprise Manager下，创建一个“main”用户，默认数据库为STUDENT_DATA(应用实例中数据环境)，且享有一切权限。
CREATE LOGIN Main1 WITH password ='123456';--创建登录
CREATE USER main1 FROM LOGIN Main1;--创建用户
--授权
GRANT SELECT,UPDATE,DELETE,INSERT
ON  STUDENT
TO main1;
GRANT SELECT,UPDATE,DELETE,INSERT
ON  GRADE
TO main1;
GRANT SELECT,UPDATE,DELETE,INSERT
ON  DORM
TO main1;
GRANT SELECT,UPDATE,DELETE,INSERT
ON  DEPARTMENT
TO main1;



--2、将“main”用户修改学生姓名的权限收回。
REVOKE UPDATE(SNAME)--修改姓名权限
ON  STUDENT
TO main1;
--检查
SELECT SNAME
FROM student
WHERE sno = '990101';
UPDATE  student
SET sname = '小明'
WHERE sno = '990101';
SELECT SNAME
FROM student
WHERE sno = '990101';
--3、收回“main”用户对GRADE表的所有权限。
REVOKE ALL
ON GRADE
FROM main1;
SELECT * FROM grade;

--4、将对GRADE表的查询权限授给“main”用户。
GRANT SELECT
ON GRADE
TO main1;
SELECT *
FROM grade;

