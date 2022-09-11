// 수열과 쿼리 21
// 세그먼트 트리

// 세그먼트 트리에 그 구간에 더해진 값들을 저장함

#include<iostream>
#include<algorithm>
#include<vector>

typedef long long ll;

const int MAX = 100000;

ll arr[MAX + 1];
ll tree[MAX * 4];

void init(int node, int s, int e)
{
	if (s == e)
	{
		tree[node] = arr[s];
		return;
	}
	tree[node] = 0;
	int mid = (s + e) / 2;
	init(node * 2,s, mid);
	init(node * 2 + 1, mid + 1, e);
}

void updateTree(int node, int s, int e, int l, int r, ll k)
{	
	if (s > r || e < l){
        return; 
    } 
	if (l <= s && e <= r)
	{
		tree[node] += k;
		return;
	}
	int mid = (s + e) / 2;
	updateTree(node*2, s, mid, l, r, k);
	updateTree(node*2 + 1, mid + 1, e, l, r, k);
}

ll search(int node, int s, int e, int index, ll ans)
{	
	if (index < s || index > e){
        return 0;
    } else {

        ans += tree[node];

        if (s == e){
            // 목표 인덱스에 도달했으므로 return
            return ans;
        } else {
            int mid = (s + e) / 2;
            return search(node * 2, s, mid, index, ans) + search(node * 2 + 1, mid + 1, e, index, ans);
        }

    }
}

int main(void)
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	int n, m;
	std::cin >> n;

	for (int i = 1; i <= n; i++){
		std::cin >> arr[i];
    }

	init(1, 1, n);

	std::cin >> m;

	while (m--)
	{
		int q, l, r, index;
		ll k;

		std::cin >> q;

		if (q == 1)
		{
			std::cin >> l >> r >> k;
			updateTree(1, 1, n, l, r, k);
		} else {
			std::cin >> index;
			std::cout << search(1, 1, n, index, 0) <<'\n';
		}
	}

    return 0;
}