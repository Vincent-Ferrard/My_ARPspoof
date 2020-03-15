/*
** EPITECH PROJECT, 2018
** transfer.c
** File description:
** transfer.c
*/

#include "arp_spoof.h"

void send_packet(int sockfd, unsigned char *b, struct sockaddr_ll *sockaddr)
{
    size_t len = sizeof(struct ethhdr) + sizeof(arp_header_t);
    struct sockaddr *s = (struct sockaddr *) sockaddr;

    if (sendto(sockfd, b, len, 0, s, sizeof(*sockaddr)) == -1) {
        perror("error sendto()");
        exit(84);
    }
}

void recv_packet(int sockfd, unsigned char *buffer)
{
    bzero(buffer, MSG_MAX_LENGTH);
    if (recvfrom(sockfd, buffer, MSG_MAX_LENGTH, 0, NULL, NULL) == -1) {
        perror("error recvfrom()");
        exit(84);
    }
}
