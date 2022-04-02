// 수열과 쿼리 21
// 세그먼트 트리

#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;

const int MAX = 100000;

ll a[MAX + 1];
ll tree[MAX * 4];

void init(int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = a[start];
		return;
	}
	tree[node] = 0;
	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
}

void updateTree(int start, int end, int node, int left, int right, ll k)
{	
	if (start > right || end < left){
        return; 
    } 
	if (left <= start && end <= right)
	{
		tree[node] += k;
		return;
	}
	int mid = (start + end) / 2;
	updateTree(start, mid, node * 2, left, right, k);
	updateTree(mid + 1, end, node * 2 + 1, left, right, k);
}

ll search(int start, int end, int node, int index, ll ans)
{	
	if (index < start || index > end){
        return 0;
    }

	ans += tree[node];

	if (start == end){

        return ans;

    } 
	int mid = (start + end) / 2;
	return search(start, mid, node * 2, index, ans) + search(mid + 1, end, node * 2 + 1, index, ans);
}

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n;

	for (int i = 1; i <= n; i++){
		std::cin >> a[i];
    }

	init(1, n, 1);

	std::cin >> m;

	while (m--)
	{
		int q, left, right, index;
		ll k;

		std::cin >> q;

		if (q == 1)
		{
			std::cin >> left >> right >> k;
			updateTree(1, n, 1, left, right, k);
		} else {
			std::cin >> index;
			std::cout << search(1, n, 1, index, 0) <<'\n';
		}
	}

    return 0;
}