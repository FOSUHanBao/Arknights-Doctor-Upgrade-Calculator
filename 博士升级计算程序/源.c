//һ����ʿ�����������V1.0��
#include<stdio.h>
#define EXP_PER_SANITY 12//1���ǻ�12����
#define MIN_PER_SANITY 6//6���ӻָ�1����
int main(void)
{
	int EXP_per_level[120];//����һ���洢ÿ��һ�����辭�������
	int a = 3;
	EXP_per_level[0] = 500;//1��2���辭��
	EXP_per_level[1] = 800;//2��3���辭��
	EXP_per_level[2] = 1240;//3��4���辭��
	while (a < 28)//3��29����1240Ϊ���80Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 80;
		a++;
	}
	while (a < 34)//29��35����3350Ϊ���110Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 110;
		a++;
	}
	while (a < 51)//35��52����3900Ϊ���300Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 300;
		a++;
	}
	while (a < 65)//52��66����9000Ϊ���500Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 500;
		a++;
	}
	while (a < 101)//66��102����20000Ϊ���1000Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 1000;
		a++;
	}
	while (a < 110)//102��111����52000Ϊ���2000Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 2000;
		a++;
	}
	while (a < 120)//111��121�������ڣ�����70000Ϊ���3000Ϊ����ĵȲ�����
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 3000;
		a++;
	}
	int Accumulated_EXP[120];//����һ���洢ÿһ���ۻ����������
	int b = 1, c;
	Accumulated_EXP[0] = 0;//1���ۻ�����Ϊ0
	while (b < 120)//����ÿһ�����ۻ�����
	{
		for (c = 0;c < b;c++)
			Accumulated_EXP[b] = Accumulated_EXP[b-1] + EXP_per_level[c];
		b++;
	}
	int Current_Level, //Ŀǰ�ĵȼ�
		Current_EXP, //Ŀǰ������
		Target_Level, //Ŀ��ȼ�
		minutes, //������
		hours, //Сʱ��
		days, //����
		time, //�ܼ�ʱ��
		EXP_1, //Ŀǰ�ۻ�����
		EXP_2, //������������
		sanity;//���ĵ�����
	int status_1, status_2, i;
	printf("��ӭʹ�ò�ʿ�����������������ĸ���˳����򣩡�\n");
	while (1)
	{
		printf("��������Ŀǰ�ĵȼ���1��-119������");
        if (scanf_s("%d", &Current_Level) == 0)//�������Ĳ����������������
			break;
		while (Current_Level < 1 || Current_Level>119)
			//�������ĵȼ��Ƿ���1-119��Χ��
		{
			printf("������ȼ����ڷ�Χ�ڣ����������룺");
			scanf_s("%d", &Current_Level);
		}
		printf("��������Ŀǰ������ֵ��");
		if (scanf_s("%d", &Current_EXP) == 0)//�������Ĳ����������������
			break;
		while (Current_EXP >= Accumulated_EXP[Current_Level] - Accumulated_EXP[Current_Level - 1] || Current_EXP < 0)
			//������������ֵ�Ƿ���ڵ�ǰ�ȼ�����һ�ȼ����辭���С��0
		{
			printf("����������ֵ�������������룺");
			scanf_s("%d", &Current_EXP);
		}
		printf("��������Ҫ�����ĵȼ���2��-120������");
		if (scanf_s("%d", &Target_Level) == 0)//�������Ĳ����������������
		    break;
		while (Target_Level <= Current_Level || Target_Level > 120)
			//��������Ŀ��ȼ��Ƿ�С�ڻ���ڵ�ǰ�ȼ�
		{
			printf("������ĵȼ��������������룺");
			scanf_s("%d", &Target_Level);
		}
		EXP_1 = Accumulated_EXP[Current_Level - 1] + Current_EXP;//��Ŀǰ�ۻ�����
		EXP_2 = Accumulated_EXP[Target_Level - 1] - EXP_1;//��������������
		sanity = EXP_2 / EXP_PER_SANITY;//����Ҫ���ĵ�����
		if (EXP_2 % EXP_PER_SANITY > 0)//���������������С��12�����1����
			sanity += 1;
		time = sanity * MIN_PER_SANITY;//���ܼ���Ҫ��ʱ��
		days = time / 1440;//������
		hours = (time - 1440 * days) / 60;//��Сʱ
		minutes = (time - 1440 * days) % 60;//�����
		status_1 = printf("��Ŀǰ�ܹ���%d����������%d����Ҫ%d����������%d����", EXP_1, Target_Level, EXP_2, sanity);
		status_2 = printf("��������Ȼ�ָ�ʱ���ܼ�%d��%dСʱ%d���ӣ���\n", days, hours, minutes);
		for (i = 1;i < (status_1 + status_2);i++)
			printf("-");//����printf()�ķ���ֵ��ӡ�ָ���
		printf("\n");
	}
	printf("�����ѽ�������л����ʹ�ã�\n");
	return 0;
}
