#include "stdafx.h"


class Picture
{
	friend Picture frame(const Picture&);                      //加框
	friend Picture operator&(const Picture&, const Picture&);  //纵向合并
	friend Picture operator|(const Picture&, const Picture&);  //横向合并
	friend ostream& operator << (ostream& o, const Picture& p);
private:
	int height, width;
	char* data;
	char& position(int row, int col){
		return data[row * width + col];
	};
	char position(int row, int col) const{
		return data[row * width + col];
	};
	void copyblock(int,int,const Picture&);
public:
	Picture() : height(0),width(0),data(0){};
	Picture(const char* const*, int);
	Picture(const Picture& );
	~Picture();
	Picture& operator=(const Picture&);
	static int max(int m, int n)
	{
		return m > n ? m : n;
	};
	void init(int h, int w);
	void clear(int , int ,int ,int );
};

ostream& 
	operator << (ostream& o, const Picture& p)
{
	for(int i = 0; i < p.height; ++i)
	{
		for(int j =0; j < p.width; ++j)
			o << p.position(i,j);
		o << endl;
	}
	return o;
};


void Picture::init(int h, int w)
{
	height = h;
	width = w;
	data = new char[height * width];
};

Picture::Picture(const char* const* array, int n)
{
	int w = 0;
	int i ;
	for(i = 0; i < n; i++)
		w = Picture::max(w, strlen(array[i]));
	init(n,w);
	for(i = 0; i < n; i++)
	{
		const char* src = array[i];
		int len = strlen(src);
		int j = 0;
		while(j < len)
		{
			position(i,j) = src[j];
			++j;
		}
		while(j < width)
		{
			position(i, j) = ' ';
			++j;
		}
	}
}

Picture::Picture(const Picture& p):
	height(p.height), width(p.width),
	data(new char[p.height * p.width])
{
	copyblock(0,0,p);
}

Picture::~Picture()
{
	delete []data;
}

Picture& Picture::operator=(const Picture& p)
{
	if(this != &p)
	{
		delete []data;
		init(p.height,p.width);
		copyblock(0,0,p);
	}
	return *this;
}

void Picture::copyblock(int row,int col,const Picture& p)
{
	for(int i =0; i < p.height; ++i)
	{
		for(int j =0; j < p.width; ++j)
			position(i+row, j+col) = p.position(i,j);
	}
}

void Picture::clear(int h1,int w1,int h2,int w2)
{
	for(int r = h1; r < h2; ++r)
		for(int c = w1; c < w2; ++c)
			position(r,c) = ' ';
}

Picture frame(const Picture& p)
{
	Picture r;
	r.init(p.height + 2, p.width + 2);
	for(int i = 1; i < r.height -1; ++i)
	{
		r.position(i,0) = '|';
		r.position(i, r.width - 1) = '|';
	}
	for(int j = 1; j < r.width - 1; ++j)
	{
		r.position(0, j) = '-';
		r.position(r.height - 1, j) = '-';
	}
	r.position(0, 0) = '+';
	r.position(0, r.width-1) = '+';
	r.position(r.height-1, 0)= '+';
	r.position(r.height-1,r.width-1)='+';
	r.copyblock(1,1,p);
	return r;
}

Picture operator&(const Picture& p, const Picture& q)
{
	Picture r;
	r.init(p.height + q.height, Picture::max(p.width ,q.width));
	r.clear(0,p.width,p.height,r.width);
	r.clear(p.height,q.width,r.height,r.width);	
	r.copyblock(0,0,p);
	r.copyblock(p.height,0,q);
	return r;
}

Picture operator|(const Picture& p, const Picture& q)
{
	Picture r;
	r.init(Picture::max(p.height,q.height),p.width + q.width);
	r.clear(p.height,0,r.height,q.width);
	r.clear(q.height,p.width,r.height,r.width);
	r.copyblock(0,0,p);
	r.copyblock(0,p.width,q);
	return r;
}