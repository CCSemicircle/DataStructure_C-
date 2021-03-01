#include"Comp.h"
#include"Swap.h"

//  µœ÷√∞≈›≈≈–Ú
template<typename E>
void bubsort(E A[], int n,int cnt[]) {
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if (prior(A[j], A[j - 1]) && (++cnt[0])) {
				swap(A, j, j - 1);
				cnt[1]++;
			}
}
