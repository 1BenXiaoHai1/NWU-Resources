--ʵ����
--���²��������У���Ҫ����Ƿ���Ȩ�ɹ���
--1����Enterprise Manager�£�����һ����main���û���Ĭ�����ݿ�ΪSTUDENT_DATA(Ӧ��ʵ�������ݻ���)��������һ��Ȩ�ޡ�
CREATE LOGIN Main1 WITH password ='123456';--������¼
CREATE USER main1 FROM LOGIN Main1;--�����û�
--��Ȩ
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



--2������main���û��޸�ѧ��������Ȩ���ջء�
REVOKE UPDATE(SNAME)--�޸�����Ȩ��
ON  STUDENT
TO main1;
--���
SELECT SNAME
FROM student
WHERE sno = '990101';
UPDATE  student
SET sname = 'С��'
WHERE sno = '990101';
SELECT SNAME
FROM student
WHERE sno = '990101';
--3���ջء�main���û���GRADE�������Ȩ�ޡ�
REVOKE ALL
ON GRADE
FROM main1;
SELECT * FROM grade;

--4������GRADE��Ĳ�ѯȨ���ڸ���main���û���
GRANT SELECT
ON GRADE
TO main1;
SELECT *
FROM grade;

