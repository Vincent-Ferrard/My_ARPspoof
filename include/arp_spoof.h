/*
** EPITECH PROJECT, 2019
** arp_spoof.h
** File description:
** arp_spoof.h
*/

#pragma once

#ifndef ARP_SPOOF_H
#define  ARP_SPOOF_H

#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "struct.h"
#include "init.h"
#include "parameters.h"
#include "packet.h"
#include "transfer.h"

void print_broadcast(const data_t);

void print_spoof(const data_t);

void print_mac_address_victim(arp_packet_t, data_t *);
void get_mac_victim(int, struct ifreq, struct sockaddr_ll, data_t *);
void send_spoof_pack(int, unsigned char *, struct sockaddr_ll, data_t);
void spoof_arp_packet(int, struct ifreq, struct sockaddr_ll, data_t);
void arp_spoofing(data_t);

#endif
