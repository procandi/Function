#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


bool looping=1;
char *displayName=NULL;
Display *hDsp;
Window hWin;
int hScreenNum;
GC hGC;
Colormap hCmap;
char szClassName[]="sui qow ix sya onr d flp sow up nrr ay d";
XFontStruct *fontinfo;
Font newFont;
Atom wm_delwindow=0;
Atom wm_protocols=0;

bool InitApp();
bool InitInstance();
bool WndProc(XEvent);
int main(int argc, char **argv){
	XEvent event;
	
	if(!InitApp())
		return false;
	if(!InitInstance())
		return false;
	
  	while(!XNextEvent(hDsp,&event)){
		if(WndProc(event)){
			XUnloadFont(hDsp, newFont);
		  	XDestroyWindow(hDsp, hWin);
		  	XFlush(hDsp);
		  	XCloseDisplay(hDsp);
			break;
		}
	}
  	
  	return 0;
}
bool InitApp(){
	if((hDsp=XOpenDisplay(displayName))==NULL)
		return false;
	
	hScreenNum=DefaultScreen(hDsp);
	hGC=DefaultGC(hDsp,hScreenNum);
	hCmap=DefaultColormap(hDsp,hScreenNum);
	
	return true;
}
bool InitInstance(){
	hWin=XCreateSimpleWindow(
  		hDsp,
		RootWindow(hDsp,hScreenNum),
		0,0,140,40,0,
		BlackPixel(hDsp,hScreenNum),
		WhitePixel(hDsp,hScreenNum)
  	);
  	
  	XSetForeground(hDsp,hGC,0xFF0000);
	newFont=XLoadFont(hDsp, 
		"-adobe-helvetica-medium-r-normal--14"
		"-*-*-*-*-*-iso8859-1"
  	);
  	XSetFont(hDsp,hGC,newFont);
  	fontinfo=XQueryFont(hDsp,XGContextFromGC(hGC));

  	XStoreName(hDsp,hWin,szClassName);
  	XSelectInput(hDsp,hWin,ExposureMask | ButtonPressMask);
	XMapWindow(hDsp,hWin);
	
	wm_protocols=XInternAtom(hDsp,"WM_PROTOCOLS",0);
  	wm_delwindow=XInternAtom(hDsp,"WM_DELETE_WINDOW",0);
  	XSetWMProtocols(hDsp,hWin,&wm_delwindow,1);
  	
  	return true;
}
bool WndProc(XEvent event){
	switch(event.type){
  	case ButtonPress:
    	return true;
    	break;
  	case ClientMessage:
		if((event.xclient.message_type==wm_protocols) && (event.xclient.format==32)){
      		Atom msg=event.xclient.data.l[0];
      		if(msg==wm_delwindow)
      			return true;
    	}
    	break;
	}
	
	return false;
}
