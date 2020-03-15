/*
** EPITECH PROJECT, 2019
** arp_main
** File description:
** arp
*/

#include "arp_spoof.h"

int main(int ac, char **av)
{
    data_t data = get_parameters(ac, av);

    if (data.printBroadcast == 1)
        print_broadcast(data);
    else if (data.printSpoof == 1)
        print_spoof(data);
    else
        arp_spoofing(data);
    if (data.infra)
        free(data.infra);
    return (0);
}
