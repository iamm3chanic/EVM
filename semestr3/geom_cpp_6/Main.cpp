/* 
 * Main.cpp 
  6. Дано множество точек. Найти центр и радиус минимального круга, который содержит все эти точки.
 */
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Classes.h"

using namespace std;


void test1() {
   try {
    cout << "test1\n";
    CDot d1,d2,d3(5,7);
    double x,y;
    cout<<"Введите х, у: ";
    cin>>x>>y; 
    d1.SetDot(x,y);
    cout<<"d1: ";
    d1.ShowDot();
    cout<<"d2: ";
    d2.ShowDot();
    cout<<"d3: ";
    d3.ShowDot();
    
    d1=d2;
    cout<<"Теперь d1=d2\n ";
    d1.ShowDot();

    } catch(int err) {cout << "error=" <<err<<endl;}
    }
void test2() {    
   try {
    cout << "test2\n";
    CDot d(0,1);
    CCircle c1,c2,c3(5,7,2.0), c4(3,d);
    double x,y,r;
    cout<<"Введите х, у: ";
    cin>>x>>y; 
    cout<<"Введите r: ";
    cin>>r;
    c1.SetCircle(r,x,y);
    cout<<"c1: ";
    c1.ShowCircle();
    cout<<"c2: ";
    c2.ShowCircle();
    cout<<"c3: ";
    c3.ShowCircle();
    cout<<"c4: ";
    c4.ShowCircle();
    
    c1=c4;
    cout<<"Теперь c1=c4\n ";
    c1.ShowCircle();

    } catch(int err) {cout << "error=" <<err<<endl;}
    }
void test3() {    
    try {
    cout << "test3\n";
    CDot d(0,1),d1;
    CCircle c1,c2,c3(5,7,2.0), c4(3,d);
    //double x,y,r;
    cout<<"Ввод с1. ";
    cin>>c1;
    cout<<"c1: "<<c1;
    cout<<"Ввод d1. ";
    cin>>d1;
    cout<<"d1: "<<d1;
   
    cout<<"c3: "<<c3;
    cout<<"c4: "<<c4;

    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test4() {
    try {
    cout << "test4\n";
    CDot d(0,1),d1;
    CCircle c1,c2,c3(5,7,2), c4(3,d);
    //double x,y,r;
    cout<<"Ввод с1. ";
    cin>>c1;
    cout<<"c1: "<<c1;
    cout<<"Ввод d1. ";
    cin>>d1;
    cout<<"d1: "<<d1;
    if(IsInCircle(d1,c1)) cout<<"d1 лежит в c1!\n";
    else cout<<"d1 не лежит в c1!\n";
   
    cout<<"d: "<<d;
    cout<<"c3: "<<c3;
    if(IsInCircle(d,c3)) cout<<"d лежит в c3!\n";
    else cout<<"d не лежит в c3!\n";
    
    } catch(int err) {cout << "error=" <<err<<endl;}
    }
void test5() {
    try {
    cout << "test5\n";
    CDot d(0,1),*d1;
    CCircle c1,c2,c3(5,7,2), c4(3,d);
    //double x,y,r;
    int n=NReader();
    d1 = new CDot[n];
    cout<<"Ввод d1. ";
    for(int i=0;i<n;i++)
    {cin>>d1[i];}
    //cout<<"d1: "<<d1[i];
    BuildCircle(d1,n);
    
    delete [] d1;
    } catch(int err) {cout << "error=" <<err<<endl;}
    }
void test6() {
    try {
    cout << "test6\n";
    CDot d1(0,100),*d,d2(0,0),d3(200,200);
    //double x,y,r;
    //int n=NReader();
    d = new CDot[3];
    d[0]=d1;d[1]=d2;d[2]=d3;
    for(int i=0;i<3;i++){cout<<"d1: "<<d[i];}   
    BuildCircle(d,3);
    
    delete [] d;
    } catch(int err) {cout << "error=" <<err<<endl;}
    }
void test7() {
    try {
    cout << "test7\n";
     Display *disp;
 int ScrNum;
 GC prGC;
 XEvent Evnt;
 Window win;
 //int width=100; int height=100;
 int angle1=0;int angle2=360*64; 
 //int x=0,y=0;
 CDot d1(0,100),*d,d2(0,0),d3(100,200);
 CCircle c;
 
 if ( (disp = XOpenDisplay (NULL)) == NULL)
  {
    printf("\n====1");
    exit(1);
  }
 
 ScrNum = DefaultScreen( disp );
 win = XCreateSimpleWindow( disp, RootWindow( disp, ScrNum), 0, 0, 500, 500, 2, 
                                  BlackPixel(  disp, ScrNum), WhitePixel(  disp, ScrNum) );
 XSelectInput( disp, win, ExposureMask | KeyPressMask | ButtonPressMask);
 XMapWindow (disp,win);
 while( 1 )
  {
    XNextEvent( disp, &Evnt);
    switch (Evnt.type)
     {
      case Expose:
        if ( Evnt.xexpose.count!=0 ) break;
         
         d = new CDot[3];
         d[0]=d1;d[1]=d2;d[2]=d3;
         for(int i=0;i<3;i++){cout<<"d1: "<<d[i];}   
         c=BuildCircle1(d,3);   
         prGC = XCreateGC( disp, win, 0, NULL );
         XSetForeground( disp, prGC, BlackPixel(disp, 0) ); 
         XDrawLine(disp, win, prGC, 0, 250, 500, 250);
         XDrawLine(disp, win, prGC, 250, 0, 250, 500); //координатные линии
         XDrawPoint(disp, win, prGC, d1.GetX()+250, -d1.GetY()+250) ;
         XDrawPoint(disp, win, prGC, d2.GetX()+250, -d2.GetY()+250) ;
         XDrawPoint(disp, win, prGC, d3.GetX()+250, -d3.GetY()+250) ;   //точки   
         XDrawArc(disp, win, prGC, c.GetD().GetX()+250-c.GetR(), -c.GetD().GetY()+250-c.GetR(), 2*c.GetR(), 2*c.GetR(), angle1, angle2);  //собсно, круг
         //попытка сделать точки жирнее
         XDrawArc(disp, win, prGC, d1.GetX()+250-2, -d1.GetY()+250-2, 5, 5, angle1, angle2);
         XDrawArc(disp, win, prGC, d2.GetX()+250-2, -d2.GetY()+250-2, 5, 5, angle1, angle2);
         XDrawArc(disp, win, prGC, d3.GetX()+250-2, -d3.GetY()+250-2, 5, 5, angle1, angle2); 
         XFreeGC( disp, prGC );
         delete [] d;
         //n_call++;
         //sprintf(str,"Hello... %d",n_call);
       break;
      case KeyPress:
       goto fin; 
     }
  } 
fin:
 XCloseDisplay( disp ); 
    } catch(int err) {cout << "error=" <<err<<endl;}
}
void test8() {
    try {
    cout << "test8\n";
     Display *disp;
 int ScrNum;
 GC prGC;
 XEvent Evnt;
 Window win;
 //int width=100; int height=100;
 int angle1=0;int angle2=360*64; 
 //int x=0,y=0;
 CDot d1(0,100),*d,d2(0,0);
 CCircle c;
 
 if ( (disp = XOpenDisplay (NULL)) == NULL)
  {
    printf("\n====1");
    exit(1);
  }
 
 ScrNum = DefaultScreen( disp );
 win = XCreateSimpleWindow( disp, RootWindow( disp, ScrNum), 0, 0, 500, 500, 2, 
                                  BlackPixel(  disp, ScrNum), WhitePixel(  disp, ScrNum) );
 XSelectInput( disp, win, ExposureMask | KeyPressMask | ButtonPressMask);
 XMapWindow (disp,win);
 while( 1 )
  {
    XNextEvent( disp, &Evnt);
    switch (Evnt.type)
     {
      case Expose:
        if ( Evnt.xexpose.count!=0 ) break;
         
         d = new CDot[2];
         d[0]=d1;d[1]=d2;
         for(int i=0;i<2;i++){cout<<"d1: "<<d[i];}   
         c=BuildCircle1(d,2);   
         prGC = XCreateGC( disp, win, 0, NULL );
         XSetForeground( disp, prGC, BlackPixel(disp, 0) ); 
         XDrawLine(disp, win, prGC, 0, 250, 500, 250);
         XDrawLine(disp, win, prGC, 250, 0, 250, 500); //координатные линии
         XDrawPoint(disp, win, prGC, d1.GetX()+250, -d1.GetY()+250) ;
         XDrawPoint(disp, win, prGC, d2.GetX()+250, -d2.GetY()+250) ; //точки   
         XDrawArc(disp, win, prGC, c.GetD().GetX()+250-c.GetR(), -c.GetD().GetY()+250-c.GetR(), 2*c.GetR(), 2*c.GetR(), angle1, angle2);  //собсно, круг!
         //XDrawArc(display, d, gc, x, y, width, height, angle1, angle2);
         //попытка сделать точки жирнее
         XDrawArc(disp, win, prGC, d1.GetX()+250-2, -d1.GetY()+250-2, 5, 5, angle1, angle2);
         XDrawArc(disp, win, prGC, d2.GetX()+250-2, -d2.GetY()+250-2, 5, 5, angle1, angle2);
         XFreeGC( disp, prGC );
         delete [] d;
         //n_call++;
         //sprintf(str,"Hello... %d",n_call);
       break;
      case KeyPress:
       goto fin; 
     }
  } 
fin:
 XCloseDisplay( disp ); 
    } catch(int err) {cout << "error=" <<err<<endl;}
}

void test9() {
    try {
    cout << "test9\n";
     Display *disp;
 int ScrNum;
 GC prGC;
 XEvent Evnt;
 Window win;
 //int width=100; int height=100;
 int angle1=0;int angle2=360*64; 
 //int x=0,y=0;
 CDot d1(0,100),*d,d2(0,0),d3(100,190),d4(-170,100);
 CCircle c;
 
 if ( (disp = XOpenDisplay (NULL)) == NULL)
  {
    printf("\n====1");
    exit(1);
  }
 
 ScrNum = DefaultScreen( disp );
 win = XCreateSimpleWindow( disp, RootWindow( disp, ScrNum), 0, 0, 500, 500, 2, 
                                  BlackPixel(  disp, ScrNum), WhitePixel(  disp, ScrNum) );
 XSelectInput( disp, win, ExposureMask | KeyPressMask | ButtonPressMask);
 XMapWindow (disp,win);
 while( 1 )
  {
    XNextEvent( disp, &Evnt);
    switch (Evnt.type)
     {
      case Expose:
        if ( Evnt.xexpose.count!=0 ) break;
         
         d = new CDot[4];
         d[0]=d1;d[1]=d2;d[2]=d3;d[3]=d4;
         for(int i=0;i<4;i++){cout<<"d1: "<<d[i];}   
         c=BuildCircle1(d,4);   
         prGC = XCreateGC( disp, win, 0, NULL );
         XSetForeground( disp, prGC, BlackPixel(disp, 0) ); 
         XDrawLine(disp, win, prGC, 0, 250, 500, 250);
         XDrawLine(disp, win, prGC, 250, 0, 250, 500); //координатные линии
         XDrawPoint(disp, win, prGC, d1.GetX()+250, -d1.GetY()+250) ;
         XDrawPoint(disp, win, prGC, d2.GetX()+250, -d2.GetY()+250) ;
         XDrawPoint(disp, win, prGC, d3.GetX()+250, -d3.GetY()+250) ;   //точки  
         XDrawPoint(disp, win, prGC, d4.GetX()+250, -d4.GetY()+250) ; 
         XDrawArc(disp, win, prGC, c.GetD().GetX()+250-c.GetR(), -c.GetD().GetY()+250-c.GetR(), 2*c.GetR(), 2*c.GetR(), angle1, angle2);  //собсно, круг
         //попытка сделать точки жирнее
         XDrawArc(disp, win, prGC, d1.GetX()+250-2, -d1.GetY()+250-2, 5, 5, angle1, angle2);
         XDrawArc(disp, win, prGC, d2.GetX()+250-2, -d2.GetY()+250-2, 5, 5, angle1, angle2);
         XDrawArc(disp, win, prGC, d3.GetX()+250-2, -d3.GetY()+250-2, 5, 5, angle1, angle2); 
         XDrawArc(disp, win, prGC, d4.GetX()+250-2, -d4.GetY()+250-2, 5, 5, angle1, angle2); 
         XFreeGC( disp, prGC );
         delete [] d;
         //n_call++;
         //sprintf(str,"Hello... %d",n_call);
       break;
      case KeyPress:
       goto fin; 
     }
  } 
fin:
 XCloseDisplay( disp ); 
    } catch(int err) {cout << "error=" <<err<<endl;}
}

int main()
{
  test9();
    /*test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();*/
   
    return 0;
}
