/***************************************************************************//**
    @file   echod.c

    @brief  A daemon implementing the Echo Protocol specified in RFC 862
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DNAME   "echod"

/*******************************************************************************
    usage
*//**
    @brief  Displays usage statement then exits
*******************************************************************************/
void
usage(void)
{
    fprintf(stderr, "usage: %s [-h]\n", DNAME);
    fprintf(stderr, "  -h\tDisplay this help menu\n");
    exit(1);
}


/*******************************************************************************
    parse_args
*//**
    @brief  Parses command-line arguments
    @param  argc    Count of command-line arguments
    @param  *argv[] Command-line argument vector

    @note   Calls exit() on failure
*******************************************************************************/
void
parse_args(int argc, char *argv[])
{
    int i = 0;

    if (!argv)
    {
        exit(-1);
    }

    for (i = 1; i < argc; i++)
    {
        if (0 == (strcmp("-h", argv[i])))
        {
            usage();
        }
        else
        {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            usage();
        }
    }
}


/*******************************************************************************
    main
*//**
    @brief  Entry point for the daemon
    @param  argc    Count of command-line arguments
    @param  *argv[] Command-line argument vector

    @return Error code
    @retval 0   Success
*******************************************************************************/
int
main(int argc, char *argv[])
{
    parse_args(argc, argv);
    printf("Hello, World!\n");
    return 0;
}

