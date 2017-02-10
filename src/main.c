/*
 * main.c
 *
 *  Created on: Feb 7, 2017
 *      Author: kieutq
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <getopt.h>

#define ACTION_ENCRYPT 1
#define ACTION_DECRYPT 2

int action = 0;
char file_name[256];

int opt_process(int argc, char * argv[])
{
	static struct option long_opt[] =
	{
			{"encrypt", required_argument, &action, ACTION_ENCRYPT},
			{"decrypt", required_argument, &action, ACTION_DECRYPT},
			{0, 0, 0, 0}
	};
	int opt_index = 0;

	int res = 0;
	do
	{
		res = getopt_long(argc,  argv,  "e:d:", &long_opt, &opt_index);
		switch(res)
		{
		case 0:
			printf("Action: %s file %s\r\n", long_opt[opt_index].name, optarg);
			break;
		case 'e':
			printf("Encrypt file %s\r\n", optarg);
			memset(file_name, 0, 256);
			strcpy(file_name, optarg);
			action = ACTION_ENCRYPT;
			break;
		case 'd':
			printf("Decrypt file %s\r\n", optarg);
			memset(file_name, 0, 256);
			strcpy(file_name, optarg);
			action = ACTION_DECRYPT;
			break;
		case -1:
			break;
		default:
			break;
		}
	}
	while(res != -1);
}


int main(int argc, char * argv[])
{
	opt_process(argc, argv);

	switch(action)
	{
	case ACTION_ENCRYPT:
		puts("Encrypted\r\n");
		break;
	case ACTION_DECRYPT:
		puts("Decrypted\r\n");
		break;
	default:
		puts("Nothing TODO\r\n");
		break;
	}

	return 0;
}
