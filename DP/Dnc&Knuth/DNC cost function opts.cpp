https://codeforces.com/contest/868/problem/F


/*
Where calculating cost (l,r) is not so easy we can use the fact that we are filling the dp table in recursive middle by middle way

thus if we use a pattern like below the total movement of the l and r pointer will be O(n) per layer


SO THIS WILL be n*k*logn soltuion only
*/

int n, k, l = 1, r = 0;
ll a[maxn + 10], dp[maxn + 10][maxk + 10], cnt[maxn + 10], quantity = 0;

void add(int p)
{
    quantity += cnt[a[p]];
    cnt[a[p]]++;
}
void del(int p)
{
    cnt[a[p]]--;
    quantity -= cnt[a[p]];
}
ll cost(int ql, int qr)
{
    while (l < ql) del(l++);
    while (l > ql) add(--l);
    while (r < qr) add(++r);
    while (r > qr) del(r--);
    return quantity;
}
void dnc(int j, int l, int r, int optl, int optr)
{
    if (l > r) return ;
    int m = l + r >> 1;
    ii best = {INF, -1};

    for (int z = optl; z <= min(m, optr); z++)
        best = min(best, {dp[z - 1][j - 1] + cost(z, m), z});

    dp[m][j] = best.fi;
    dnc(j, l, m - 1, optl, best.se);
    dnc(j, m + 1, r, best.se, optr);
}
