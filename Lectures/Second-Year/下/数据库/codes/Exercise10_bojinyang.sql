--实验十 数据完整性维护

--1、在STUDENT学生情况表上建立以学号为主键的列级约束。
CREATE TABLE STUDENT1
(
	SNO CHAR(6) 
	CONSTRAINT PK PRIMARY KEY, --列级约束（只有一列）
	SNAME CHAR(10),
	SEX CHAR(2),
	SAGE INT,
	DNO CHAR(4),
	DORMNO CHAR(5)
);

--2、在GRADE学生课程成绩表上建立以学号、课程号主键的表级约束。
CREATE TABLE GRADE2
(
	SNO CHAR(6),
	CNO CHAR(2),
	SCORE INT,
	CONSTRAINT PK_sno_cno PRIMARY KEY(SNO,CNO) --表级约束（多列）
);

--3、对应用实例STUDENT_DATA数据环境，用“数据库关系图”方式建立表之间的外键关系，并测试是否有效。


--4、对学生信息录入使用CHECK约束，来维护性别只能输入“男”或“女”。
CREATE TABLE STUDENT1
(
	SNO CHAR(6) PRIMARY KEY, --设置sno为主键
	SNAME CHAR(10),
	SEX CHAR(2) CHECK (SEX IN ('男','女')),--CHECK语句，限制性别只能为男女
	SAGE INT,
	DNO CHAR(4),
	DORMNO CHAR(5)
);