/**
## as fast as possible
### 题意


### 思路
当每个人乘车的时间相同时, 总用时最少.
- 设每个人走路和乘车的时间分别为`t1`和`t2`, 则对于每个人: v1*t1 + v2*t2 = l,
总用时t = t1 + t2
- 设车子总共要运送g次, 则 g = n/k + (n%k>0)?1 :0,
- 返回g-1次, 设每次返回的用时为t3
- 对于车子的每一个来回: 人的位移 = 车的位移
                       => v1*(t2+t3) = v2*t2-v2*t3
                       => t3 = (v2-v1)*t2/(v2+v1)
- 最终车子也是会由起点走到终点:
l = 最后一趟的位移 + 前面g-1趟的位移
  = v2*t2 + (g-1)*v2*(t2-t3)
或者:
l = g趟往前 - (g-1)趟往回
  = g*v2*t2 - (g-1)*v2*t3
=> t3 = (g*v2*t2-l)/((g-1)*v2)

=> (g*v2*t2-l)/((g-1)*v2) = (v2-v1)*t2/(v2+v1)
=> t2 = l / (g*v2 - (g-1)*v2*temp), temp = (v2-v1)/(v2+v1)
=> t1 = (l-v2*t2) / v1

t = t1 + t2 = ...

- ref: 
<http://blog.csdn.net/snowy_smile/article/details/52032301>

**/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int n, k;
    double l, v1, v2;

    scanf("%d%lf%lf%lf%d", &n,&l,&v1,&v2,&k);
    int g = n/k + ((n%k>0)?1:0);
    double temp = (v2-v1)/(v2+v1);
    double t2 = l / (g*v2 - (g-1)*v2*temp);
    double t1 = (l-v2*t2) / v1;

    // printf("%d, %f, %f, %f\n", g, temp, t2, t1);
    printf("%.7f\n", t1+t2);

    return 0;
}

