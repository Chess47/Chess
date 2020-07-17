#pragma once
//已引用#include<iostream>
//已命名using namespace std;

//含有控制台输出位置操作方法
//含有整型转字符串String方法
//含有二维字符数组拷贝方法
//含有时间日期类
//常用数学方法
//随机数生成方法
//

//常用键盘按键ACSII码
#ifndef _KEYBOARD_COMMON_
#define _KEYBOARD_COMMON_

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define ESC 27

#endif // !_KEYBOARD_COMMON_

//自定义方向宏
#ifndef _MY_DIRECTION_
#define _MY_DIRECTION_

#define UP_DIRECTION 1
#define DN_DIRECTION 2
#define LT_DIRECTION 3
#define RT_DIRECTION 4

#endif // !_MY_DIRECTION_

//数字、字符、数组间的常用宏
#ifndef _STRING_NUMBER_OP_
#define _STRING_NUMBER_OP_

#define FROM_LARGE_SMALL 5
#define FROM_SMALL_LARGE 6

#define SMALLER 5
#define BIGGER 6

#endif //!_STRING_NUMBER_OP_

//时间日期类的有关引用宏
#ifndef _TIME_CLASS_
#define _TIME_CLASS_

#define NORMAL_TIME 0	//hh:mm:ss
#define COMMON_TIME 1	//hh-mm-ss  
#define HALF_TIME 2		//(12h) 

#define NORMAL_DATE 0	//yyyy/mm/dd
#define COMMON_TIME 1	//yyyy-mm-dd  
#define ALLOW_WEEK 2	//(+ week) 

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SET 9
#define OCT 10
#define NOV 11
#define DEC 12

#define MONDAY 1
#define TUESDAY 1
#define WENSDAY 1
#define THURSDAY 1
#define FIRDAY 1
#define SATURDAY 1
#define SUNDAY 1

#endif // !_TIMESTYLE_CLASS_

//数学方法有关宏
#ifndef _NUMBER_FIELD_
#define _NUMBER_FIELD_

#define COMPLETE_NUMBER 141
#define DEFICIENT_NUMBER 142
#define ABUNDANT_NUMBER 143

#define MCD GetMaxnimumCommonDivisor
#define LCM GetLowestCommonMultiple

#define FLOAT_MIN 5.35898e-06
#define PI 3.1415926535898
#define E 2.718281828459

#define AP Arrangement
#define CP Combination

#endif // !_NUMBER_FIELD_

//随机数相关宏
#ifndef _RANDNUMBER_OP_
#define _RANDNUMBER_OP_

#define SRANDINIT(); srand((unsigned int)time(0));

#define MAX_PRECISION 0.00001
#define DEFAULT_PRECISION 0.01

#endif // !_RANDNUMBER_OP_

//矩阵类有关宏
#ifndef _MATRIX_CLASS_
#define _MATRIX_CLASS_

#define _T_ MatrixTransposition()
#define _Y_ InverseMatrix()
#define _A_ AdjugateMatrix
#define _a_ AlgebraicCofactor
#define _r_ Rank()
#define _Det Det()
#define _D_ Diff()
#define _I_ Integrate

#endif // _MATRIX_CLASS_

#include <stdlib.h>

//常用STD指令
#ifndef _STD_COMMAND_
#define _STD_COMMAND_

#define CLS system("cls");
#define PAUSE system("pause");

#endif // !_STD_COMMAND_

#include <Windows.h>

//控制台界面下有关方法
#ifdef _STD_COMMAND_

//改变控制台输出位置
void ChangeToXY(short nx, short ny);
//指定位置输出0~9
bool SetXY2Num(short nx, short ny, int num);
//指定位置输出字符串，并将光标移至指定位置
bool SetXY2Str(short nx, short ny, const char * str, short endx, short endy);
//指定位置输出字符串，并选择是否将光标移至原点
void SetXY2Str(short nx, short ny, const char * str, bool isRest = false);

#endif // _STD_COMMAND_

#include <string>
#include <sstream>

#include <iostream>
using namespace std;

//数字、字符、数组间的常用方法
#ifdef _STRING_NUMBER_OP_

//数字转字符串
string Change_i2s(int num);
//获取整形位数
int GetLength(int num);
//正整型数分解，并返回位数
int* NumResolve(unsigned int num,int &length);

//数组排序
template<class T>
void Sort(T* &num, int length, int style);
//下一顺序数
void NextSort(unsigned int* num, int length, int style);

//指定大小生成二维数组
char** Create_2Demenssion_Array_Size(int lines, int colomns);
//拷贝数组内容到新的空数组
void Copy_Array_2EmptyArray(char* Empty_Array, char* SameSize_Array);
void Copy_Array_2EmptyArray(char* Empty_Array, const char* SameSize_Array);

#endif // !_STRING_NUMBER_OP_

//时间日期操作类
#ifdef _TIME_CLASS_

//判断是否为闰年
bool JudgeBissextile(int year);

//时间类
class MY_TIME
{
private:
	int hour, minute, second;
public:
	MY_TIME(int ihour = 0, int iminute = 0, int isecond = 0)
	{
		hour = ihour;
		minute = iminute;
		second = isecond;
	}
	MY_TIME(long iseconds = 0)
	{
		second = iseconds % 60;
		minute = (iseconds / 60) % 60;
		hour = (iseconds / 3600) % 24;
	}
	MY_TIME(MY_TIME& other)
	{
		second = other.GetSecond();
		minute = other.GetMinute();
		hour = other.GetHour();
	}
	int GetHour() { return hour; }
	int GetMinute() { return minute; }
	int GetSecond() { return second; }
	friend ostream& operator<< (ostream &os, const MY_TIME &c)
	{
		return os << c.hour << ":" << c.minute << ":" << c.second;
	}
	friend istream& operator>>(istream &is, MY_TIME &c)
	{
		return is >> c.hour >> c.minute >> c.second;
	}
	MY_TIME& operator + (long seconds)
	{
		long _this = 3600 * hour + 60 * minute + second;
		_this += seconds;
		return *(new MY_TIME(_this));
	}
	MY_TIME& operator - (long seconds)
	{
		long _this = 3600 * hour + 60 * minute + second;
		_this -= seconds;
		return *(new MY_TIME(_this));
	}
	long operator - (MY_TIME& other) { return *this - other; }
	MY_TIME& operator = (unsigned long seconds)
	{
		second = seconds % 60;
		minute = (seconds / 60) % 60;
		hour = (seconds / 3600) % 24;
		return *this;
	}
	MY_TIME& operator = (MY_TIME& other)
	{
		long _other = 3600 * other.GetHour() + 60 * other.GetMinute() + other.GetSecond();
		return (*this = _other);
	}
	operator long() { return 3600 * hour + 60 * minute + second; }
	int AddTime(unsigned int ihour = 0, unsigned int iminute = 0, unsigned int isecond = 0)
	{
		long _this = 3600 * hour + 60 * minute + second;
		_this += 3600 * ihour + 60 * iminute + isecond;
		*this = _this;
		return _this % (86400);
	}
	int MinueTime(unsigned int ihour = 0, unsigned int iminute = 0, unsigned int isecond = 0)
	{
		int day = 0;
		long _this = 3600 * hour + 60 * minute + second;
		_this -= 3600 * ihour + 60 * iminute + isecond;
		while (0 > _this)
		{
			_this += 86400;
			day++;
		}
		*this = _this;
		return day;
	}
	const char * GetStr(int style = 0)
	{
		switch (style)
		{
		case NORMAL_TIME:
			return (Change_i2s(hour).append(":").append(Change_i2s(minute)).append(":").append(Change_i2s(second))).c_str();
			break;
		case NORMAL_TIME | HALF_TIME:
		{
			if (12 > hour) return (Change_i2s(hour).append(":").append(Change_i2s(minute)).append(":").append(Change_i2s(second)).append(" AM")).c_str();
			else return (Change_i2s(hour).append(":").append(Change_i2s(minute)).append(":").append(Change_i2s(second)).append(" PM")).c_str();
			break;
		}
		case COMMON_TIME:
			return (Change_i2s(hour).append("-").append(Change_i2s(minute)).append("-").append(Change_i2s(second))).c_str();
		case COMMON_TIME | HALF_TIME:
		{
			if (12 > hour) return (Change_i2s(hour).append("-").append(Change_i2s(minute)).append("-").append(Change_i2s(second)).append(" AM")).c_str();
			else return (Change_i2s(hour).append("-").append(Change_i2s(minute)).append("-").append(Change_i2s(second)).append(" PM")).c_str();
			break;
		}
		}
	}
};

//日期类
class MY_DATE
{
private:
	int year, month, day, week;
	void CWeek()
	{
		int nYear = year, nMonth = month;
		if (1 == nMonth || 2 == nMonth)
		{
			nMonth += 12;
			nYear--;
		}
		int temp = day + 2 * nMonth + (3 * (nMonth + 1)) / 5 - nYear / 100 + nYear / 400 + nYear / 4 + nYear;
		week = (temp % 7) + 1;
	}
public:
	MY_DATE(MY_DATE& other)
	{
		year = other.GetYear(), month = other.GetMonth(), day = other.GetDay();
		CWeek();
	}
	MY_DATE(unsigned short iyrr = 1900, unsigned short imon = JAN, unsigned short iday = 1) :year(iyrr), month(imon), day(iday)
	{
		CWeek();
	}
	MY_DATE(long days)
	{
		if (1 >= days)
		{
			year = 1900, month = JAN, day = 1;
			CWeek();
		}
		else
		{
			bool is = FALSE;
			int nYear = 1900, nMonth = JAN;
			int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
			for (;; nYear++)
			{
				if (JudgeBissextile(nYear)) MonthDays[FEB - 1] = 29;
				else MonthDays[FEB - 1] = 28;
				for (; nMonth <= DEC; nMonth++)
				{
					if (MonthDays[nMonth - 1] >= days)
					{
						year = nYear, month = nMonth, day = days;
						CWeek();
						is = 1;
						break;
					}
					days -= MonthDays[nMonth - 1];
				}
				if (is) break;
				nMonth = JAN;
			}
		}
	}
	int GetYear() { return year; }
	int GetMonth() { return month; }
	int GetDay() { return day; }
	int GetWeek() { return week; }
	friend ostream& operator<< (ostream &os, const MY_DATE& c)
	{
		return os << c.year << "/" << c.month << "/" << c.day;
	}
	friend istream& operator>>(istream &is, MY_DATE& c)
	{
		return is >> c.year >> c.month >> c.day;
	}
	operator long()
	{ 
		int nYear = year, nMonth = month;
		long days = day;
		int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (; 1900 <= nYear; nYear--)
		{
			if (JudgeBissextile(nYear)) MonthDays[FEB - 1] = 29;
			else MonthDays[FEB - 1] = 28;
			for (; nMonth >= JAN; nMonth--)
			{
				days += MonthDays[nMonth - 1];
			}
			nMonth = DEC;
		}
		return days;
	}
	MY_DATE& operator = (long days)
	{
		if (1 >= days) return *(new MY_DATE(1900, JAN, 1));
		int nYear = 1900, nMonth = JAN;
		int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (;; nYear++)
		{
			if (JudgeBissextile(nYear)) MonthDays[FEB - 1] = 29;
			else MonthDays[FEB - 1] = 28;
			for (; nMonth <= DEC; nMonth++)
			{
				if (MonthDays[nMonth - 1] >= days)
				{
					return *(new MY_DATE(nYear, nMonth, int(days)));
				}
				days -= MonthDays[nMonth - 1];
			}
			nMonth = JAN;
		}
	}
	MY_DATE& operator = (MY_DATE& other)
	{
		long days = *this;
		return (*this = days);
	}
	long operator - (MY_DATE& other) { return(*this - other); }
	MY_DATE& operator + (long days)
	{
		long NewDays = *this + days;
		return *(new MY_DATE(NewDays));
	}
	MY_DATE& operator - (long days)
	{
		long NewDays = *this - days;
		return *(new MY_DATE(NewDays));
	}
	void AddDate(unsigned int iYear = 0, unsigned int iMonth = 0, unsigned int iDay = 0)
	{
		int nYear = year + iYear, nMonth = month + iMonth, nDay = day + iDay;
		int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		while (DEC < nMonth)
		{
			nMonth -= 12;
			nYear++;
		}
		if (JudgeBissextile(nYear)) MonthDays[FEB - 1] = 29;
		while (MonthDays[nMonth - 1] < nDay)
		{
			nDay -= MonthDays[nMonth - 1];
			nMonth++;
			if (DEC < nMonth)
			{
				nMonth -= 12;
				nYear++;
			}
		}
		year = nYear, month = nMonth, day = nDay;
		CWeek();
	}
	void MinuDate(unsigned int iYear = 0, unsigned int iMonth = 0, unsigned int iDay = 0)
	{
		int nYear = year - iYear, nMonth = month - iMonth, nDay = day - iDay;
		int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		while (JAN > nMonth)
		{
			nMonth += 12;
			nYear--;
		}
		if (JudgeBissextile(nYear)) MonthDays[FEB - 1] = 29;
		while (0 > nDay)
		{
			nDay += MonthDays[nMonth - 1];
			nMonth--;
			if (JAN > nMonth)
			{
				nMonth += 12;
				nYear--;
			}
		}
		year = nYear, month = nMonth, day = nDay;
		CWeek();
	}
	const char * GetStr(int style = 0)
	{
		const char * WEEK[7] = { "Monday","Tuesday","Wensday","Thurday","Friday","Saturday","Sunday" };
		switch (style)
		{
		case NORMAL_DATE:
			return (Change_i2s(year).append("/").append(Change_i2s(month)).append("/").append(Change_i2s(day))).c_str();
			break;
		case NORMAL_TIME | ALLOW_WEEK:
		{
			return (Change_i2s(year).append("/").append(Change_i2s(month)).append("/").append(Change_i2s(day)).append(WEEK[week])).c_str();
			break;
		}
		case COMMON_TIME:
			return (Change_i2s(year).append("-").append(Change_i2s(month)).append("-").append(Change_i2s(day))).c_str();
		case COMMON_TIME | ALLOW_WEEK:
		{
			return (Change_i2s(year).append("-").append(Change_i2s(month)).append("-").append(Change_i2s(day)).append(WEEK[week])).c_str();
			break;
		}
		}
	}
};

#endif // _TIME_CLASS_

//数学方法
#ifdef _NUMBER_FIELD_

//交换两个数
template<class T>
void Swap(T & num1, T & num2);

//获得符号
template<class T>
int Sign(T num);

//阶乘
long Factorial(int n);
//排列数
long Arrangement(unsigned int n, unsigned int m);
//组合数
long Combination(unsigned int n, unsigned int m);
//伽马函数
double Gamma(double n);
//贝塔函数
double Beta(double x,double y);
//求最大公约数
unsigned int GetMaxnimumCommonDivisor(unsigned int num1, unsigned int num2);
//求最小公倍数
unsigned int GetLowestCommonMultiple(unsigned int num1, unsigned int num2);
//判断是否为质数
bool JudgePrime(int x);
//列出所有因数，并判断是否为质数
bool JudgePrime(int x, int* &pFactors, unsigned int &pFactorsCount);
//质因数分解
bool PrimeFactorization(int x, int* &pFactors, unsigned int &pFactorsCount);
//完全数判断
int JudgePerfect(int x);
//亲密数判断，若是亲密数，则返回亲密数对，否则返回0
int JudgeClose(int x);
//水仙花数判断
bool JudgeNarcissistic(long x);
//水仙花数寻找
long NextNarcissistic(long x);
//自守数判断
int JudgeAutomorphic(int x);
//距离计算
double Distance(double x1, double y1, double x2, double y2);

#endif // !_NUMBER_FIELD_

#include<time.h>
#include<stdlib.h>

//随机数方法
#ifdef _RANDNUMBER_OP_

//单概率产生随机数(0 <= p <= 1)，p的概率产生0，1-p的概率产生1
bool GetRandBool(double p);
//双概率产生随机数(0 <= p1 <= p2 <=1)，p1的概率产生1，p2-p1的概率产生2,1-p2的概率产生3
int GetRandPSS(double p1, double p2);
//指定区间[a,b]均匀产生整形随机数
int GetRandInt(int a, int b);
//指定区间[a,b]与精度均匀产生浮点随机数
double GetRandFloat(double a, double b, double precision);
//以指定期望与标准差产生正态分布型随机数
double GetRandNormal(double average, double standard);

#endif // !_RANDNUMBER_OP_

#include<conio.h>

//按键类
#ifdef _KEYBOARD_COMMON_

//按键检测类
class KEY
{
private:
	unsigned char isShift : 1;//0 is off,1 is on
	unsigned char isCtrl : 1;//0 is off,1 is on
	unsigned char isAlt : 1;//0 is off,1 is on
	unsigned char isOperate : 1;//0 is off,1 is on//is or not operate key
	unsigned char : 4;
	unsigned char nKey : 8;//0~256//ASCII
public:
	KEY()
	{
		Clear();
	}
	KEY& Check()
	{
		Clear();
		if (_kbhit())
		{
			if (224 == (nKey = _getch()))
			{
				nKey = _getch();
				isOperate = 1;
			}
			if (GetKeyState(VK_SHIFT) < 0) isShift = 1;
			if (GetKeyState(VK_CONTROL) < 0) isCtrl = 1;
		}
		return *this;
	}
	KEY& Wait()
	{
		Clear();
		while (1)
		{
			if (_kbhit())
			{
				if (224 == (nKey = _getch()))
				{
					nKey = _getch();
					isOperate = 1;
				}
				if (GetKeyState(VK_SHIFT) < 0) isShift = 1;
				if (GetKeyState(VK_CONTROL) < 0) isCtrl = 1;
				return *this;
			}
		}
	}
	void Clear()
	{
		isShift = 0, isCtrl = 0, isAlt = 0, isOperate = 0, nKey = 0;
	}
};

//自定义异步按键检测函数
int ReadKey();

#endif // _KEYBOARD_COMMON_

#include <math.h>

//复数类
#ifdef _NUMBER_FIELD_

//复数类
class Complex
{
private:
	double Real, Image;
	void ADJ()
	{
		if (-FLOAT_MIN < Real && Real < FLOAT_MIN) Real = 0;
		if (-FLOAT_MIN < Image && Image < FLOAT_MIN) Image = 0;
	}
public:
	Complex(double fReal = 0.0, double fImage = 0.0) :Real(fReal), Image(fImage) { ADJ(); }
	double GetReal() const { return Real; }
	double GetImage() const { return Image; }
	double Module() const { return sqrt(Real * Real + Image * Image); }
	double AngleP() const { return atan2(Image, Real); } // <= | PI |
	double AngleD() const { return (AngleP() * 180) / PI; } // <= | 180°|
	friend ostream& operator<< (ostream &os, const Complex &c)
	{
		if (0 > c.Image) return os << "( " << c.Real << " - " << -c.Image << "i )";
		else if (0 < c.Image) return os << "( " << c.Real << " + " << c.Image << "i )";
		else return os << c.Real;
	}
	friend istream& operator>>(istream &is, Complex &c)
	{
		return is >> c.Real >> c.Real;
	}
	Complex operator - (void) { return Complex(-Real, -Image); }
	Complex operator ~ (void) { return Complex(Real, -Image); }
	Complex operator + (const double c) { return Complex(Real + c, Image); }
	Complex operator - (const double c) { return Complex(Real - c, Image); }
	Complex& operator = (const double c)
	{
		Real = c, Image = 0;
		ADJ();
		return *this;
	}
	Complex& operator = (const Complex &c)
	{
		Real = c.GetReal(), Image = c.GetImage();
		ADJ();
		return *this;
	}
	Complex& operator += (const double c)
	{
		Real += c;
		ADJ();
		return *this;
	}
	Complex& operator -= (const double c)
	{
		Real -= c;
		ADJ();
		return *this;
	}
	Complex operator * (const double c) { return Complex(Real * c, Image * c); }
	Complex operator / (const double c) { return Complex(Real / c, Image / c); }
	Complex& operator *= (const double c)
	{
		Real = Real * c;
		Image = Image * c;
		ADJ();
		return *this;
	}
	Complex& operator /= (const double c)
	{
		Real = Real / c;
		Image = Image / c;
		ADJ();
		return *this;
	}
	bool operator == (const double c) { return (Real == c && 0 == Image); }
	Complex operator + (const Complex &c) { return Complex(Real + c.GetReal(), Image + c.GetImage()); }
	Complex operator - (const Complex &c) { return Complex(Real - c.GetReal(), Image - c.GetImage()); }
	Complex& operator += (const Complex &c)
	{
		Real += c.GetReal();
		Image += c.GetImage();
		ADJ();
		return *this;
	}
	Complex& operator -= (const Complex &c)
	{
		Real -= c.GetReal();
		Image -= c.GetImage();
		ADJ();
		return *this;
	}
	Complex operator * (const Complex &c) { return Complex(Real * c.GetReal() - Image * c.GetImage(), Real * c.GetImage() + Image * c.GetReal()); }
	Complex operator / (const Complex &c)
	{
		double _c = c.GetReal() * c.GetReal() + c.GetImage() * c.GetImage();
		double rec = (Real * c.GetReal()) / _c, img = (Image * c.GetImage()) / _c;
		return Complex(rec, img);
	}
	Complex& operator *= (const Complex &c)
	{
		Real = Real * c.GetReal() - Image * c.GetImage();
		Image = Real * c.GetImage() + Image * c.GetReal();
		ADJ();
		return *this;
	}
	Complex& operator /= (const Complex &c)
	{
		double _c = c.GetReal() * c.GetReal() + c.GetImage() * c.GetImage();
		Real = (Real * c.GetReal()) / _c;
		Image = (Image * c.GetImage()) / _c;
		ADJ();
		return *this;
	}
	bool operator == (const Complex &c) { return (Real == c.GetReal() && Image == c.GetImage()); }
	Complex operator ^ (const double c)
	{
		double m = pow(Module(), c);
		double d = AngleP() * c;
		while (PI < d || -PI > d)
		{
			if (PI < d) d -= PI;
			else if (-PI > d) d += PI;
		}
		return Complex(m * cos(d), m * sin(d));
	}
	Complex& operator ^= (const double c)
	{
		double m = pow(Module(), c);
		double d = AngleP() * c;
		while (PI < d || -PI > d)
		{
			if (PI < d) d -= PI;
			else if (-PI > d) d += PI;
		}
		Real = m * cos(d), Image = m * sin(d);
		ADJ();
		return *this;
	}
	Complex operator ^ (const Complex &c)
	{
		Complex A((*this) ^ (c.GetReal()));
		Complex B(Complex(log(Module()), AngleP()) * (c.GetImage()));
		A *= B.GetReal(), B = Complex(cos(B.GetReal()), sin(B.GetImage()));
		return A * B;
	}
	Complex& operator ^= (const Complex &c)
	{
		Complex A((*this) ^ (c.GetReal()));
		Complex B(Complex(log(Module()), AngleP()) * (c.GetImage()));
		A *= B.GetReal(), B = Complex(cos(B.GetReal()), sin(B.GetImage()));
		*this = A * B;
		ADJ();
		return *this;
	}
};

//复对数
Complex Ln(const Complex& c);
//复正弦
Complex Sin(const Complex& c);
//复余弦
Complex Cos(const Complex& c);
//复数开n次方根
Complex* Sqt(const Complex &c, unsigned int n);

#endif // _NUMBER_FIELD_

//几何坐标类
#ifndef _COORDINATE_
#define _COORDINATE_

//(矢量)2维点坐标类
typedef class POSITION2D
{
private:
	double X, Y;
	int nType;//记号
	double nToward;//矢量向
	POSITION2D * pNextNode;//矢量位
public:
	POSITION2D(double nx, double ny, int type = 1, double toward = 0, POSITION2D * NextNode = NULL) :X(nx), Y(ny), nType(type), nToward(toward), pNextNode(NextNode) {}
	double Toward(double nx, double ny)
	{ 
		nToward = atan2(ny - Y, nx - X);
		return Distance(nx, ny);
	}
	double Toward(POSITION2D& NextNode)
	{ 
		nToward = atan2(NextNode.GetY() - Y, NextNode.GetX() - X);
		return Distance(NextNode);
	}
	double GetX() { return X; }
	double GetY() { return Y; }
	int GetType() { return nType; }
	double GetToward() { return nToward; }
	POSITION2D* GetNext() { return pNextNode; }
	double Distance(double nx = 0, double ny = 0)
	{
		return sqrt((X - nx) * (X - nx) + (Y - ny) * (Y - ny));
	}
	double Distance(POSITION2D& NextNode)
	{
		return sqrt((X - NextNode.GetX()) * (X - NextNode.GetX()) + (Y - NextNode.GetY()) * (Y - NextNode.GetY()));
	}
} POS2;

//(矢量)3维点坐标类
typedef class POSITION3D
{
private:
	double X, Y, Z;
	int nType;//记号
	double nToward_x;//r-x矢量向
	double nToward_xy;//r-xy矢量向
	POSITION3D * pNextNode;//矢量位
public:
	POSITION3D(double nx, double ny, double nz, 
		int Type = 1, double TowardX = 0, double TowardXY = 0,
		POSITION3D * NextNode = NULL)
		:X(nx), Y(ny), Z(nz),
		nType(Type), nToward_x(TowardX), nToward_xy(TowardXY),
		pNextNode(NextNode) {}
	double Toward(double nx, double ny, double nz)
	{
		nToward_x = atan2(ny - Y, nx - X);
		nToward_xy = atan2(nz - Z, sqrt((X - nx) * (X - nx) + (Y - ny) * (Y - ny)));
		return Distance(nx, ny, nz);
	}
	double Toward(POSITION3D& NextNode)
	{
		nToward_x = atan2(NextNode.GetY() - Y, NextNode.GetX() - X);
		nToward_xy = atan2(NextNode.GetZ() - Z, sqrt((X - NextNode.GetX()) * (X - NextNode.GetX()) + (Y - NextNode.GetY()) * (Y - NextNode.GetY())));
		return Distance(NextNode);
	}
	double GetX() { return X; }
	double GetY() { return Y; }
	double GetZ() { return Z; }
	int GetType() { return nType; }
	double GetTowardX() { return nToward_x; }
	double GetTowardXY() { return nToward_xy; }
	double Distance(POSITION3D& NextNode)
	{
		return sqrt((X - NextNode.GetX()) * (X - NextNode.GetX()) + (Y - NextNode.GetY()) * (Y - NextNode.GetY()) + (Z - NextNode.GetZ()) * (Z - NextNode.GetZ()));
	}
	double Distance(double nx = 0, double ny = 0, double nz = 0)
	{
		return sqrt((X - nx) * (X - nx) + (Y - ny) * (Y - ny) + (Z - nz) * (Z - nz));
	}
} POS3;

#endif // !_COORDINATE_

//链表类
#ifndef _MY_LIST_
#define _MY_LIST_

template<class T>
class LISTING
{
private:
	T *pHead, *pLast;
	int nCount;
public:
	LISTING(T* Head);
	BOOL Add(T* NewNode);
	BOOL AddAt(T* NewNode, int nIndex);
	BOOL AddAtHead(T* NewNode);
	BOOL Del(T* DelNode);
	BOOL Destory();
	T* GetHead();
	T* GetLast();
	int GetCount();
};
template<class T>
LISTING<T>::LISTING(T* Head)
{
	int count = 1;
	pHead = Head;
	if (NULL != Head)
	{
		T* temp = Head;
		while (NULL != temp->pNextNode)
		{
			temp = temp->pNextNode;
			count++;
		}
		pLast = temp;
		nCount = count;
	}
	else
	{
		pLast = Head;
		nCount = 0;
	}
};
template<class T>
BOOL LISTING<T>::Add(T* NewNode)
{
	if (NULL == NewNode) return FALSE;
	if (NULL == pHead && NULL == pLast) pHead = NewNode;
	else pLast->pNextNode = NewNode;
	pLast = NewNode, nCount++;
	return 1;
}
template<class T>
BOOL LISTING<T>::AddAt(T* NewNode, int nIndex)
{
	if (NULL == NewNode) return FALSE;
	if (0 > nIndex || nCount < nIndex) return FALSE;
	T * pTemp = pHead;
	if (nCount == nIndex) pLast = NewNode;
	if (0 == nIndex)
	{
		NewNode = pTemp;
		pHead = NewNode;
	}
	else
	{
		while (1 != (nIndex--)) pTemp = pTemp->pNextNode;
		NewNode->pNextNode = pTemp->pNextNode;
		pTemp->pNextNode = NewNode;
	}
	nCount++;
	return 1;
}
template<class T>
BOOL LISTING<T>::AddAtHead(T* NewNode) { return LISTING<T>::AddAt(NewNode, 0); }
template<class T>
BOOL LISTING<T>::Del(T* DelNode)
{
	if (NULL == DelNode) return FALSE;
	if (DelNode == pHead)
	{
		pHead = DelNode->pNextNode;
		if (DelNode == pLast) pLast = pHead;
	}
	else
	{
		T * pTemp = pHead;
		while (NULL != pTemp)
		{
			if (DelNode == pTemp->pNextNode)
			{
				pTemp->pNextNode = DelNode->pNextNode;
				if (DelNode == pLast) pLast = pTemp;
				break;
			}
			pTemp = pTemp->pNextNode;
		}
	}
	nCount--;
	delete DelNode;
	return 1;
}
template<class T>
BOOL LISTING<T>::Destory()
{
	if (0 == nCount) return FALSE;
	T * pTemp = pHead;
	while (NULL != pTemp)
	{
		if(Del(pTemp)) pTemp = pHead;
	}
	return 1;
}
template<class T>
T* LISTING<T>::GetHead() { return pHead; }
template<class T>
T* LISTING<T>::GetLast() { return pLast; }
template<class T>
int LISTING<T>::GetCount() { return nCount; }

#endif // !_MY_LIST_

//矩阵类
#if defined( _MATRIX_CLASS_) && defined(_NUMBER_FIELD_)

//矩阵类
class MATRIX
{
private:
	double ** value;
	unsigned int line, column;
public:
	MATRIX(double input_value = 0.0)
	{
		line = column = 1;
		value = new double*[line];
		*value = new double[column];
		value[0][0] = input_value;
	}
	MATRIX(MATRIX &matrix) { *this = matrix; }
	MATRIX(MATRIX *matrix) { *this = *matrix; }
	MATRIX(unsigned int Line, unsigned int Column, double Value = 0.0)
	{
		line = Line, column = Column;
		value = new double*[Line];
		for (unsigned int i = 0; i < Line; i++)
			value[i] = new double[Column];
		for (unsigned int i = 0; i < Line; i++)
		{
			for (unsigned int j = 0; j < Column; j++)
			{
				value[i][j] = Value;
			}
		}
	}
	MATRIX(double** Arry, unsigned int Line, unsigned int Column)
	{
		line = Line, column = Column;
		value = new double*[Line];
		for (unsigned int i = 0; i < Line; i++)
			value[i] = new double[Column];
		for (unsigned int i = 0; i < Line; i++)
		{
			for (unsigned int j = 0; j < Column; j++)
			{
				value[i][j] = Arry[i][j];
			}
		}
	}
	unsigned int GetLine() { return line; }
	unsigned int GetColumn() { return column; }
	void Clear()
	{
		double * temp = (double*)value;
		delete[]temp;
		line = column = 1;
		value = new double*[line];
		*value = new double[column];
		value[0][0] = 0;
	}
	double* operator [](unsigned int i) { return value[i]; }
	MATRIX& operator () (unsigned int i)
	{
		double ** temp = new double*[1];
		temp[0] = new double[column];
		for (unsigned int k = 0; k < column; k++)
			temp[0][k] = value[i][k];
		return *(new MATRIX(temp, 1, column));
	}
	double operator () (unsigned int i, unsigned int j) { return value[i][j]; }
	MATRIX& operator - (void)
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = -value[i][j];
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator + (double k)
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] + k;
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator - (double k)
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] - k;
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator + (MATRIX& other)
	{
		if (line != other.GetLine() && column != other.GetColumn()) return *(new MATRIX());
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] + other[i][j];
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator - (MATRIX& other)
	{
		if (line != other.GetLine() && column != other.GetColumn()) return *(new MATRIX());
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] - other[i][j];
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator * (double k)
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] * k;
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator / (double k)
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = value[i][j] / k;
			}
		}
		return *(new MATRIX(temp, line, column));
	}
	MATRIX& operator * (MATRIX& other)
	{
		if (this->GetColumn() != other.GetLine()) return *(new MATRIX());
		unsigned int n = this->GetColumn();
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[other.GetColumn()];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < other.GetColumn(); j++)
			{
				double ij = 0.0;
				for (unsigned int k = 0; k < n; k++)
				{
					ij += value[i][k] * (other[k][j]);
				}
				temp[i][j] = ij;
			}
		}
		return *(new MATRIX(temp, line, other.GetColumn()));
	}
	MATRIX& operator / (MATRIX& other)
	{
		MATRIX* temp = &(other.InverseMatrix());
		MATRIX* resualt = &((*this) * (*temp));
		delete temp;
		return *resualt;
	}
	MATRIX& operator = (MATRIX& other)
	{
		double * temp = (double*)value;
		delete[]temp;
		line = other.GetLine();
		column = other.GetColumn();
		value = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			value[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				value[i][j] = other[i][j];
			}
		}
		return *this;
	}
	MATRIX& operator += (double k)
	{
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				value[i][j] += k;
			}
		}
		return *this;
	}
	MATRIX& operator -= (double k)
	{
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				value[i][j] -= k;
			}
		}
		return *this;
	}
	MATRIX& operator *= (double k)
	{
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				value[i][j] *= k;
			}
		}
		return *this;
	}
	MATRIX& operator /= (double k)
	{
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				value[i][j] /= k;
			}
		}
		return *this;
	}
	void ChangeLine(unsigned int i, unsigned int j)
	{
		for (unsigned int u = 0; u < column; u++)
			Swap((*this)[i][u], (*this)[j][u]);
	}
	double Det()
	{
		if (line != column) return EOF;
		MATRIX temp(this);
		int i, j, k, u, n = line;
		int LineChangeTimes = 0;
		double DetValue = 1, Rate;
		for (i = 0; i < n; i++)
		{
			if (0 == temp[i][i])
			{
				j = i + 1;
				while (1)
				{
					if (n == j) return 0;
					if (0 == temp[j][i]) j++;
					else
					{
						temp.ChangeLine(i, j);
						break;
					}
				}
			}
			if (0 != temp[i][i])
			{
				for (k = i + 1; k < n; k++)
				{
					if (0 != temp[k][i])
					{
						Rate = -1 * temp[k][i] / temp[i][i];
						for (u = 0; u < n; u++)
						{
							temp[k][u] = temp[k][u] + temp[i][u] * Rate;
						}
					}
				}
			}
		}
		for (i = 0; i < n; i++)
			DetValue = DetValue * temp[i][i];
		if (1 == LineChangeTimes % 2) DetValue = -DetValue;
		temp.Clear();
		return DetValue;
	}
	MATRIX& AdjugateMatrix(unsigned int i, unsigned int j)
	{
		double ** temp = new double*[line - 1];
		for (unsigned int i = 0; i < line - 1; i++)
			temp[i] = new double[column - 1];
		unsigned int a = 0, b = 0;
		while (!((line - 1)* (column - 1) <= a || line * column <= b))
		{
			if (j == b % column || i == b / column)
			{
				b++;
				continue;
			}
			else temp[a / (column - 1)][a % (column - 1)] = value[b / column][b % column];
			a++, b++;
		}
		return *(new MATRIX(temp, line - 1, column - 1));
	}
	double AlgebraicCofactor(unsigned int i, unsigned int j)
	{
		if (line != column) return EOF;
		double p = (0 == (i + j) % 2) ? 1.0 : -1.0;
		MATRIX* temp = &AdjugateMatrix(i, j);
		p *= temp->Det();
		temp->Clear();
		delete temp;
		return p;
	}
	MATRIX& InverseMatrix()
	{
		double ** temp = new double*[line];
		for (unsigned int i = 0; i < line; i++)
			temp[i] = new double[column];
		for (unsigned int i = 0; i < line; i++)
		{
			for (unsigned int j = 0; j < column; j++)
			{
				temp[i][j] = AlgebraicCofactor(j, i);
			}
		}
		return MATRIX(temp, line - 1, column - 1) / this->Det();
	}
	unsigned int Rank()
	{
		MATRIX temp(this);
		unsigned int Rank, i, j, k, u, v = 0;
		double Rate;
		for (i = 0; i < temp.GetLine(); i++)
		{
			if (v < i) v = i;
			for (; v < temp.GetColumn(); v++)
			{
				if (0 == temp[i][v])
				{
					j = i + 1;
					while (1)
					{
						if (temp.GetLine() == j) break;
						if (0 == temp[j][v]) j++;
						else
						{
							temp.ChangeLine(i, j);
							break;
						}
					}
				}
				if (0 != temp[i][v])
				{
					for (k = i + 1; k < temp.GetLine(); k++)
					{
						if (0 != temp[k][v])
						{
							Rate = -1 * temp[k][v] / temp[i][v];
							for (u = 0; u < temp.GetColumn(); u++)
							{
								temp[k][u] = temp[k][u] + temp[i][u] * Rate;
							}
						}
					}
					break;
				}
			}
			if (temp.GetColumn() == v)
			{
				temp.Clear();
				return i;
			}
		}
		Rank = temp.GetLine();
		temp.Clear();
		return Rank;
	}
	MATRIX& MatrixTransposition()//新生成的转置矩阵有可能无法清除
	{
		double ** temp = new double*[column];
		for (unsigned int i = 0; i < column; i++)
			temp[i] = new double[line];
		for (unsigned int i = 0; i < column; i++)
		{
			for (unsigned int j = 0; j < line; j++)
			{
				temp[i][j] = value[j][i];
			}
		}
		return *(new MATRIX(temp, column, line));
	}
};

#endif // !_MATRIX_CLASS_

//函数类
#if defined( _MATRIX_CLASS_) && defined(_NUMBER_FIELD_)

//函数类
class Function
{
private:
	unsigned int MaxDegree;
	MATRIX * Coefficient;
public:
	Function()
	{
		Coefficient = new MATRIX();
		MaxDegree = 0;
	}
	Function(double* C, unsigned int length)
	{
		double** temp = new double*[1];
		temp[0] = new double[length];
		for (unsigned int i = 0; i < length; i++)
			temp[0][i] = C[i];
		Coefficient = new MATRIX(temp, 1, length);
		MaxDegree = length - 1;
	}
	Function(MATRIX& C, unsigned int _line = 0)
	{
		Coefficient = &C(_line);
		MaxDegree = C.GetColumn() - 1;
		for (unsigned int i; i < C.GetColumn(); i++)
		{
			if (0 == Coefficient[0][i]) MaxDegree--;
			else break;
		}
	}
	Function(MATRIX* C, unsigned int _line = 0)
	{
		Coefficient = &(*C)(_line);
		MaxDegree = C->GetColumn() - 1;
		for (unsigned int i; i < C->GetColumn(); i++)
		{
			if (0 == Coefficient[0][i]) MaxDegree--;
			else break;
		}
	}
	Function(Function &function) { *this = function; }
	Function(Function *function) { *this = *function; }
	Function& Diff()
	{
		MATRIX* temp = new MATRIX(1, MaxDegree);
		for (unsigned int i = 0; i < MaxDegree; i++)
		{
			(*temp)[0][i] = (*Coefficient)[0][i] * (MaxDegree - i);
		}
		Function* _temp = new Function(temp, 1);
		delete temp;
		return *_temp;
	}
	Function& Integrate(MATRIX* start)
	{
		if (2 != start->GetColumn() || 1 != start->GetLine()) return *(new Function());
		MATRIX* temp = new MATRIX(1, MaxDegree + 2);
		for (unsigned int j = 0; j < MaxDegree + 1; j++)
			(*temp)[0][j] = (*Coefficient)[0][j] / (MaxDegree - j + 1);
		double ff = 0.0;
		for (unsigned int j = 0; j < MaxDegree + 1; j++)
			ff += (*temp)[0][j] * pow((*start)[0][0], MaxDegree - j + 1);
		(*temp)[0][MaxDegree + 1] = (*start)[0][1] - ff;
		Function* _temp = new Function(temp, 1);
		delete temp;
		return *_temp;
	}
	MATRIX& Zero()
	{
		switch (MaxDegree)
		{
		case 0:
		{
			return *(new MATRIX());
		}
		case 1:
		{
			if (0 == (*Coefficient)[0][0]) return *(new MATRIX());
			MATRIX* temp = new MATRIX(1, 2);
			(*temp)[0][0] = -(*Coefficient)[0][1] / (*Coefficient)[0][0];
			return *temp;
		}
		case 2:
		{
			double deta = (*Coefficient)[0][1] * (*Coefficient)[0][1] - 4 * (*Coefficient)[0][0] * (*Coefficient)[0][2];
			if (0 > deta || 0 == (*Coefficient)[0][0]) return *(new MATRIX());
			MATRIX* temp = new MATRIX(2, 2);
			(*temp)[0][0] = (-(*Coefficient)[0][1] + sqrt(deta)) / (2 * (*Coefficient)[0][0]);
			(*temp)[1][0] = (-(*Coefficient)[0][1] - sqrt(deta)) / (2 * (*Coefficient)[0][0]);
			return *temp;
		}
		case 3:
		{
			double a = (*Coefficient)[0][0], b = (*Coefficient)[0][1], c = (*Coefficient)[0][2], d = (*Coefficient)[0][3];
			if (0 == a) return *(new MATRIX());
			double _A = b * b - 3 * a*c, _B = b * c - 9 * a*d, _C = c * c - 3 * b*d;
			double deta = _B * _B - 4 * _A*_C;
			if (0 > _A || (0 == _A && 0 != _B))
			{
				double Y1 = _A * b + 1.5*a*(-_B + sqrt(deta)), Y2 = _A * b + 1.5*a*(-_B - sqrt(deta));
				MATRIX* temp = new MATRIX(1, 2);
				(*temp)[0][0] = -(b + pow(Y1, 1.0 / 3) + pow(Y2, 1.0 / 3)) / (3 * (*Coefficient)[0][0]);
				return *temp;
			}
			else if (0 == _A && 0 == _B)
			{
				MATRIX* temp = new MATRIX(3, 2);
				(*temp)[0][0] = (*temp)[1][0] = (*temp)[2][0] = -b / (3 * a);
				return *temp;
			}
			else if (0 == deta)
			{
				MATRIX* temp = new MATRIX(3, 2);
				(*temp)[0][0] = -b / a + _B / _A;
				(*temp)[1][0] = (*temp)[2][0] = -_B / (2 * _A);
				return *temp;
			}
			else if (deta < 0)
			{
				double T = (2 * _A*b - 3 * a*_B) / (2 * pow(_A, 1.0 / 3));
				double sita = acos(T);
				MATRIX* temp = new MATRIX(3, 2);
				(*temp)[0][0] = -(b + 2 * sqrt(_A)*cos(sita / 3)) / (3 * a);
				(*temp)[1][0] = -(b - sqrt(_A)*(cos(sita / 3)) - sqrt(3)*sin(sita / 3)) / (3 * a);
				(*temp)[2][0] = -(b - sqrt(_A)*(cos(sita / 3)) + sqrt(3)*sin(sita / 3)) / (3 * a);
				return *temp;
			}
		}
		default:
		{
			MATRIX* temp = new MATRIX(1, 2);
			double x0 = 0.0, x1 = 0.0;
			Function DF = Diff();
			for (int i = 0; i <= 10000; i++)
			{
				double fx0, f_x0;
				if (0.0 == (f_x0 = DF.Value(x0)))//泰勒展开点x0处一阶导数为0
				{
					x0 += 1.0;
					continue;
				}
				x1 = x0 - (fx0 = Value(x0)) / f_x0;
				//两次迭代结果误差小于0.001或迭代结果接近于0或达到最大迭代次数
				if (0.001 >= abs(x1 - x0) || 0.001 >= fx0 || 10000 == i) break;
				else x0 = x1;
			}
			(*temp)[0][0] = x1;
			return *temp;
		}
		}
	}
	Function& operator = (Function& other)
	{
		delete Coefficient;
		MaxDegree = other.GetDegree();
		Coefficient = new MATRIX(1, MaxDegree + 1);
		for (unsigned int i = 0; i < MaxDegree + 1; i++)
		{
			(*Coefficient)[0][i] = other(MaxDegree - i);
		}
	}
	double operator () (unsigned int i)//A(i)为i次幂项系数
	{
		if (MaxDegree < i) return 0.0;
		else return (*Coefficient)(0, MaxDegree - i);
	}
	double& operator [] (unsigned int i)//A[0]为最高次项系数
	{
		double *c;
		if (MaxDegree >= i) c = &((*Coefficient)[0][MaxDegree - i]);
		return *c;
	}
	Function& operator * (Function& other)
	{
		unsigned int NewDegree = MaxDegree + other.GetDegree();
		Function *A = this, *B = &other;
		if (MaxDegree < other.GetDegree()) Swap(A, B);
		MATRIX *temp = new MATRIX(1, NewDegree + 1);
		for (unsigned int j = 0; j <= NewDegree; j++)
		{
			double ij = 0.0;
			for (unsigned int u = min(A->GetDegree(), NewDegree - j); u + j >= A->GetDegree(); u--)
			{
				ij += (*A)(u) * (*B)(NewDegree - j - u);
				if (0 == u) break;
			}
			(*temp)[0][j] = ij;
		}
	}
	unsigned int GetDegree() { return MaxDegree; }
	double Value(double x)
	{
		double r = (*this)[0];
		for (unsigned int i = 1; i <= MaxDegree; i++)
			r = r * x + (*this)[i];
		return r;
	}
};

#endif // !_MATRIX_CLASS_

#include <io.h>

//文件操作方法
#ifndef _FILE_OP_
#define _FILE_OP_

//查看文件夹下同一类型文件数目
unsigned int Get_Counts_SameType_Files_In_Document(const char * Assigned_Type, const char * Disc_Document);
//获取文件夹下某一类型文件的所有绝对路径
char** Get_SameType_FileName_In_Document(const char * Assigned_Type, const char * Disc_Document);

#endif // !_FILE_OP_

//数组排序
#ifdef _STRING_NUMBER_OP_

//数组排序
template<class T>
inline void Sort(T* &num, int length, int style = FROM_SMALL_LARGE)
{
	bool is = 1;
	if (FROM_LARGE_SMALL == style)//Max -> Min
	{
		while (is)
		{
			is = false;
			for (int i = 0; i < length - 1; i++)
			{
				if (is |= (num[i] < num[i + 1])) Swap(num[i], num[i + 1]);
			}
		}
	}
	else if (FROM_SMALL_LARGE == style)//Min -> Max
	{
		while (is)
		{
			is = false;
			for (int i = 0; i < length - 1; i++)
			{
				if (is |= (num[i] > num[i + 1])) Swap(num[i], num[i + 1]);
			}
		}
	}
}

#endif //!_STRING_NUMBER_OP_

//交换两个数
#ifdef _NUMBER_FIELD_

//交换两个数
template<class T>
inline void Swap(T & num1, T & num2)
{
	T temp = num1;
	num1 = num2;
	num2 = temp;
}
//获取符号
template<class T>
inline int Sign(T num)
{
	if (0 < num) return 1;
	else if (0 == num) return 0;
	else return -1;
}

#endif //!_NUMBER_FIELD_
