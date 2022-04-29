// 小根堆
priority_queue<int,vector<int>,greater<int> >q;

//大根堆
priority_queue<int,vector<int>,less<int> >q;

//相关操作
q.push(num) //num push进堆
q.top() // 访问堆顶元素
q.pop() // 弹出堆顶元素
