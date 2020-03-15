/*
** EPITECH PROJECT, 2018
** struct.h
** File description:
** struct.h
*/

#pragma once

#ifndef STRUCT_H_
#define STRUCT_H_

#define MSG_MAX_LENGTH 60

#include <linux/if_arp.h>
#include <linux/if_ether.h>

typedef struct arp_header_s {
    unsigned short ar_hrd;
    unsigned short ar_pro;
    unsigned char ar_hln;
    unsigned char ar_pln;
    unsigned short ar_op;
    unsigned char ar_sha[6];
    unsigned char ar_sip[4];
    unsigned char ar_tha[6];
    unsigned char ar_tip[4];
} arp_header_t;

typedef struct arp_packet_s {
    struct ethhdr *eth;
    arp_header_t *arp;
} arp_packet_t;

typedef struct data_s {
    unsigned char send_ip[4];
    unsigned char dest_ip[4];
    char *infra;
    int printBroadcast;
    int printSpoof;
    unsigned char dest_mac[6];
} data_t;

#endif
