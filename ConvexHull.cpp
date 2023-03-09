#include<iostream>
#include<math.h>
using namespace std;
class Point{
	public:
	int x, y;
	public:
	Point(){
	}
	friend istream &operator>>(istream &a, Point &p);
	friend ostream &operator<<(ostream &a, Point p);
	double distance();
	bool operator>(Point p2);
};
Point p0;
   double Point::distance(){
		return sqrt((x-p0.x)*(x-p0.x)+(y-p0.y)*(y-p0.y));
	}
	bool Point::operator>(Point p2){
		if((p2.x - p0.x)*(y - p0.y) > (x - p0.x)*(p2.y - p0.y))
		    return true;
		else if(((p2.x - p0.x)*(y - p0.y) == (x - p0.x)*(p2.y - p0.y)) && distance() > p2.distance())
			return true;
		else
			return false;
	}

istream &operator>>(istream &a, Point &p){
	a>>p.x>>p.y;
	return a;
}

ostream &operator<<(ostream &a, Point p){
	a<<"("<<p.x<<", "<<p.y<<")";
	return a;
}
void read(Point a[], int n){
	cout<<"Enter " << n << " points\n";
	for(int i=0; i<n; i++)
		cin >> a[i];
}

void print(Point a[], int n){
	cout<<"\nList of points is: [";
	for(int i=0; i<n; i++)
		cout << a[i] << ", ";
	cout<<"\b\b]";
}
class Node{
	public:
	Point data;
	Node *leftLink, *rightLink;
};
class CDLL{
	Node *first;
	public:
	CDLL(){first = NULL;}
	void create(Point a[], int n);
	void display();
	Node *getFirst(){ return first;}
	void del(Node *n);
};
void bubbleSort(Point a[], int n){
	for(int i=1; i<n; i++){
		bool isSorted = true;
		for(int j=0; j<=n-i-1; j++){
			if(a[j] > a[j+1]){
				Point x = a[j]; a[j] = a[j+1]; a[j+1] = x;
				isSorted = false;
			}
		}
		if(isSorted == true)
		   break;
	}
}
Point getP0(Point a[], int n){
	Point p0 = a[0];
	for(int i=1; i<n; i++)
		if(a[i].y < p0.y || (a[i].y == p0.y && a[i].x < p0.x))
		   p0 = a[i];
	return p0;
}

int main(){
	cout<<"How many points? ";
	int n;
	cin >> n;
	Point *a = new Point[n];
	read(a, n);
	print(a, n);
	p0 = getP0(a, n);
	bubbleSort(a, n);
	print(a, n);
	return 0;
}
