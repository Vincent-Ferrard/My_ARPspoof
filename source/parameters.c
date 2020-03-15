/*
** EPITECH PROJECT, 2018
** parameters.c
** File description:
** parameters.c
*/

#include "arp_spoof.h"

void get_ip(unsigned char *n_ip, const char *ip)
{
    int t[4] = {-1, -1, -1, -1};

    if (!ip)
        exit(84);
    sscanf(ip, "%d.%d.%d.%d", &t[0], &t[1], &t[2], &t[3]);
    for (int i = 0; i < 4; i++)
        n_ip[i] = (unsigned char) t[i];
}

void get_mac_address(unsigned char *n_mac, const char *mac)
{
    int t[6] = {-1, -1, -1, -1, -1, -1};

    if (!mac)
        exit(84);
    sscanf(mac, "%x:%x:%x:%x:%x:%x", &t[0], &t[1], &t[2], &t[3], &t[4], &t[5]);
    for (int i = 0; i < 6; i++)
        n_mac[i] = (unsigned char) t[i];
}

int good_addr(const unsigned char *value, int max)
{
    for (int i = 0; i < max; i++)
        if (value[i] == (unsigned char) 0xff)
            return (0);
    return (1);
}

void get_flags(data_t *data, char **av)
{
    for (int i = 1; av[i]; i++) {
        if (strcmp(av[i], "-i") == 0) {
            av[i + 1] ? : exit(84);
            data->infra = strdup(av[i + 1]);
            i++;
        }
        if (strcmp(av[i], "-t") == 0) {
            get_ip(data->send_ip, av[i + 1]);
            get_ip(data->dest_ip, av[i + 2]);
            i += 2;
        }
        if (strcmp(av[i], "--printBroadcast") == 0)
            data->printBroadcast = 1;
        if (strcmp(av[i], "--printSpoof") == 0) {
            data->printSpoof = 1;
            get_mac_address(data->dest_mac, av[i + 1]);
            i++;
        }
    }
}

data_t get_parameters(int ac, char **av)
{
    int a = -1;
    data_t d = {{a, a, a, a}, {a, a, a, a}, NULL, 0, 0, {a, a, a, a, a, a}};

    if (ac < 4)
        exit(84);
    get_flags(&d, av);
    if (!d.infra && !good_addr(d.send_ip, 4) && !good_addr(d.dest_ip, 4))
        for (int i = 1; av[i]; i++) {
            if (i == 1)
                get_ip(d.send_ip, av[i]);
            if (i == 2)
                get_ip(d.dest_ip, av[i]);
            if (i == 3)
                d.infra = strdup(av[i]);
        }
    if (!d.infra || !good_addr(d.send_ip, 4) || !good_addr(d.dest_ip, 4))
        exit(84);
    else if (d.printBroadcast == 1 && d.printSpoof == 1)
        exit(84);
    return (d);
}
