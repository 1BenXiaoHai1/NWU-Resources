--ʵ����

--����һ��ѧ����¼��������insert into table���� values�������
insert into student(
	sno,
	sname,
	sex,
	sage,
	dno,
	dormno
)
values(
	'980101',
	'�º�',
	'Ů',
	21,
	'4',
	'2303'
);

select *from student;

--��DEPARTMENTԺϵ���в�����ʷϵ��������insert ���
select *from department; --�ȿ�һ��department������û����ʷϵ
insert into department(
	dno,
	dname
)
values(
	'5',
	'��ʷϵ'
);

select *from department;

--�������ݱ�Gradel�� ����99����ѧ��ѡ�����ݿ�ԭ��ġ�û�з�����ѧ�����뵽Gradel����
CREATE TABLE GRADE1
(SNO CHAR(6),
CNO CHAR(2),
SCORE INT
)
INSERT INTO GRADE1
SELECT *
FROM GRADE
WHERE SNO  LIKE '99%' AND CNO='01' AND SCORE IS NULL;

SELECT * FROM GRADE1


--�޸�ѧ��Ϊ980101��ѧ������Ϊ�º� ����Ϊ20��������update...set...where...���
select *from student;

update student
set sname = '�º�'
where sno = '980101';

select *from student; -- ����Ƿ��޸ĳɹ�

--��course�γ���Ϣ��û�����޿εĿγ̵�ѧ������2�֡������ݵĸ���update���
select *from course where cpno is NULL; -- ��ֵ���Ĳ�ѯҪ��is NULL �������� = NULL����ѯ

update course
set credit = credit + 2
where cpno is NULL;

select *from course where cpno is NULL; -- ��ѯ�ж��Ƿ���ĳɹ�


--������ϵ������ѧ�������ݿ�ԭ��ɼ���Ϊ���
select *from student where dno in (select dno from department where dno = '3');--��ѯ����ϵ��ѧ��

update grade
set score = 0
where sno in
	(
		select sno from student where dno = '3'
	) and cno = '01'; --��������������ѧ�����в�ѯѧ�ţ���Ҫ��ѯ��ѧ�ŵ�ϵΪ����ϵ3��
	
select *from grade where sno in (select sno from student where dno = '3');--�ж��Ƿ��޸ĳɹ�

--ɾ��98������ѧ������Ϣ��������delete���
select *from student where LEFT(sno,2)='98'; 

delete 
from student
where LEFT(sno,2)='98';--��ѯ98��ѧ�� ʹ�����ݿ��Դ�left������ȡ�ַ���

select *from student where LEFT(sno,2)='98'; --��ѯ�Ƿ�ɾ���ɹ�