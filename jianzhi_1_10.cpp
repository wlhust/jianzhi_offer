/*
剑指offer
@Author: wangli
@Date: 2019-03-30
*/

/* 
1. 二维数组中的查找
题目描述:
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include<stddef.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL){
    }    
};

class Solution1{
public:
    bool Find(int target, vector<vector<int> > array){
        int i = 0;
        int j = array[0].size() - 1;
        while(i<array.size() && j>=0){
            if(array[i][j] < target){
                i++;
            }
            else if(array[i][j] > target){
                j--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


/*
2. 替换空格
题目描述:
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution2{
public:
    void replaceSpace(char *str, int length){
        int orilength = 0;
        int countblank = 0;
        for(int i=0; str[i]!='\0'; i++){
            orilength++;
            if(str[i]==' '){
                countblank++;
            }
        }
        int len = orilength + 2 * countblank;
        char *p1 = str + orilength;
        char *p2 = str + len;
        while(p1<p2){
            if(*p1 == ' '){
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
            }
            else{
                *p2-- = *p1;
            }
            --p1;
        }
    }
};


/*
3. 从尾到头打印链表
题目描述:
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/


class Solution3{
public:
    vector<int> printListFromTailToHead(ListNode* head){
        vector<int> out;
        stack<int> arr;
        ListNode* p = head;
        while(p!=NULL){
            arr.push(p->val);
            p = p-> next;
        }
        int len = arr.size();
        for(int i=0; i<len; i++){
            out.push_back(arr.top());
            arr.pop();
        }
        return out;
    }
};


/*
5. 用两个栈实现队列
问题描述:
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/
class Solution5{
public:
    void push(int node){
        stack1.push(node);
    }

    int pop(){
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int out = stack2.top();
        stack2.pop();
        return out;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};


/*
6. 旋转数组的最小数字
题目描述:
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
class Solution6{
public:
    int minNumberInRotateArray(vector<int> rotateArray){
        int length = rotateArray.size();
        int fir = rotateArray[0];
        if(length == 1){
            return fir;
        }
        int left = 0;
        int right = length - 1;
        int mid = left;
        while(left < right){
            if((right - left) == 1){
                mid = right;
                break;
            }
            else{
                mid = (left + right) / 2;
                if(rotateArray[mid] < fir){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
        }
        return rotateArray[mid];
    }
};


/*
7. 斐波拉契数列
题目描述:
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
class Solutioin7{
public:
    int Fibonacci(int n){
        int fir = 0;
        int sec = 1;
        int tmp = sec;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=1; i<n; i++){
            tmp = sec;
            sec = fir + sec;
            fir = tmp;
        }
        return sec;
    }
};


/*
8. 跳台阶
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
class Solutioin8{
public:
    int Fibonacci(int n){
        int fir = 0;
        int sec = 1;
        int tmp = sec;
        if(n==0) return 0;
        if(n==1) return 1;
        for(int i=0; i<n; i++){
            tmp = sec;
            sec = fir + sec;
            fir = tmp;
        }
        return sec;
    }
};


/*
9. 变态跳台阶
题目描述:
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
class Solution9{
public:
    int jumpFloorII(int number) {
        int res = 1;
        for(int i=1; i<number; i++){
            res = res * 2;
        }
        return res;
    }
};


/*
10. 矩形覆盖
题目描述:
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution10{
public:
    int rectCover(int number){
        int fir = 0;
        int sec = 1;
        int tmp = 1;
        for(int i=0; i<number; i++){
            tmp = sec;
            sec = fir + sec;
            fir = tmp;
        }
        return sec;
    }
};


/*
11. 二进制中1的个数
题目描述:
输入一个整数，输出该数二进制表示中1的个数，负数用补码表示
*/

/*
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，
那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1
(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。

举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。
减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，
因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。
这个时候如果我们再把原来的整数和减去1之后的结果做与运算，
从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.
也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.
那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
*/
class Solution11_1 {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n != 0){
             count++;
             n = n & (n - 1);
         }
         return count;
     }
};

class Solution11_2{
public:
    int NumberOf1(int n){
        int f_1 = 0x55555555;
        int f_2 = 0x33333333;
        int f_4 = 0x0f0f0f0f;
        int f_8 = 0x00ff00ff;
        int f_16 = 0x0000ffff;
        int count1 = (n & f_1) + (n >> 1) & f_1;
        int count2 = (count1 & f_2) + (count1 >> 2) & f_2;
        int count4 = (count2 & f_4) + (count2 >> 4) & f_4;
        int count8 = (count4 & f_8) + (count4 >> 8) & f_8;
        int count16 = (count8 & f_16) + (count8 >> 16) & f_16;
        return count16;
    }
};


/*
13. 调整数组顺序使奇数位于偶数前面
题目描述:
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

class Solution13 {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> array_tmp;
        vector<int>::iterator ib1;
        ib1 = array.begin();
        for(; ib1!=array.end();){
            if(*ib1 % 2 == 0){
                array_tmp.push_back(*ib1);
                ib1 = array.erase(ib1);
            }
            else{
                ib1++;
            }
        }
        vector<int>::iterator ib2, ie2;
        ib2 = array_tmp.begin();
        ie2 = array_tmp.end();
        for(; ib2!=ie2 ;ib2++){
            array.push_back(*ib2);
        }
    }
};


/*
14. 链表倒数第k个节点
题目描述:
输入一个链表，输出链表的倒数第k个节点
*/
// 双指针

class Solution14{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k){
        ListNode* p = pListHead;
        for(int i=0; i<k; i++){
            if(!p){ 
                return NULL;
            }
            else{
                p = p->next;
            }
        }
        while(p){
            pListHead = pListHead->next;
            p = p->next;
        }
        return pListHead;
    }
};


/*
15. 反转链表
题目描述:
输入一个链表，反转链表后，输出新链表的表头。
*/

class Solution15 {
public:
    ListNode* ReverseList(ListNode* pHead){
        if(!pHead || !pHead->next){
            return pHead;
        }
        ListNode* last = NULL;
        ListNode* tmp = NULL;
        while(pHead){
            tmp = pHead->next;
            pHead->next = last;
            last = pHead;
            pHead = tmp;
        }
        return last;
    }
};



/*
16. 合并两个排序的链表
题目描述: 
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则
*/

class Solutioin16 {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
        ListNode* mergeHead = new ListNode(-1);
        ListNode* p = mergeHead;
        while(pHead1 && pHead2){
            if(pHead1->val > pHead2->val){
                mergeHead->next = pHead2;
                pHead2 = pHead2->next;
            }
            else{
                mergeHead->next = pHead1;
                pHead1 = pHead1->next;
            }
            mergeHead = mergeHead->next;
        }
        if(pHead1){
            mergeHead->next = pHead1;
        }
        if(pHead2){
            mergeHead->next = pHead2;
        }
        return p->next;
    }
};

/*
17. 树的子结构
题目描述:
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

class Solution17 {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1 || !pRoot2) return false;
        return isSubTree(pRoot1, pRoot2) || \
                HasSubtree(pRoot1->left, pRoot2) || \
                HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool isSubTree(TreeNode* pRoot1, TreeNode* pRoot2)
    {    //如果tree2遍历完了则返回true
        if(!pRoot2) return true;
        // tree2没遍历完，但是tree1遍历完了返回false
        if(!pRoot1) return false;
        if(pRoot1->val == pRoot2->val){
            return isSubTree(pRoot1->left, pRoot2->left) && 
                isSubTree(pRoot1->right, pRoot2->right);
        }
        else return false;
    }
};

/*
18. 二叉树的镜像
题目描述:
操作给定的二叉树，将其变换为源二叉树的镜像。
*/

class Solution18 {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL) return;
        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

/*
20. 包含min函数的栈
题目描述:
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

class Solution20 {
public:
    void push(int value) {
        if(assist.empty()){
            assist.push(value);
        }
        else if(value<assist.top()){
            assist.push(value);
        }
        else{
            assist.push(assist.top());
        }
        stack1.push(value);
    }
    void pop() {
        if(!stack1.empty()){
            stack1.pop();
            assist.pop();
        }
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return assist.top();
    }
private:
    stack<int> stack1;
    stack<int> assist;
};


/*
21. 栈的压入，弹出序列
题目描述:
输入两个整数序列，第一个序列表示栈的压入顺序，
请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的)
*/

// 借助辅助栈模拟入栈和出栈的过程
class Solution21 {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> assist;
        int id = 0;
        for(int i=0; i<popV.size(); i++){
            while(assist.empty() || assist.top()!=popV[i]){
                assist.push(pushV[id++]);
                if(id > pushV.size()){
                    return false;
                }
            }
            assist.pop();
        }
        if(assist.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};



/*
22. 从上往下打印二叉树
题目描述:
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
返回从上到下每个节点值列表，例：[1,2,3]
*/
class Solution22 {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> que;
        queue<TreeNode*> q;
        TreeNode* fr;
        if(root==NULL) return que;
        q.push(root);
        while(!q.empty()){
            fr = q.front();
            que.push_back(fr->val);
            if(fr->left != NULL){
                q.push(fr->left);
            }
            if(fr->right != NULL){
                q.push(fr->right);
            }
            q.pop();
        }
        return que;
    }
};

/*
23. 二叉搜索树的后序遍历序列
题目描述:
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/

class Solution23 {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return IsSearchTree(sequence, 0, sequence.size()-1);
    }
    
    bool IsSearchTree(vector<int> sequence, int begin, int end){
        if(begin>=end) return true;
        int root = sequence[end];
        int gate = begin;
        while(sequence[gate] < root && gate<end){
            gate++;
        }
        for(int i=gate; i<end; i++){
            if(sequence[i] < root) return false;
        }
        return true && IsSearchTree(sequence, begin, gate-1) && IsSearchTree(sequence, gate, end-1);
    }
};


/*
28. 数组中出现次数超过一半的数字
题目描述:
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/*
如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，
若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，
则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。
然后再判断它是否符合条件即可。
*/

class Solution28 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len = numbers.size();
        int num = numbers[0];
        int count = 0;
        for(int i=0; i<len; i++){
            if(numbers[i] == num){
                count++;
            }else{
                count--;
            }
            if(count==0){
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for(int i=0; i<len; i++){
            if(numbers[i] == num) count++;
            if(count * 2 > len) return num;
        }
        return 0;
    }
};


/*
30. 连续子数组的最大和
题目描述:

HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。
今天测试组开完会后,他又发话了:在古老的一维模式识别中,
常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少是1)
*/

class Solution31 {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int max_sum = 0xffffffff;
        int cur_sum = 0;
        for(int i=0; i<array.size(); i++){
            if(cur_sum < 0){
                cur_sum = array[i];
            }
            else cur_sum += array[i];
            if(cur_sum > max_sum){
                max_sum = cur_sum;
            }
        }
        return max_sum;
    }
};


/*
40. 数组中只出现一次的数字
题目描述:
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

/*
思路就是使用异或，但是与在成对出现的数字中查找一个单独的数字不同的是
需要利用异或结果的最低位为1的flag将数组中的数字分为两类，一类是与flag按位与为0，
另一类为不为0，这样再分别异或一次就能够找出这两个数。很是巧妙。
其中有一个语法上容易忽略的坑：==的优先级比&高，所以&时需要加括号。
*/

class Solution40 {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size()<2) return ;
        int myxor = 0;
        int flag = 1;
        for(int i=0; i<data.size(); i++){
            myxor ^=data[i];
        }
        while((myxor & flag) == 0){
            flag <<= 1;
        }
        *num1 = myxor;
        *num2 = myxor;
        for(int i=0; i<data.size(); i++){
            if((data[i] & flag) == 0){
                *num1 ^= data[i];
            }
            else *num2 ^= data[i];
        }
    }
};

/*
41. 和为s的连续整数序列
题目描述:
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!
*/

/*
序列中间值代表了平均值大小，假设序列长度为n，序列中间值为（s/n）
1. 当n为奇数时，序列中间值刚好为平均值。所以需要满足: (n % 2) == 1 && sum % n == 0（sum能被n整除）
2. 当n为偶数时，序列中间值为中间两数的平均值，要满足: (n % 2) == 0 && (sum % n) * 2 == n，保证sum/n的小数部分为0.5
*/

class Solution41 {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        int start, mean, bias;
        for(int n=2; n<sqrt(2*sum); n++){
            if((n % 2 == 1 && sum % n == 0) || (n % 2 == 0 && (sum % n) * 2 == n)){
                vector<int> tmp;
                mean = sum / n;
                bias = (n + 1) / 2;
                start = mean - (bias - 1);
                for(int j=0; j<n; j++){
                    tmp.push_back(start+j);
                }
                res.insert(res.begin(),tmp);
            } 
        }
        return res;
    }
};


/*
42. 两数之和v1(leetcode)
题目描述:
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，
并返回他们的数组下标。
*/

class Solution42_v1{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> out;
        std::map<int, int> e;
        for(int i; i<nums.size(); i++){
            if(e.count(target-nums[i])){
                out.push_back(i);
                out.push_back(e[target-nums[i]]);
                return out;
            }
            e[nums[i]] = i;
        }
        return out;
    }
};



/*
42. 两数之和v2(niuke)
题目描述:
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

class Solution42_v2 {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int n = array.size();
        int i = 0; 
        int j = n - 1;
        while(i < j){
            if((array[i] + array[j]) > sum){
                j --;
            }
            else if((array[i] + array[j]) < sum){
                i ++;
            }
            else{
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
        }
        return res;
    }
};


/*
43. 左旋转字符串
题目描述:
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/

/*
三次翻转，s="abcXYZdef", X="abc", Y="XYZdef",利用YX=(X^T Y^T)^T, X^T表示X的翻转。
*/
class Solution43 {
public:
    string LeftRotateString(string str, int n) {
        if(str.size()<=1) return str;
        n = n % str.size();
        reverse(str.begin(), str.begin() + n);
        reverse(str.begin() + n, str.end());
        reverse(str.begin(), str.end());
        return str;
    }
};


/*
44. 翻转单词顺序列
题目描述:
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，
这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

class Solution44 {
public:
    string ReverseSentence(string str) {
        string res = "";
        string tmp = "";
        for(int i=0; i<str.size(); i++){
            if(str[i]==' '){
                res = " " + tmp + res;
                tmp = "";
            }
            else tmp += str[i];
        }
        res = tmp + res;
        return res;
    }
};