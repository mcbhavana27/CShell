shell: \
	main.o \
	printcmdline.o \
	echo.o \
	cd.o \
	history.o \
	ls.o \
	pinfo.o \
	bg.o \
	jobs.o \
	kjob.o \
	fg.o \
	bg_job.o \
	overkill.o \
	env.o \
	redirection.o \
	pipe.o
	gcc   -o shell $^

main.o: main.c shell.h
	gcc -c main.c
printcmdline.o: printcmdline.c shell.h
	gcc -c printcmdline.c
echo.o: echo.c shell.h
	gcc -c echo.c
cd.o: cd.c shell.h
	gcc -c cd.c
history.o: history.c shell.h
	gcc -c history.c
ls.o: ls.c shell.h
	gcc -c ls.c
pinfo.o: pinfo.c shell.h
	gcc -c pinfo.c
bg.o: bg.c shell.h
	gcc -c bg.c
jobs.o: jobs.c shell.h
	gcc -c jobs.c
kjob.o: kjob.c shell.h
	gcc -c kjob.c
fg.o : fg.c shell.h
	gcc -c fg.c
bg_job.o : bg_job.c shell.h
	gcc -c bg_job.c
overkill.o : overkill.c shell.h
	gcc -c overkill.c
env.o : env.c shell.h
	gcc -c env.c
redirection.o : redirection.c shell.h
	gcc -c redirection.c
pipe.o : pipe.c shell.h
	gcc -c pipe.c
clean:
	rm  -f *.o shell

