#include <stdio.h>
#include <sqlite3.h>

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK )
	{
		printf("Cannot open database");
	}

	char *sql = "select * from auto;";

	rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
	if (rc != SQLITE_OK)
	{
		return (-1);
	}

	while ((rc = sqlite3_step(res)) == SQLITE_ROW) 
	{
		printf("%s\t%s\t\t%s\n", sqlite3_column_text(res, 0), sqlite3_column_text(res, 1), sqlite3_column_text(res, 2));
	}



	sqlite3_finalize(res);
			

	sqlite3_close(db);

}
