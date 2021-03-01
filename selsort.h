#include"Comp.h"
#include"Swap.h"

//  µœ÷—°‘Ò≈≈–Ú
template<typename E>
void selsort(E A[], int n,int cnt[]) {
	for (int i = 0; i < n - 1; i++) {
		int lowindex = i;
		for (int j = n - 1; j > i; j--)
			if (prior(A[j], A[lowindex]) && (++cnt[0])) lowindex = j;
		swap(A, i, lowindex);
		cnt[1]++;
	}
}
