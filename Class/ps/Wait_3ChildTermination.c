#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
main()
{
	if (fork() == 0)
	{
		int r;
		srand(getpid());

		r = rand() % 10 + 1;
		printf("in c1 r=%d\n", r);
		sleep(r);
		exit(1);
	}
	else
	{
		if (fork() == 0)
		{
			int r;
			srand(getpid());
			r = rand() % 10 + 1;
			printf("in c2 r=%d\n", r);
			sleep(r);
			exit(2);
		}
		else
		{
			if (fork() == 0)
			{
				int r;
				srand(getpid());
				r = rand() % 10 + 1;
				printf("in c3 =%d\n", r);
				sleep(r);
				exit(3);
			}
			else
			{
				int s;
				while (wait(&s) != -1)
				{
					s = s >> 8;
					if (s == 1)
						printf("c1\n");
					else if (s == 2)
						printf("c2\n");
					else if (s == 3)
						printf("c3\n");
				}
			}
		}
	}
}
