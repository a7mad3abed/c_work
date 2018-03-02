#include <gtk/gtk.h>
#ifndef _my_app_window_h_
#define _my_app_window_h_

G_BEGIN_DECLS

#define BOOKS_APP (books_app_get_type())
G_DECLARE_FINAL_TYPE(BOOKS_APP, books_app, BOOKS, APP, GtkApplication)

BOOKS_APP *	books_app_new(void);

G_END_DECLS

#endif

