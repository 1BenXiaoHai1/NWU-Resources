--ʵ��ʮ ����������ά��

--1����STUDENTѧ��������Ͻ�����ѧ��Ϊ�������м�Լ����
CREATE TABLE STUDENT1
(
	SNO CHAR(6) 
	CONSTRAINT PK PRIMARY KEY, --�м�Լ����ֻ��һ�У�
	SNAME CHAR(10),
	SEX CHAR(2),
	SAGE INT,
	DNO CHAR(4),
	DORMNO CHAR(5)
);

--2����GRADEѧ���γ̳ɼ����Ͻ�����ѧ�š��γ̺������ı�Լ����
CREATE TABLE GRADE2
(
	SNO CHAR(6),
	CNO CHAR(2),
	SCORE INT,
	CONSTRAINT PK_sno_cno PRIMARY KEY(SNO,CNO) --��Լ�������У�
);

--3����Ӧ��ʵ��STUDENT_DATA���ݻ������á����ݿ��ϵͼ����ʽ������֮��������ϵ���������Ƿ���Ч��


--4����ѧ����Ϣ¼��ʹ��CHECKԼ������ά���Ա�ֻ�����롰�С���Ů����
CREATE TABLE STUDENT1
(
	SNO CHAR(6) PRIMARY KEY, --����snoΪ����
	SNAME CHAR(10),
	SEX CHAR(2) CHECK (SEX IN ('��','Ů')),--CHECK��䣬�����Ա�ֻ��Ϊ��Ů
	SAGE INT,
	DNO CHAR(4),
	DORMNO CHAR(5)
);