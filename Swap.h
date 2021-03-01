// 实现交换函数
template<typename E> 
void swap(E A[], int a, int b){
	E temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}
