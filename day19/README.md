## STL
1. vector
变长数组(动态变化), 倍增
2. string
字符串, `substr()`, `c_str()`
3. queue
队列, `push()`,`front()`, `pop()`
4. priority_queue
优先队列, `push()`,`pop()`, `top()`
5. stack
栈, `push()`, `top()`, `pop()`
6. deque
双端队列
7. set, map, multiset, multimap
基于平衡二叉树(红黑树), 动态维护有序序列
8. unordered_set, unordered_map, unordered_multiset
哈希表unordered_multimap
9. bitset 压位

### vector
``` C++
// 定义
vector<int> a;
vector<int> a(10);
vector<int> a(10, 3);

// 大小 o(1)
a.size();

// 是否为空 o(1)
a.empty();

// 清空
a.clear();

// 返回第一个
a.front();

// 返回最后一个
a.back();

// 向尾部追加一个
a.push_back();

// 尾部弹出
a.pop_back();

// 迭代器
a.begin();

// 最后一个数的后面
a.end();

// 遍历
for(int i = 0; i < a.size(); i++) cout << a[i] << ' ';

for(auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';

for(auto x : a) cout << x << ' ';

// 支持比较 字典序 a<b
vector a(4,3), b(4,5);

```
自动边长, 系统为某一个程序分配空间时, 所需时间基于本上与空间大小无关, 与申请次数有关.
32 -> 64 原有元素拷贝到新vector中

### pair
``` C++
// 定义
pair<int, string> p;

// 第一个元素
p.first

// 第二个元素
p.second

// 可以比较 first为第一关键字 second为第二关键字

// 创建
p = make_pair(10, "bing");
// 或
p = {10, "bing"};
```

### string
``` c++
string a = "bing";
a.size();
a.empty();
a.clear();

a+= "ABC";
a+= 'c';

// 从0开始 起始位置1 长度3
a.substr(1, 3)
// 从1开始 所有
a.substr(1)
// 返回存储string数组的起始位置
a.c_str();
```

### queue
``` C++
queue<int> a;
a.size();
a.empty();
// 无clear() 直接构造空queue
a.push();
a.front();
a.back();
a.pop(); 
```

### priority_queue
``` c++
// 默认大根堆
priority_queue<int> heap; 
// 小根堆
// 直接定义
priority_queue<int, vector<int>, greater<int>> heap;
// 或插入负数
heap.push(-x);
 
push() // 插入一个元素
top() // 返回堆顶元素
pop() // 弹出堆顶元素 
```

### stack
``` C++
push() // 向栈顶插入一个元素
top() // 返回栈顶元素
pop() // 弹出栈顶元素
```

### deque
``` C++
size()
empty()
clear()
front()
back()
push_back() / pop_back()
push_front() / push_back()
begin() / end() 
```

### set multiset
set不重复 / multiset 可重复
``` C++
size()
empty()
clear()
insert() //插入一个数
find() // 查找一个数
count() // 返回某一个数的个数
erase(x) // 删除等于这个数的所有元素 O(k + logn)
erase(itr) // 删除迭代器
lower_bound(x) // 返回大于等于x最小的迭代器
upper_bound(x) // 返回大于x最小的迭代器
begin() / end() // ++ -- 前驱 后继
```
### map multimap
``` C++
size()
empty()
clear()
insert() // 插入的是pair
erase() // pair或者迭代器
find()
begin() / end() // ++ -- 前驱 后继

map<string, int> a;
a["bing"] = 1;
cout << a["bing] << endl; // 1 O(logn)
```

### unordered
与上类似, 增删改查O(1)
但内部无序, 不支持lower_bound/upper_bound, 不支持++/--

### bitset
```
bitset<10000> s;
~, &, |, ^
>>, <<
==, !=
[]
count() // 返回有多少个1
any() // 是否有一个1
none() // 是否全为0
set() // 所有位置1
set(k, v) // 将第k位置为1
reset() // 所有位变成0
flip() // 等价于~
flip(k) // 第k位取反 
``` 