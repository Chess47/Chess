#include "My.h"

//改变控制台输出位置
void ChangeToXY(short nx, short ny)
{
	_COORD pos = { nx,ny };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//指定位置输出0~9
bool SetXY2Num(short nx, short ny, int num)
{
	if (0 > num && 9 < num) return 0;
	_COORD pos = { nx,ny };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << num;
	return 1;
}
//指定位置输出字符串，并将光标移至指定位置
bool SetXY2Str(short nx, short ny, const char * str, short endx, short endy)
{
	_COORD pos = { nx,ny };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << str;
	if (nx != endx && ny != endy)
	{
		pos.X = endx, pos.Y = endy;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		return 1;
	}
	return 0;
}
//指定位置输出字符串，并选择是否将光标移至原点
void SetXY2Str(short nx, short ny, const char * str, bool isRest)
{
	_COORD pos = { nx,ny };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << str;
	if (isRest)
	{
		pos.X = 0, pos.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
}

//数字转字符串
string Change_i2s(int num)
{
	string pTemp = "";
	std::stringstream ss;
	ss << num;
	pTemp = ss.str();
	return pTemp;
}
//获取整形位数
int GetLength(int num)
{
	int nLength = (num < 0) ? 2 : 1;
	while (0 != num / 10)
	{
		num /= 10;
		nLength++;
	}
	return nLength;
}
//正整型数分解，并返回位数
int * NumResolve(unsigned int num, int & length)
{
	length = GetLength(num);
	int * number = new int[length];
	for (int i = 0; i < length; i++)
	{
		number[i] = num % 10;
		num /= 10;
		if (0 == num) break;
	}
	return number;
}
//下一顺序数
void NextSort(unsigned int* num, int length, int style = BIGGER)
{
	if (BIGGER == style)
	{
		if (num[length - 1] > num[length - 2])
			Swap(num[length - 1], num[length - 2]);
		else
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num[i] > num[i - 1])
				{
					int u = length - 1;
					for (int j = length - 2; j >= i; j--)
					{
						if (num[i - 1] < num[j] && (num[j] <= num[u] || num[i - 1] >= num[u]))
							u = j;
					}
					Swap(num[u], num[i - 1]);
					int* temp = new int[length - i];
					for (int j = 0; j < length - i; j++)
						temp[j] = num[i + j];
					Sort(temp, length - i, FROM_SMALL_LARGE);
					for (int j = 0; j < length - i; j++)
						num[i + j] = temp[j];
					delete[]temp;
					break;
				}
			}
		}
	}
	else if (SMALLER == style)
	{
		if (num[length - 1] < num[length - 2])
			Swap(num[length - 1], num[length - 2]);
		else
		{
			for (int i = length - 1; i > 0; i--)
			{
				if (num[i] < num[i - 1])
				{
					Swap(num[i], num[i - 1]);
					int* temp = new int[length - i];
					for (int j = 0; j < length - i; j++)
						temp[j] = num[i + j];
					Sort(temp, length - i - 1, FROM_LARGE_SMALL);
					for (int j = 0; j < length - i; j++)
						num[i + j] = temp[j];
					delete[]temp;
					break;
				}
			}
		}
	}
}
//指定大小生成二维数组
char ** Create_2Demenssion_Array_Size(int lines, int colomns)
{
	char** theArray = new char*[lines];
	for (unsigned short i = 0; i < lines; i++) theArray[i] = new char[colomns];
	for (unsigned short i = 0; i < lines; i++)
		for (unsigned short j = 0; j < colomns; j++)
			theArray[i][j] = 0;
	return theArray;
}
//拷贝数组内容到新的空数组
void Copy_Array_2EmptyArray(char * Empty_Array, char * SameSize_Array)
{
	for (unsigned short i = 0; SameSize_Array[i] != '\0'; i++)
		Empty_Array[i] = SameSize_Array[i];
}
void Copy_Array_2EmptyArray(char * Empty_Array, const char* SameSize_Array)
{
	for (unsigned short i = 0; SameSize_Array[i] != '\0'; i++)
		Empty_Array[i] = SameSize_Array[i];
}

//判断是否为闰年
bool JudgeBissextile(int year)
{
	return (0 == year % 400 || (0 != year % 100 && 0 == year % 4));
}

//阶乘
long Factorial(int n)
{
	if (0 > n) return 0;
	else if (1 >= n) return 1;
	else return n * Factorial(n - 1);
}
//排列数
long Arrangement(unsigned int n, unsigned int m)
{
	if (n < m) return 0;
	long r = 1;
	for (unsigned int i = n; i > n - m; i--)
		r *= i;
	return r;
}
//组合数
long Combination(unsigned int n, unsigned int m)
{
	if (n < m) return 0;
	else if (0 == m || n == m) return 1;
	else return Combination(n - 1, m - 1) + Combination(n - 1, m);
}
//伽马函数
double Gamma(double n)
{
	if (0 >= n) return -1.0;
	else if (0 < n && 2 >= n)
	{
		return Gamma(n + 1) / n;
	}
	else if (2 < n && 3 >= n)
	{
		double C[11] = { 0.0000677106,-0.0003442342,0.0015397681,
			-0.0024467480,0.0109736958,-0.0002109075,0.0742379071,
			0.0815782188,0.4118402518,0.4227843370,1.0 };
		double r = C[10];
		for (int i = 1; i <= 10; i++)
			r += C[10 - i] * pow(n - 2.0, i);
		return r;
	}
	else return (n - 1) * Gamma(n - 1);
}
//贝塔函数
double Beta(double x, double y)
{
	return Gamma(x) * Gamma(y) / Gamma(x + y);
}
//求最大公约数
unsigned int GetMaxnimumCommonDivisor(unsigned int num1, unsigned int num2)
{
	for (; num1 != num2;)
	{
		if (num1 < num2) Swap(num1, num2);
		num1 -= num2;
	}
	return num1;
}
//求最小公倍数
unsigned int GetLowestCommonMultiple(unsigned int num1, unsigned int num2)
{
	return (num1 * num2) / GetMaxnimumCommonDivisor(num1, num2);
}
//判断是否为质数
bool JudgePrime(int x)
{
	if (0 == x || 1 == x || 9 == x) return 0;
	else if (2 == x || 3 == x || 5 == x || 7 == x) return 1;
	else if (0 == x % 2) return 0;
	for (int i = 3; i < x / 3; i++)//compute the odd number over by 10
		if (0 == x % i) return 0;
	return 1;
}
//列出所有因数，并判断是否为质数
bool JudgePrime(int x, int *& pFactors, unsigned int & pFactorsCount)
{
	delete[] pFactors;
	pFactorsCount = 1;
	if (0 == x || 1 == x)
	{
		pFactors = new int[pFactorsCount];
		pFactors[0] = x;
		return 0;
	}
	else
	{
		for (int i = 2; i <= x; i++)//calculate the factor of the number
		{
			if (0 == x % i) pFactorsCount++;
		}
		pFactors = new int[pFactorsCount];
		pFactors[0] = 1;
		unsigned int j = 1;
		for (int i = 2; i <= x && j <= pFactorsCount; i++)//calculate the factor of the number
		{
			if (0 == x % i) pFactors[j++] = i;
		}
	}
	if (2 == pFactorsCount) return 1;
	else return 0;
}
//质因数分解
bool PrimeFactorization(int x, int *& pFactors, unsigned int & pFactorsCount)
{
	delete[] pFactors;
	pFactorsCount = 0;
	if (0 > x) return 0;
	else if (0 == x || 1 == x)
	{
		pFactorsCount = 1;
		pFactors = new int[pFactorsCount];
		pFactors[0] = x;
		return 0;
	}
	else
	{
		int *temp_class = new int[x / 2];
		pFactorsCount = 0;
		for (int i = 2; 1 != x; i++)
		{
			if (0 == x % i &&JudgePrime(i))
			{
				x /= i;
				temp_class[pFactorsCount++] = i;
				i = 1;
			}
		}
		pFactors = new int[pFactorsCount];
		for (unsigned int i = 0; i < pFactorsCount; i++)
			pFactors[i] = temp_class[i];
		delete[] temp_class;
		return 1;
	}
}
//完全数判断
int JudgePerfect(int x)
{
	int* factors = NULL;
	unsigned int factors_count = 0;
	JudgePrime(x, factors, factors_count);
	int temp = 0;
	for (unsigned int i = 0; i < factors_count; i++)
		temp += factors[i];
	if (x < temp) return ABUNDANT_NUMBER;
	else if (x == temp) return COMPLETE_NUMBER;
	else return DEFICIENT_NUMBER;
	return 0;
}
//亲密数判断，若是亲密数，则返回亲密数对，否则返回0
int JudgeClose(int x)
{
	int * pFactors = NULL;
	unsigned int nCount = 0;
	JudgePrime(x, pFactors, nCount);
	int other = 0;
	for (unsigned int i = 0; i < nCount - 1; i++)
		other += pFactors[i];
	JudgePrime(other, pFactors, nCount);
	int temp = 0;
	for (unsigned int i = 0; i < nCount - 1; i++)
		temp += pFactors[i];
	if (temp == x) return other;
	else return 0;
}
//水仙花数判断
bool JudgeNarcissistic(long x)
{
	long the_x = x;
	int length = 0;
	int * num = NumResolve(x, length);
	long temp = 0;
	for (int i = 0; i < length; i++)
		temp += long(pow(num[i], length));
	delete[]num;
	return (temp == the_x);
}
//水仙花数寻找
long NextNarcissistic(long x)
{
	while (FALSE == JudgeNarcissistic(x + 1)) x++;
	return x + 1;
}
//自守数判断
int JudgeAutomorphic(int x)
{
	int length = 0;
	int* num = NumResolve(x, length);
	int* r = new int[length];
	for (int i = 0; i < length; i++)
		r[i] = 0;
	for (int i = 0; i < length; i++)
	{
		int temp = 0;
		for (int u = 0; u <= i; u++)
			temp += num[u] * num[i - u];
		int temp_len = 0;
		int* temp_num = NumResolve(temp, temp_len);
		for (int j = 0; j < temp_len && i + j < length; j++)
			r[i + j] += temp_num[j];
		delete[]temp_num;
	}
	bool is = FALSE;
	for (int i = 0; i < length && FALSE == is; i++)
		is |= (num[i] == r[i]);
	delete[]num;
	delete[]r;
	if (is) return int(pow(10, length) + 1 - x);
	else return 0;
}
//距离计算
double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

//单概率产生随机数(0 <= p <= 1)，p的概率产生0，1-p的概率产生1
bool GetRandBool(double p)
{
	unsigned int P = (unsigned int)(10000 * p);
	unsigned int num = (unsigned int)(rand() % 10000);
	if (P < num) return 1;
	return false;
}
//双概率产生随机数(0 <= p1 <= p2 <=1)，p1的概率产生1，p2-p1的概率产生2,1-p2的概率产生3
int GetRandPSS(double p1, double p2)
{
	unsigned int P1 = (unsigned int)(10000 * p1), P2 = (unsigned int)(10000 * p2);
	unsigned int num = (unsigned int)(rand() % 10000);
	if (P2 < num) return 3;
	else if (P1 < num) return 2;
	return 1;
}
//指定区间[a,b]均匀产生整形随机数
int GetRandInt(int a, int b)
{
	if (a > b) Swap(a, b);
	else if (a == b) return a;
	return rand() % (b - a) + a;
}
//指定区间[a,b]与精度均匀产生浮点随机数
double GetRandFloat(double a, double b, double precision = DEFAULT_PRECISION)
{
	if (a > b) Swap(a, b);
	else if (a == b) return a;
	double r = 0.0;
	if (MAX_PRECISION <= precision)
	{
		double ix = (b - a) / precision;
		ix -= int(ix);
		if (1 - FLOAT_MIN < ix) ix = 0.0;
		if (-FLOAT_MIN<ix&&FLOAT_MIN>ix)
		{
			r = GetRandInt(0, int((b - a) / precision)) * precision + a;
			r = int((r - a) / precision) * precision + a;
		}
	}
	return r;
}
//以指定期望与标准差产生正态分布型随机数
double GetRandNormal(double average = 0.0, double standard = 1.0)
{
	double r = 0.0;
	for (int i = 0; i < 12; i++)
		r += GetRandFloat(0, 1);
	r = average + standard * (r - 6.0);
	return r;
}

//自定义异步按键检测函数
int ReadKey()
{
	if (0 != GetAsyncKeyState('W') || 0 != GetAsyncKeyState('w')) return UP_DIRECTION;
	if (0 != GetAsyncKeyState('S') || 0 != GetAsyncKeyState('s')) return DN_DIRECTION;
	if (0 != GetAsyncKeyState('A') || 0 != GetAsyncKeyState('a')) return LT_DIRECTION;
	if (0 != GetAsyncKeyState('D') || 0 != GetAsyncKeyState('d')) return RT_DIRECTION;
	if (0 != GetAsyncKeyState(VK_UP)) return UP;
	if (0 != GetAsyncKeyState(VK_DOWN)) return DOWN;
	if (0 != GetAsyncKeyState(VK_LEFT)) return LEFT;
	if (0 != GetAsyncKeyState(VK_RIGHT)) return RIGHT;
	if (0 != GetAsyncKeyState(VK_SPACE)) return SPACE;
	if (0 != GetAsyncKeyState(VK_RETURN)) return ENTER;
	return 0;
}

//复对数
Complex Ln(const Complex & c)
{
	return Complex(log(c.Module()), c.AngleP());
}
//复正弦
Complex Sin(const Complex & c)
{
	double p = exp(c.GetImage());
	double q = 1.0 / p;
	return Complex(sin(c.GetReal()) * (p + q) * 0.5, cos(c.GetReal()) * (p - q) * 0.5);
}
//复余弦
Complex Cos(const Complex & c)
{
	double p = exp(c.GetImage());
	double q = 1.0 / p;
	return Complex(cos(c.GetReal()) * (p + q) * 0.5, -sin(c.GetReal()) * (p - q) * 0.5);
}
//复数开n次方根
Complex * Sqt(const Complex & c, unsigned int n)
{
	Complex* temp;
	if (0 == n || 1 == n)
	{
		temp = new Complex[1];
		temp[0] = c;
	}
	else
	{
		temp = new Complex[n];
		double m = pow(c.Module(), 1.0 / n);
		double d = c.AngleP() / n;
		for (unsigned int i = 0, j = 0; i < n; i++)
		{
			if (PI < d + j * (PI / n)) j = -1;
			else if ((-PI > d + j * (PI / n)) && n - 1 == i) break;
			temp[i] = Complex(m * cos(d + j * (PI / n)), m * sin(d + j * (PI / n)));
			j = (j >= 0) ? j + 1 : j - 1;
		}
	}
	return temp;
}

//查看文件夹下同一类型文件数目
unsigned int Get_Counts_SameType_Files_In_Document(const char * Assigned_Type, const char * Disc_Document)
{
	_finddata_t file_attribute;
	intptr_t hFile;
	unsigned int count = 0;
	if ((hFile = _findfirst((string(Disc_Document).append(Assigned_Type).c_str()), &file_attribute)) == EOF);
	else
		do {
			count++;
		} while (_findnext(hFile, &file_attribute) == 0);
		_findclose(hFile);
		return count;
}
//获取文件夹下某一类型文件的所有绝对路径
char ** Get_SameType_FileName_In_Document(const char * Assigned_Type, const char * Disc_Document)
{
	_finddata_t file_attribute;
	intptr_t hFile;
	unsigned int filecount = 0;
	char **filename = Create_2Demenssion_Array_Size(Get_Counts_SameType_Files_In_Document(Assigned_Type, Disc_Document), 256);
	if ((hFile = _findfirst((string(Disc_Document).append(Assigned_Type).c_str()), &file_attribute)) == EOF)
	{
		delete[]filename;
		return NULL;
	}
	else
		do {
			Copy_Array_2EmptyArray(filename[filecount++], file_attribute.name);
		} while (_findnext(hFile, &file_attribute) == 0);
		_findclose(hFile);
		return filename;
}
