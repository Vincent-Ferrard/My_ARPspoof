/*
** EPITECH PROJECT, 2018
** packet.c
** File description:
** packet.c
*/

#include "arp_spoof.h"

void generate_ethhdr(struct ethhdr *eth, struct ifreq ifr)
{
    for (int i = 0; i < 6; i++) {
        eth->h_source[i] = (unsigned char) ifr.ifr_hwaddr.sa_data[i];
        eth->h_dest[i] = (unsigned char) 0xff;
    }
    eth->h_proto = htons(ETH_P_ARP);
}

void generate_arphdr(arp_header_t *arp, struct ifreq ifr, const data_t data)
{
    arp->ar_hrd = htons(1);
    arp->ar_pro = htons(ETH_P_IP);
    arp->ar_hln = 6;
    arp->ar_pln = 4;
    arp->ar_op = htons(0x01);
    for (int i = 0; i < 6; i++) {
        arp->ar_sha[i] = (unsigned char) ifr.ifr_hwaddr.sa_data[i];
        arp->ar_tha[i] = (unsigned char) 0xff;
    }
    for (int i = 0; i < 4; i++) {
        arp->ar_sip[i] = data.send_ip[i];
        arp->ar_tip[i] = data.dest_ip[i];
    }
}

void generate_ethhdr_spoof(struct ethhdr *eth, struct ifreq ifr, data_t data)
{
    for (int i = 0; i < 6; i++) {
        eth->h_source[i] = ifr.ifr_hwaddr.sa_data[i];
        eth->h_dest[i] = data.dest_mac[i];
    }
    eth->h_proto = htons(ETH_P_ARP);
}

void generate_arphdr_spoof(arp_header_t *arp, struct ifreq ifr, const data_t d)
{
    arp->ar_hrd = htons(1);
    arp->ar_pro = htons(ETH_P_IP);
    arp->ar_hln = 6;
    arp->ar_pln = 4;
    arp->ar_op = htons(0x02);
    for (int i = 0; i < 6; i++) {
        arp->ar_sha[i] = (unsigned char) ifr.ifr_hwaddr.sa_data[i];
        arp->ar_tha[i] = d.dest_mac[i];
    }
    for (int i = 0; i < 4; i++) {
        arp->ar_sip[i] = d.send_ip[i];
        arp->ar_tip[i] = d.dest_ip[i];
    }
}

arp_packet_t init_arp_packet(unsigned char *buffer)
{
    arp_packet_t packet;

    bzero(buffer, MSG_MAX_LENGTH);
    packet.eth = (struct ethhdr *) buffer;
    packet.arp = (arp_header_t *) (buffer + sizeof(struct ethhdr));
    return (packet);
}
