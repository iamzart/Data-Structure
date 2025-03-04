#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

/*标题统计*/
//代码思路：
//第一种方法：用getline，判断是否为空白字符，如果不是，计数器++
//第二种方法：用循环的方式，把一个字符串拆成几个单词，因为cin会跳过空格，切while循环里是cin的话，能读取就会进入循环，不能读取就会跳出循环，需要按ctrlZ

//int main()
//{
//	string s;
//	int cnt = 0;
//	getline(cin, s);
//	//遍历，判断
//	for (auto e : s)
//	{
//		if (isspace(e))//如果是空格
//			continue;
//		else
//		 cnt++;
//	}
//	cout << cnt << endl;
//
//	return 0;
//}

//int main()
//{
//	string s;
//	int cnt = 0;
//	while (cin >> s)
//	{
//		//输入一个单词就求出它的长度加起来
//		cnt += s.size();
//	}
//	cout << cnt << endl;
//	return 0;
//}


/*石头剪子布*/
//代码思路：循环n次，字符串比大小

//int main()
//{
//	int n;
//	cin >> n;
//	string s1;
//	string s2;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s1 >> s2;
//		if (s1 > s2 && s1 == "Rock")
//			cout << "Player1";
//
//把s1赢得情况罗列出来，除此之外else
//
//	}
//	return 0;
//}


//int main()
//{
//	string s;
//	getline(cin, s);
//	string::iterator it = s.begin();//就是begin指向字符串s的第一个元素
//	int sz = s.size();
//	for (int i = 0; i < sz; i++)
//	{
//		if (isupper(s[i]) || islower(s[i]))
//		{
//			s[i] -= 1;
//			if (s[i] == 'a' || s[i] == 'A')
//				s[i] += 25;
//			
//		}
//
//	}
//	cout << s << endl;
//	return 0;
//}


/*文字处理软件*/
//int main()
//{
//	int q;
//	cin >> q;
//	string s;
//	int a = 0, b = 0;
//	string str1;
//	string str;
//	cin >> s;
//	int n = 0;
//	for (int i = 0; i < q; i++)
//	{
//		cin >> n;
//		switch (n)//选项
//		{
//		case 1:
//			cin >> str;
//			s += str;
//			cout << s << endl;
//			break;
//		case 2:
//			cin >> a >> b;
//			 s = s.substr(a, b);//这里是只保留，就是对这个字符串本身进行改变，如果用另一个来接受，那么就没有对他本身进行改变
//			cout << s << endl;
//			break;
//		case 3:
//			cin >> a >> str;
//			s.insert(a, str);
//			cout << s << endl;
//			break;
//		case 4:
//			cin >> str;
//			size_t m = s.find(str);
//			if (m == string::npos)//没找到
//				cout << "-1" << endl;
//			else
//				cout << m << endl;
//
//			break;
//		}
//
//	}
//	return 0;
//}


/*单词的长度*/
//代码思路：说实话我觉得，用getline输进去是一个，咋给他分开啊
//int main()
//{
//	string s;
//	cin >> s;
//	cout << s.size();
//	while (cin >> s)//这个就是在s读不了了就会跳出循环，能读的话会跳过空白字符
//	{
//		cout << "," << s.size();
//		
//	}
//
//	return 0;
//}

//int main()
//{
//	string s;
//	bool flag = true;
//	while (cin >> s)//这个就是在s读不了了就会跳出循环，能读的话会跳过空白字符
//	{
//		if (flag) {
//			cout << s.size();
//			flag = false;//刚开始是真的嘛，你输入一次后就变成假，往后就都是和逗号组合
//		}
//		else
//			cout << "," << s.size();
//		
//
//	}
//
//	return 0;
//}

//第一种方法
// 只区分第一个字符串，让他单独输入，后边的话“，字符串”为一组
//第二种方法
//让flag是true，就是让他进来，但赶紧置为false，就是只让他进来一次，第二次就不是true，就进不来了



//int main()
//{
//	string s;
//	char tmp;
//	
//	while (cin >> s)
//	{
//		string::iterator it = s.begin();
//		string::iterator is = s.end() - 1;
//		while (it < is)
//		{
//			tmp = *it;
//			*it = *is;
//			*is = tmp;
//			it++;
//			is--;
//		}
//		cout << s << endl;
//	}
//	return 0;
//}
//要把迭代器放循环里!!!

//int main()
//{
//	string s;
//	
//	char tmp;
//	while (cin >> s)
//	{
//		int i = 0;
//		size_t sz = s.size();
//		while (i < sz - 1)
//		{
//			tmp = s[i];
//			s[i] = s[sz - 1];
//			s[sz - 1] = tmp;
//			i++;
//			sz--;
//		}
//		cout << s << endl;
//	}
//	return 0;
//}

//#include<algorithm>
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		reverse(s.begin(), s.end());
//		cout << s << endl;
//	}
//	return 0;
//}


//int main()
//{
//	int arr[10];
//	for (int &e : arr)
//	{
//		cin >> e;
//	}
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	reverse(arr, arr+sz);
//	for (int i = 0; i < sz; i++)
//	{
//		cout << arr[i];
//	}
//
//}



//int main()
//{
//	string s;
//	cin >> s;
//	size_t sz = s.size();
//	int left = 0;
//	int right = sz - 1;
//	int flag = 1;//是回文数
//	while (left < right)
//	{
//		if (s[left] == s[right])
//		{
//			left++;
//			right--;
//		}
//		else
//		{
//			cout << "no" << endl;
//			flag = 0;
//			break; //这里可以写return0；!!就是提前结束
//		}
//			
//	}
//	//现在出循环了，只有两种可能
//	//第一种是自然的出循环，左右一直相等，知道都比较完了
//	//第二种是输出了no
//	if (flag == 1)
//		cout << "yes" << endl;
//	return 0;
//}

//#include<algorithm>
//int main()
//{
//	string s;
//	cin >> s;
//	string t = s;
//	string::iterator it = s.begin();
//	string::iterator is = s.end();
//	//reverse函数没有返回值，所以是改变它自身
//	//应该拷贝一份由他使用
//	reverse(it, is);
//	if (s == t)
//	{
//		cout << "yes" << endl;
//	}
//	else
//		cout << "no" << endl;
//
//	return 0;
//}


/*手机*/
//int main()
//{
//	//因为有空格还要被读进去，所以用getline
//	string s;
//	int sum = 0;
//	int count[26] = { 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4 };
//	//这些就是他们的下标数字
//	getline(cin, s);
//	//接下来要遍历
//	for (auto ch : s)
//	{
//		if (ch == ' ')
//			sum += 1;
//		else
//		sum += count[ch - 'a'];
//	}
//	cout << sum << endl;
//	return 0;
//}



/*口算练习题*/
//int main()
//{
//	string op;
//	int i;
//	int n1, n2;
//	cin >> i;
//	int r = 0;
//	string ans=0;
//	while (i--) {
//		cin >> op;
//		cin >> n1 >> n2;
//		if (op == "a" || op == "b" || op == "c")
//		{//三个数据情况
//			
//			ans += to_string(n1);
//			ans += op;
//			ans += to_string(n2);
//			ans += "=";
//			ans += to_string(r);
//
//		}
//		else
//		{//两个数据情况
//
//		}
//	}
//	return 0;
//}