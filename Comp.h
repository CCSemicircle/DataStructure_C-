// 实现比较函数
template<typename E> 
bool prior(E a, E b) {			// 较小的数在前
	if (a < b) return true;
	else return false;
}
