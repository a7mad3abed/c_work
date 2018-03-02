/* A program to test c with sqlite. That was my plan before i start to
write my own program to sort and manage my read books.

written by Ahmed Ibrahim am 16.01.2018
*/

#include <stdio.h>
#include <sqlite3.h>

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	char *err_msg = 0;
	const char *next = 0;
	int rc;

	rc = sqlite3_open("test.db", &db);

	if(rc)
	{
		fprintf(stderr, "Cant't open database: %s\n", sqlite3_errmsg(db));
		return(0);
	}

	char *sql = "drop table if exists auto ;""create table auto(Id integer primary key AUTOINCREMENT,  Name TEXT, Price INT);"
		"insert into auto(Name, Price) values('Renaut', 2145);"
		"insert into auto(Name, Price) values('Renaut', 2145);"
		"insert into auto(Name, Price) values('Seat', 2000);"
		"insert into auto(Name, Price) values('Peugot', 3600);"
		"insert into auto(Name, Price) values('Merced', 6000);"
		"insert into auto(Name, Price) values('Opel', 22100);"
		"insert into auto(Name, Price) values('BMW', 7600);"
		"insert into auto(Name, Price) values('Nissan', 5400);"
		"insert into auto(Name, Price) values('Lada', 200);"
		"insert into auto(Name, Price) values('Toyota', 8800);"
		"insert into auto(Name, Price) values('Mazda', 11100);"
		"insert into auto(Name, Price) values('Lexus', 88800);"
		"insert into auto(Name, Price) values('Camry', 99900);"
		"insert into auto(Name, Price) values('Ford', 4400);"
		"insert into auto(Name, Price) values('VW', 3400);";

	/*
	 that might look like easy. But that was very hard to find.
	 With this while loop can multiple sql statements successively passed to sqlite3_step.
	 The trick was that we need to set sql to the pointer next every time.
	 We needed here too a cast, because sql is not of the type const.
	 */
	/******************************
	 * ***************************
	 *******************************
	 */
	while(sqlite3_complete(sql))
	{
		rc = sqlite3_prepare_v2(db, sql, -1, &res, &next);
		rc = sqlite3_step(res);
		sql = (char *)next;
	}

	/**********************************************
	 **********************************************
	 **********************************************
	 **********************************************/

	// that is it when it is done maually without a loop


	/*rc = sqlite3_prepare_v2(db, sql, -1, &res, &next);
	rc = sqlite3_step(res);
	sql = (char *)next;
	rc = sqlite3_prepare_v2(db, sql, -1, &res, &next);
	rc = sqlite3_step(res);
	sql = (char *)next;
	rc = sqlite3_prepare_v2(db, sql, -1, &res, &next);
	rc = sqlite3_step(res);
	sql = (char *)next;
	rc = sqlite3_prepare_v2(db, sql, -1, &res, &next);
	rc = sqlite3_step(res);
	*/


	if(rc == SQLITE_DONE)
	{
		printf("Done\n");
	}

/* that is another way to do the job. That is much easier.

rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "error: %s\n", err_msg);
	}
	*/






	sqlite3_finalize(res);

	sqlite3_close(db);
}
