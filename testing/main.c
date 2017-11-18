#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int fd, fd1, fd2, to_check, check_origin;
	char *str;
	int res = 0;
    char a[32000];
    char b[32000];
    int ret;
    ft_putstr("buff_size: ");
    ft_putnbr(BUFF_SIZE);
    ft_putendl("");
    if (ac == 1)
    {
        res = get_next_line(0, &str);
        ft_putstr("res = ");
        ft_putnbr(res);
        ft_putendl("");
        ft_putendl(str);
    }
    if (ac == 2)
    {
        if ((to_check = open("file", O_TRUNC | O_WRONLY | O_CREAT, 0777)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open(av[1], O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }

        ret = get_next_line(check_origin, &str);
        ft_putnbr(ret);
        ft_putstr_fd(str, to_check);

        close(to_check);
        close(check_origin);
        if ((to_check = open("file", O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open(av[1], O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }

        ret = read(check_origin, a, 100);
        a[ret] = '\0';
        ret = read(to_check, b, 100);
        b[ret] = '\0';

        /* if (strcmp(a, b) == 0)
             ft_putendl("OK!");
         else
             ft_putendl("ERROR!");
         */
        /* int i = 0;
         while (i < 30002){
             res = a[i] - b[i];
             if (res != 0)
                 printf("char# = %d, r = %d\n", i, res);
             i++;
          }*/
        int i = 0;
        while (i < 100) {
            res = a[i] - b[i];
            if (res != 0)
                printf("char1 = %c, char2 = %c, i = %d\n", a[i], b[i], i);
            i++;
        }
        printf("end\n");
        close(to_check);
        close(check_origin);
    }
    if (ac == 3) {

        if ((to_check = open(av[1], O_TRUNC | O_WRONLY | O_CREAT, 0777)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open(av[2], O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }

        ret = get_next_line(check_origin, &str);
        ft_putnbr(ret);
        ft_putstr_fd(str, to_check);

        close(to_check);
        close(check_origin);
        if ((to_check = open(av[1], O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open(av[2], O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }

        ret = read(check_origin, a, 32000);
        a[ret] = '\0';
        ret = read(to_check, b, 32000);
        b[ret] = '\0';

       /* if (strcmp(a, b) == 0)
            ft_putendl("OK!");
        else
            ft_putendl("ERROR!");
        */
       /* int i = 0;
        while (i < 30002){
            res = a[i] - b[i];
            if (res != 0)
                printf("char# = %d, r = %d\n", i, res);
            i++;
         }*/
        int i = 0;
        while (i < 30002) {
            res = a[i] - b[i];
            if (res != 0)
                printf("char1 = %c, char2 = %c, i = %d\n", a[i], b[i], i);
            i++;
        }
        printf("end\n");
        close(to_check);
        close(check_origin);
    }
	if (ac == 5)
	{
		fd = open(av[1], O_RDONLY);
		fd1 = open(av[2], O_RDONLY);
        fd2 = open(av[3], O_RDONLY);

        if((to_check = open("test_to_check", O_TRUNC | O_WRONLY | O_CREAT, 0777)) < 0)
        {
            ft_putendl("error in open");
            return (1);
        }


        ft_putendl_fd("", to_check);
		ft_putendl_fd("1_call:", to_check);
		ft_putendl_fd("file1 | out1:", to_check);
		res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
		ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
		ft_putendl_fd("2_call:", to_check);
		ft_putendl_fd("file2 | out2:", to_check);
		res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
		ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
		ft_putendl_fd("3_call:", to_check);
        ft_putendl_fd("file1 | out3:", to_check);
		res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
		ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
		ft_putendl_fd("4_call:", to_check);
		ft_putendl_fd("file2 | out4:", to_check);
		res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
		ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("5_call:", to_check);
        ft_putendl_fd("file3 | out5:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("6_call:", to_check);
        ft_putendl_fd("file3 | out6:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("7_call:", to_check);
        ft_putendl_fd("file3 | out7:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("8_call:", to_check);
        ft_putendl_fd("file wrong | out8:", to_check);
        res = get_next_line(10, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("9_call:", to_check);
        ft_putendl_fd("file1 | out9:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("10_call:", to_check);
        ft_putendl_fd("file1 (LF) | out10:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("11_call:", to_check);
        ft_putendl_fd("file2(LF) | out11:", to_check);
        res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("12_call:", to_check);
        ft_putendl_fd("file1(last) | out12:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("13_call:", to_check);
        ft_putendl_fd("file2(last) | out13:", to_check);
        res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("14_call:", to_check);
        ft_putendl_fd("file1(nothing) | out14:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("15_call:", to_check);
        ft_putendl_fd("file2(line feed) | out15:", to_check);
        res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("16_call:", to_check);
        ft_putendl_fd("file3 | out16:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("17_call:", to_check);
        ft_putendl_fd("file3 | out17:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("18_call:", to_check);
        ft_putendl_fd("file3 | out18:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("19_call:", to_check);
        ft_putendl_fd("file3 | out19:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("20_call:", to_check);
        ft_putendl_fd("file3 | out20:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("21_call:", to_check);
        ft_putendl_fd("file3 | out21:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("22_call:", to_check);
        ft_putendl_fd("file3 | out22:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("23_call:", to_check);
        ft_putendl_fd("file3 (line feed) | out23:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("24_call:", to_check);
        ft_putendl_fd("file3 (line feed) | out24:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("25_call:", to_check);
        ft_putendl_fd("file3 (last) | out25:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("26_call:", to_check);
        ft_putendl_fd("file1 over | out26:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("27_call:", to_check);
        ft_putendl_fd("file2 (line feed)) | out27:", to_check);
        res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("28_call:", to_check);
        ft_putendl_fd("file3 over2 | out28:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);


        close(fd);
        close(fd1);
        close(fd2);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("29_call:", to_check);
        ft_putendl_fd("file1 closed | out29:", to_check);
        res = get_next_line(fd, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("30_call:", to_check);
        ft_putendl_fd("file2 closed | out30:", to_check);
        res = get_next_line(fd1, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        ft_putendl_fd("", to_check);
        ft_putendl_fd("31_call:", to_check);
        ft_putendl_fd("file3 closed | out31:", to_check);
        res = get_next_line(fd2, &str);
        ft_putstr_fd("res = ", to_check);
        ft_putnbr_fd(res, to_check);
        ft_putendl_fd("", to_check);
        ft_putendl_fd(str, to_check);

        close(to_check);

        if ((to_check = open("test_to_check", O_RDONLY)) < 0)
        {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open("check_origin", O_RDONLY)) < 0)
        {
            ft_putendl("error in open");
            return (1);
        }
        ret = read(to_check, a, 20000);
        a[ret] = '\0';
        ret = read(check_origin, b, 20000);
        b[ret] = '\0';

        if (strcmp(a, b) == 0)
            ft_putendl("OK!");
        else
            ft_putendl("ERROR!");

        ft_putendl(">>>>>>>>>start check main output");
        int i = 0;
        while (i < 1600){
            res = a[i] - b[i];
            if (res != 0)
                printf("char1 = %c, char2 = %c, i = %d\n", a[i], b[i], i);
            i++;
        }
        ft_putendl(">>>>>>>>>end check main output");
        close(to_check);
        close(check_origin);
        if ((to_check = open("test_bigfat", O_TRUNC | O_WRONLY | O_CREAT, 0777)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open("one_big_fat_line", O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }

        ret = get_next_line(check_origin, &str);
        ft_putstr("ret = ");
        ft_putnbr(ret);
        ft_putendl("");
        ft_putstr_fd(str, to_check);

        close(to_check);
        close(check_origin);
        if ((to_check = open("test_bigfat", O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        if ((check_origin = open("one_big_fat_line", O_RDONLY)) < 0) {
            ft_putendl("error in open");
            return (1);
        }
        ft_putendl(">>>>>>>>>start check main big file");
        ret = read(check_origin, a, 32000);
        a[ret] = '\0';
        ret = read(to_check, b, 32000);
        b[ret] = '\0';
        ft_putendl(">>>>>>>>>end check main big file");
        /* if (strcmp(a, b) == 0)
             ft_putendl("OK!");
         else
             ft_putendl("ERROR!");
         */
        /* int i = 0;
         while (i < 30002){
             res = a[i] - b[i];
             if (res != 0)
                 printf("char# = %d, r = %d\n", i, res);
             i++;
          }*/
        i = 0;
        while (i < 30002) {
            res = a[i] - b[i];
            if (res != 0)
                printf("char1 = %c, char2 = %c, i = %d\n", a[i], b[i], i);
            i++;
        }
        printf("end\n");
        close(to_check);
        close(check_origin);

	}
	/*TEST STRUCT*/
	/*addfile(3, &a, &files);
	print_files(files);
	ft_putendl("\nnext try>>>>>>.");
	addfile(4, &b, &files);
	print_files(files);
	ft_putendl("\n22222next try>>>>>>");
	addfile(5, &c, &files);
	print_files(files);*/
	return (0);
}
