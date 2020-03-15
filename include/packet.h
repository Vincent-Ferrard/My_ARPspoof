/*
** EPITECH PROJECT, 2018
** packet.h
** File description:
** packet.h
*/

#pragma once

#ifndef PACKET_H_
#define PACKET_H_

void generate_ethhdr(struct ethhdr *, struct ifreq);
void generate_arphdr(arp_header_t *, struct ifreq, const data_t);
void generate_ethhdr_spoof(struct ethhdr *, struct ifreq, data_t);
void generate_arphdr_spoof(arp_header_t *, struct ifreq, const data_t);
arp_packet_t init_arp_packet(unsigned char *);

#endif
