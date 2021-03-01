#include"Comp.h"
#include"Swap.h"

//  µœ÷≤Â»Î≈≈–Ú
template<typename E>
void inssort(E A[], int n,int cnt[]) {
	for(int i=1;i<n;i++)
		for (int j = i; (j > 0) && (prior(A[j], A[j - 1]) && (++cnt[0])); j--) {
			swap(A, j, j - 1);
			cnt[1]++;
		}
}
