//一个博士升级计算程序（V1.0）
#include<stdio.h>
#define EXP_PER_SANITY 12//1理智换12声望
#define MIN_PER_SANITY 6//6分钟恢复1理智
int main(void)
{
	int EXP_per_level[120];//设置一个存储每升一级所需经验的数组
	int a = 3;
	EXP_per_level[0] = 500;//1升2所需经验
	EXP_per_level[1] = 800;//2升3所需经验
	EXP_per_level[2] = 1240;//3升4所需经验
	while (a < 28)//3升29是以1240为首项，80为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 80;
		a++;
	}
	while (a < 34)//29升35是以3350为首项，110为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 110;
		a++;
	}
	while (a < 51)//35升52是以3900为首项，300为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 300;
		a++;
	}
	while (a < 65)//52升66是以9000为首项，500为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 500;
		a++;
	}
	while (a < 101)//66升102是以20000为首项，1000为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 1000;
		a++;
	}
	while (a < 110)//102升111是以52000为首项，2000为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 2000;
		a++;
	}
	while (a < 120)//111升121（不存在）是以70000为首项，3000为公差的等差数列
	{
		EXP_per_level[a] = EXP_per_level[a - 1] + 3000;
		a++;
	}
	int Accumulated_EXP[120];//设置一个存储每一级累积经验的数组
	int b = 1, c;
	Accumulated_EXP[0] = 0;//1级累积经验为0
	while (b < 120)//计算每一级的累积经验
	{
		for (c = 0;c < b;c++)
			Accumulated_EXP[b] = Accumulated_EXP[b-1] + EXP_per_level[c];
		b++;
	}
	int Current_Level, //目前的等级
	    Current_EXP, //目前的声望
	    Target_Level, //目标等级
	    minutes, //分钟数
	    hours, //小时数
	    days, //天数
	    time, //总计时间
	    EXP_1, //目前累积声望
	    EXP_2, //升级所需声望
	    sanity;//消耗的理智
	int status_1, status_2, i;
	printf("欢迎使用博士升级计算程序（输入字母可退出程序）。\n");
	while (1)
	{
		printf("请输入您目前的等级（1级-119级）：");
                if (scanf_s("%d", &Current_Level) == 0)//如果输入的不是数字则结束程序
			break;
		while (Current_Level < 1 || Current_Level>119)
			//检测输入的等级是否在1-119范围内
		{
			printf("您输入等级不在范围内，请重新输入：");
			scanf_s("%d", &Current_Level);
		}
		printf("请输入您目前的声望值：");
		if (scanf_s("%d", &Current_EXP) == 0)//如果输入的不是数字则结束程序
			break;
		while (Current_EXP >= Accumulated_EXP[Current_Level] - Accumulated_EXP[Current_Level - 1] || Current_EXP < 0)
			//检测输入的声望值是否大于当前等级升下一等级所需经验或小于0
		{
			printf("您输入声望值有误，请重新输入：");
			scanf_s("%d", &Current_EXP);
		}
		printf("请输入您要升到的等级（2级-120级）：");
		if (scanf_s("%d", &Target_Level) == 0)//如果输入的不是数字则结束程序
		    break;
		while (Target_Level <= Current_Level || Target_Level > 120)
			//检测输入的目标等级是否小于或等于当前等级
		{
			printf("您输入的等级有误，请重新输入：");
			scanf_s("%d", &Target_Level);
		}
		EXP_1 = Accumulated_EXP[Current_Level - 1] + Current_EXP;//求目前累积声望
		EXP_2 = Accumulated_EXP[Target_Level - 1] - EXP_1;//求升级所需声望
		sanity = EXP_2 / EXP_PER_SANITY;//求需要消耗的理智
		if (EXP_2 % EXP_PER_SANITY > 0)//如果升级所需声望小于12，则加1理智
			sanity += 1;
		time = sanity * MIN_PER_SANITY;//求总计需要的时间
		days = time / 1440;//求天数
		hours = (time - 1440 * days) / 60;//求小时
		minutes = (time - 1440 * days) % 60;//求分钟
		status_1 = printf("您目前总共有%d声望，升到%d级需要%d声望，消耗%d理智", EXP_1, Target_Level, EXP_2, sanity);
		status_2 = printf("（理智自然恢复时间总计%d天%d小时%d分钟）。\n", days, hours, minutes);
		for (i = 1;i < (status_1 + status_2);i++)
			printf("-");//根据printf()的返回值打印分割线
		printf("\n");
	}
	printf("程序已结束，感谢您的使用！\n");
	return 0;
}
