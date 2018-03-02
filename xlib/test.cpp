#include <X11/Xlib.h>
#include <unistd.h>

int main()
{
	Display *d = XOpenDisplay(0);

	if (d)
	{
		Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 400, 
				200, 0, CopyFromParent, CopyFromParent, 
				CopyFromParent, 0, 0);
		XMapWindow(d, w);
		XFlush(d);

		sleep(5);
	}
	return 0;
}
