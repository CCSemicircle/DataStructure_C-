#include"Comp.h"
#include"Swap.h"
#include"Assert.h"

// 实现最大堆
template<typename E>
class heap {
private:
	E* Heap;			// 指向堆数组的指针
	int maxsize;		// 堆的最大空间
	int n;				// 堆中当前元素个数
	int cnt[2];			// 计数器

	void siftdown(int pos) {					// 将整个堆从某个元素开始重排列，将较小值往后放
		while (!isLeaf(pos)) {
			int j = leftchild(pos);
			int rc = rightchild(pos);
			if ((rc < n) && !prior(Heap[rc], Heap[j]) && (++cnt[0])) j = rc;	 // 将较大值的index赋值给j			
			if (!prior(Heap[pos], Heap[j]) && (++cnt[0])) return;				// 根结点与子结点中的较大值比较
			swap(Heap, pos, j);
			cnt[1]++;
			pos = j;
		}
	}

public:
	// 构造函数
	heap(E* h, int num, int max) {
		Heap = h;
		n = num;
		maxsize = max;
		buildHeap();
	}

	int size() const { return n; }	// 返回当前堆的大小

	// 判断是否为叶子节点
	bool isLeaf(int pos) const {
		return (pos >= n / 2) && (pos < n);		// 判别依据：根据完全二叉树的特性，几乎每添加一层结点都是对已有结点数加倍，并且结点从左至右依次排布并存储在数组中

	}

	int leftchild(int pos) const { return 2 * pos + 1; }		// 返回左子结点

	int rightchild(int pos) const { return 2 * pos + 2; }		// 返回右子结点

	int parent(int pos)const { return (pos - 1) / 2; }			// 返回父结点

	void buildHeap() { for (int i = n / 2 - 1; i >= 0; i--) siftdown(i); }	// 按最大堆排列调整堆的排布

	// 插入元素
	void insert(const E& it) {
		Assert(n < maxsize, "Heap is full");
		int curr = n++;
		Heap[curr] = it;
		while ((curr!=0) && !prior(Heap[curr], Heap[parent(curr)]) && (++cnt[0])) {			// 将元素移动到合适的结点
			swap(Heap, curr, parent[curr]);
			cnt[1]++;
			curr = parent(curr);
		}
	}

	// 移除并返回根结点
	E removefirst() {
		Assert(n > 0, "Heap is empty");
		swap(Heap, 0, --n);
		cnt[1]++;
		if (n != 0) siftdown(0);
		return Heap[n];
	}

	// 移除并返回指定元素
	E remove(int pos) {
		Assert((pos >= 0) && (pos < n), "Bad position");
		if (pos == (n - 1)) n--;			// 如果指定的是最后一个元素，直接将当前元素个数减一即可
		else {
			swap(Heap, pos, --n);			// 将指定index的值与最后的元素交换
			cnt[1]++;
			while ((pos != 0) && (!prior(Heap[pos], Heap[parent(pos)]))) {
				swap(Heap, pos, parent(pos));			// 将较大值往前放
				cnt[1]++;
				pos = parent(pos);
			}
			if (n != 0) siftdown(pos);					// 将整个堆从pos开始重排列，将较小值往后放
		}
		return Heap[n];				// 最末尾元素为指定index的值
	}

	int ccnt() { return cnt[0]; }			// 返回比较次数

	int excntt() { return cnt[1]; }		   // 返回交换次数
};
