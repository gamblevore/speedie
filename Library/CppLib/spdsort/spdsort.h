
// spdsort.h  http://gamblevore.org, by theodore h. smith, public domain software
// basically... just testing some sorting algorithms...

// my spdsort is like a normal quicksort, but it has better characteristics:
	// 1) handles invalid sort functions. You need this if you are making a programming language, cos you don't want some kid making his first game to crash his computer just cos the sort function is a little bit off. Garbage in = garbage out... thats all we want. C++ sorts will actually crash your app with invalid sort functions.
	// 2) Seems a lil faster?
	// 3) Handles sorted and reverse sorted arrays very fast
	// 4) Code is available and not too big. (unlike C++ sort)
	// 5) Only calls the compare function once... this is important for very slow compare functions. C++ sort calls it twice per-pair of items.
	// 6) It doesn't use a garbage design for the return value. It uses an int, which can store equal, less or more. C++'s sort uses a BOOL. Which... its just not right. If you are depth-sorting some objects, it can lead to flicker as equally distant objects will flicker onscreen.
	// 7) Actually you are free to return a bool or int! My sorter checks if your return value is <= 0. This is true for 0, but not for 1.

// You'll have to modify this yourself to be useful, of course.


#ifndef __spdsort_type__
	#define __spdsort_type__ int
#endif
extern "C" void SpdSort(void* dat__, __spdsort_type__* low, __spdsort_type__* high);


#ifndef __SPD_SORT__
#define __SPD_SORT__
#include <algorithm>


#ifndef __spdsort_func__
	#define __spdsort_func__ SpdDemoSort
	inline int SpdDemoSort (void* dat__, __spdsort_type__ a, __spdsort_type__ b) {
		return b-a;
	}
#endif

static __spdsort_type__* SortABit(void* dat__, __spdsort_type__* low, __spdsort_type__* high) {
// This design might seem strange, but it avoids bugs with invalid compare-funcs
// which is important for someone making a programming language (me).
// its also faster for non-pathological data, or slower compare-funcs.
    auto pivot = *high;
    while (__spdsort_func__(dat__, pivot, *low++) <= 0)
		if (low >= high)
			return 0;

	auto i = low - 2;
    while (low < high) {
        if (__spdsort_func__(dat__, pivot, *low) <= 0)
            std::swap(*++i, *low);
		low++;
	}
	return i+1;
}


static void QuickReverse(__spdsort_type__* low, __spdsort_type__* high) {
	do {
		std::swap(*low, *high);
	} while (++low < --high);
}


extern "C" void SpdSort(void* dat__, __spdsort_type__* low, __spdsort_type__* high) {
	if (high == low+1) { // reduce comparisons...
		if (__spdsort_func__(dat__, *low, *high) <= 0)	
			std::swap(*high, *low);
		return;
	}
    auto p = SortABit(dat__, low, high);
    if (!p) {
		p = low;
		while (__spdsort_func__(dat__, p[1], p[0]) <= 0)
			if (++p >= high)
				return;										// Avoid disasterous worst-case (sorted data).
		p = high;
    } else {
		if (p == low) { // avoid pointless compares for 2 element reversals.
			while (__spdsort_func__(dat__, p[0], p[1]) <= 0)
				if (++p >= high)							// Avoid reverse-sort. Also disasterous.
					return QuickReverse(low, high);
			p = low;
		}
		std::swap(*p, *high);
	}
	
    if (low < p - 1) {
		SpdSort(dat__, low, p - 1);
	}
	if (p+1 < high) {
		SpdSort(dat__, p + 1, high);
	}
}


#endif
