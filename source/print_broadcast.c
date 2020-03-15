/*
** EPITECH PROJECT, 2018
** printBroadcast.c
** File description:
** printBroadcast.c
*/

#include "arp_spoof.h"

void print_broadcast(const data_t data)
{
    int sockfd = create_socket(AF_INET, SOCK_DGRAM, 0);
    struct ifreq ifr;
    unsigned char buffer[MSG_MAX_LENGTH];
    arp_packet_t packet = init_arp_packet(buffer);

    init_ifreq(&ifr, sockfd, data.infra);

    generate_ethhdr(packet.eth, ifr);
    generate_arphdr(packet.arp, ifr, data);

    for (int i = 0; i < 42; i++) {
        if (i > 0)
            printf(" ");
        printf("%02x", buffer[i]);
    }
    printf("\n");
    close(sockfd);
}
