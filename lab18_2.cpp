#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect* a, Rect* b){
	if(a->y > b->y){
		if(a->y - a->h >= b->h)return 0;
		if(a->x > b->x){
			if(b->x + b->w <= a->x) return 0;
			double x = b->x + b->w - a->x, y = b->y - (a->y - a->h);
			return x * y;
		}else{
			if(a->x + a->w <= b->x) return 0;
			double x = min(b->w, a->x + a->w - b->x), y = min(b->h, b->y - (a->y - a->h));
			return x * y;
		}
	}else{
		if(b->y - b->h >= a->h)return 0;
		if(b->x > a->x){
			if(a->x + a->w <= b->x) return 0;
			double x = a->x + a->w - b->x, y = a->y - (b->y - b->h);
			return x * y;
		}else{
			if(b->x + b->w <= a->x) return 0;
			double x = min(a->w, b->x + b->w - a->x), y = min(a->h, a->y - (b->y - b->h));
			return x * y;
		}
	}
}


int main(){
	Rect R1 = {1,1,5,5};
	Rect R2 = {7,2,3,3};	
	cout << overlap(&R1,&R2);
}