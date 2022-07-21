# 숫자 카드 2
# 이분 탐색

# #이분 탐색 - count() 사용
# N = int(input())
# card = sorted(map(int,input().split()))
# M = int(input())
# search = map(int,input().split())
# def binSearch(arr, i, start, end) :
#     if start>end :
#         return 0
#     else :
#         mid = (start + end) // 2
#         if arr[mid] == i :
#             return arr[start:end+1].count(i)
#         elif arr[mid] < i :
#             return binSearch(arr, i, mid+1, end)
#         else :
#             return binSearch(arr, i, start, mid-1)
# n_dic = {}
# for i in card:
#     start = 0
#     end = N - 1
#     if i not in n_dic:
#         n_dic[i] = binSearch(card,i , start, end)
# print(' '.join(str(n_dic[x]) if x in n_dic else '0' for x in search ))

#이분 탐색 - 직접 세보기 사용
N = int(input())
card = sorted(map(int,input().split()))
M = int(input())
search = map(int,input().split())
def binSearch(arr, i, start, end) :
    if start>end :
        return 0
    else :
        mid = (start + end) // 2
        if arr[mid] == i :
            cnt = 1
            # mid로부터 큰 쪽에 같은 것이 있는지 체크
            j = 0
            while mid + j <= end :
                if arr[mid+j] != i :
                    break
                else :
                    j += 1
            cnt += j-1
            # mid로부터 작은 쪽에 같은 것이 있는지 체크 
            j = 0
            while mid - j >= start :
                if arr[mid-j] != i :
                    break
                else :
                    j += 1
            cnt += j-1
            return cnt
        elif arr[mid] < i :
            return binSearch(arr, i, mid+1, end)
        else :
            return binSearch(arr, i, start, mid-1)
n_dic = {}
for i in card:
    start = 0
    end = N - 1
    if i not in n_dic:
        n_dic[i] = binSearch(card,i , start, end)
print(' '.join(str(n_dic[x]) if x in n_dic else '0' for x in search ))
