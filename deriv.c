#include "deriv.h"

struct _BooksApp
{
	GtkApplication parent_instance;
}

G_DEFINE_TYPE(BooksApp, booksapp, GTK_TYPE_APPLICATION)

static void 
booksapp_init(BooksApp *app)
{
