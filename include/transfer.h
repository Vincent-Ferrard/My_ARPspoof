/*
** EPITECH PROJECT, 2018
** transfer.h
** File description:
** transfer.h
*/

#pragma once

#ifndef TRANSFER_H_
#define TRANSFER_H_

void send_packet(int, unsigned char *, struct sockaddr_ll *);
void recv_packet(int, unsigned char *);

#endif
