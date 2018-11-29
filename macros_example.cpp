#define MAX(x, y, r) {	__typeof__ (x) _x = (x); \
						__typeof__ (y) _y = (y);\
						r = (_x > _y)? _x :_y; }