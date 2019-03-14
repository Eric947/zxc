#include <iostream>
#include <cstdio>

using namespace std;

// ������Ĺؼ��� ���м������Ϊ���ޡ� ȷ��������ʼ����ֹ����
void split(int s[], int n, int &l, int &r)
{
    int mid = n/2;
    for(l=0; l<n; ++l)
    {
        if (s[l] == s[mid])
            break;
    }
    for(r=l+1; r<n; ++r)
    {
        if (s[r] != s[mid])
            break;
    }

}

// num ������ maxCnt ����
void getMaxCnt(int &mid, int &maxCnt, int s[], int n)
{
    int l, r;
    split(s, n, l, r);  // ���зָ��������Ǳ�����Ĺؼ�
    int num = n/2;
    int cnt = r-l;

    // update
    if (cnt > maxCnt)
    {
        maxCnt = cnt;
        mid = s[num];
    }

    // l ��ʾ��ߵĸ�������ߵĸ���������� maxCnt ���б�Ҫ��Ѱ
    if (l+1 > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s, l+1);
    }

    // �ұ���Ѱ, �ұ��������ʼ��ַҪ���
    if (n-r > maxCnt)
    {
        getMaxCnt(mid, maxCnt, s+r, n-r);
    }
}

int main(void)
{
    int s[] = {1, 2, 2, 2, 3, 5};
    int n = sizeof(s)/sizeof(s[0]);

    int maxCnt = 0;
    int num = 0;
    getMaxCnt(num, maxCnt, s, n);
	   printf("%d %d\n", num, maxCnt);

    return 0;
}
