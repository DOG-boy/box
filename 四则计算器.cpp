// 四则计算器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <fstream>

using namespace std;

int num(int x)
{
	return rand() % 100;
}
int sign()
{
	return rand() % 4;
}
int main()
{
	int a, i, j, n;
	
	cout << "请输入题目的数量：";
	cin >> a;
	srand(time(NULL));
	ofstream examplefile("demo.txt");
	while (1)
	{
		if (examplefile.is_open()) {
			if (a < 1)
			{
				cout << "该输入不符合输出";
				cin >> a;
			}
			else
			{
				for (j = 0; j < a; j++)
				{
					i = sign();
					switch (i)
					{
					case 0:
						examplefile << j + 1 << ":" << " " << num(1) << "+" << num(2) << "=" << "\n";
						break;
					case 1:
						examplefile << j + 1 << ":" << " " << num(1) << "-" << num(2) << "=" << "\n";
						break;
					case 2:
						examplefile << j + 1 << ":" << " " << num(1) << "*" << num(2) << "=" << "\n";
						break;
					case 3:
						n = num(2);
						if (n != 0)
						{
							examplefile << j + 1 << ":" << " " << num(1) << "/" << n << "=" << "\n";
						}
						else
						{
							j--;
						}
						break;
					}
				}
				break;
			}
		}
	}
	examplefile.close();
	return 0;
}
