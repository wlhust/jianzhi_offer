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
两数之和v1(leetcode)
题目描述:
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，
并返回他们的数组下标。
*/

class Solution{
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
两数之和v2(niuke)
题目描述:
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
*/

class Solutionv2 {
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
