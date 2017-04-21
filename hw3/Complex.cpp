#include "Complex.h"
#include <cmath>

Complex::Complex( const double re, const double im)
	:real(re),imag(im){};	
Complex::Complex( const Complex& c )
	:real( c.real ), imag( c.imag ){};	
Complex& Complex::operator=( const Complex& c )
{
	this->real = c.real;
	this->imag = c.imag;
	return *this;
}

Complex Complex::Polar( const double leng, const double arg )
{
	this->real = leng*cos( arg );
	this->imag = leng*sin( arg );
	return *this;
}

double Complex::Real()
{
	return this->real;
}
double Complex::Imag()
{
	return this->imag;
}
double Complex::Norm()
{
	return real*real + imag*imag;
}
double Complex::Abs()
{
	return sqrt( Norm() );
}
double Complex::Arg()
{
	return atan( imag/real );
}
Complex Complex::operator++()
{
	this->real++;
	return *this;
}
Complex Complex::operator++( int )
{
	Complex r = *this;
	this->real++;
	return r;
}
Complex Complex::operator--()
{
	this->real--;
	return *this;
}
Complex Complex::operator--( int )
{
	Complex r = *this;
	this->real--;
	return r;
}

Complex::~Complex(){};

Complex Polar( const double leng, const double arg )
{
	return Complex( leng*cos( arg ), leng*sin( arg ) );
}
double Norm( const Complex& x )
{
	return x.real*x.real + x.imag*x.imag;
}
double Abs( const Complex& x )
{
	return sqrt( Norm( x ) );
}
double Arg( const Complex& x )
{
	return atan( x.imag/x.real );
}
Complex operator+( const Complex& x, const Complex& y )
{
	return Complex( x.real+y.real, x.imag+y.imag );
}
Complex operator-( const Complex& x, const Complex& y )
{
	return Complex( x.real-y.real, x.imag-y.imag );
}
Complex operator*( const Complex& x, const Complex& y )
{
	return Complex( x.real*y.real-x.imag*y.imag, x.real*y.imag + x.imag*y.real );
}
Complex operator/( const Complex& x, const Complex& y )
{
	double denominator = y.real*y.real + y.imag*y.imag,
			real = (x.real*y.real + x.imag*y.imag)/denominator,
			imag = (x.imag*y.real - x.real*y.imag)/denominator;	
	return Complex( real, imag );
}
Complex operator+=( Complex& x, const Complex& y )
{
	x = x+y;
	return x;
}
Complex operator-=( Complex& x, const Complex& y )
{
	x = x-y;
	return x;
}
Complex operator*=( Complex& x, const Complex& y )
{
	x = x*y;
	return x;
}
Complex operator/=( Complex& x, const Complex& y )
{
	x = x/y;
	return x;
}
bool operator==( const Complex& x, const Complex& y )
{
	return x.real == y.real && x.imag == y.imag;
}
bool operator!=( const Complex& x, const Complex& y )
{
	return !( x == y );
}

ostream& operator<<( ostream& o, const Complex& x )
{
	o << '(' << x.real << ',' << x.imag << ')' ;
	return o;
}
