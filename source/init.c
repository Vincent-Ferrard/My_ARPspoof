/*
** EPITECH PROJECT, 2018
** init.c
** File description:
** init.c
*/

#include "arp_spoof.h"

int create_socket(int domain, int type, int protocol)
{
    int sockfd = socket(domain, type, protocol);

    if (sockfd < 0) {
        perror("error socket");
        exit(84);
    }
    return (sockfd);
}

int init_ifreq(struct ifreq *ifr, int sockfd, const char *infra)
{
    int index;

    strcpy(ifr->ifr_name, infra);
    if (ioctl(sockfd, SIOCGIFINDEX, ifr) == -1) {
        perror("SIOCGIFINDEX");
        exit(84);
    }
    index = ifr->ifr_ifindex;
    if (ioctl(sockfd, SIOCGIFHWADDR, ifr) == -1) {
        perror("SIOCGIFHWADDR");
        exit(84);
    }
    return (index);
}

struct sockaddr_ll init_sockaddr_ll(int index, struct ifreq ifr)
{
    struct sockaddr_ll sockaddr;

    sockaddr.sll_family = AF_PACKET;
    sockaddr.sll_protocol = htons(ETH_P_ARP);
    sockaddr.sll_ifindex = index;
    sockaddr.sll_hatype = htons(ARPHRD_ETHER);
    sockaddr.sll_pkttype = PACKET_BROADCAST;
    sockaddr.sll_halen = 0x06;
    sockaddr.sll_addr[6] = 0x00;
    sockaddr.sll_addr[7] = 0x00;
    for (int i = 0; i < 6; i++)
        sockaddr.sll_addr[i] = (unsigned char) ifr.ifr_hwaddr.sa_data[i];
    return (sockaddr);
}
