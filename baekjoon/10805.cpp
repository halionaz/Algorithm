// L 모양의 종이 자르기
// 다이나믹 프로그래밍

// 10803과 유사한 풀이

#include <iostream>
#include <algorithm>
#include <cstring>

int N,M,n,m;
int rect_dp[51][51];
int dp[51][51][51][51];

int rectSolve(int H, int W){
    if(W > H){
        return rectSolve(W,H);
    }
    if(H % W == 0){
        return H / W;
    }

    int &ret = rect_dp[H][W];

    if(ret != -1){
        return ret;
    }
    
    ret = H * W;

    for(int i = 1; i < H; i++){
        ret = std::min(ret, rectSolve(i,W) + rectSolve(H-i, W));
    }
    for(int i = 1; i < W; i++){
        ret = std::min(ret, rectSolve(H, i) + rectSolve(H, W - i));
    }
    return ret;
}

int solve(int H, int W, int h, int w){
    if(W > H){
        return solve(W, H, w, h);
    }
    int &ret = dp[H][W][h][w];
    if(ret != -1){
        return ret;
    }
    ret = H*W;
    int hr = H - h;
    int wr = W - w;
    for(int i = 1; i < H; i++){
        if(i < h){
            ret = std::min(ret, rectSolve(i, wr) + solve(H-i, W, h - i, w));
        } else if (i == h){
            ret = std::min(ret, rectSolve(h, wr) + rectSolve(H - h, W));
        } else {
            ret = std::min(ret, solve(i, W, h, w) + rectSolve(H-i, W));
        }
    }
    for(int i = 1; i < W; i++){
        if(i < wr){
            ret = std::min(ret, rectSolve(H, i) + solve(H, W - i, h, w));
        } else if (i == wr){
            ret = std::min(ret, rectSolve(H, wr) + rectSolve(hr, w));
        } else {
            ret = std::min(ret, solve(H, i, h, i - wr) + rectSolve(hr, W - i));
        }
    }
    return ret;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    memset(dp, -1, sizeof(dp));
    memset(rect_dp, -1, sizeof(rect_dp));

    std::cin >> N >> M >> n >> m;

    std::cout << solve(N,M,n,m) << '\n';

    return 0;
}